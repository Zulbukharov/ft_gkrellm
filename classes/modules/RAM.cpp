/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RAM.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azulbukh <azulbukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 22:52:11 by akupriia          #+#    #+#             */
/*   Updated: 2018/10/14 12:41:07 by azulbukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <RAM.hpp>

RAM::RAM( void )
{
	return ;
}
RAM::RAM( std::string a, int b ) : ACursesModule(a, b)
{
	return ;
}
RAM::RAM( std::string a, int b , int c) : ACursesModule(a, b, c)
{
	return ;
}
RAM::RAM( const RAM &toCopy )
{
	*this = toCopy;
}
RAM::~RAM( void )
{
	return ;
}

RAM			&RAM::operator=( const RAM &toCopy )
{
	ACursesModule::operator=(toCopy);

	return *this;
}


void		RAM::putInfo( void ) const
{
	int					y = _winStStr;
	const std::string	memCap = saveExec("cat other/sysinfo | grep 'Memory: \\d* ' | sed -e 's/^ *//'");
	const std::string	upgradeable = saveExec("cat other/sysinfo | grep 'Upgradeable Memory:' | sed 's/^ *//'");
	const std::string	banks = saveExec("cat other/sysinfo | grep -A 40 'Upgradeable Memory:' | grep 'BANK' | wc -l | sed 's/^ *//'");
	const std::string	types = saveExec("cat other/sysinfo | grep -A 40 'Upgradeable Memory:' | awk '/Type:/  {printf \"%s \", $2;}'");
	const std::string	sizes = saveExec("cat other/sysinfo | grep -A 40 'Upgradeable Memory:' | awk '/Size:/  {printf \"%s \", $2$3;}'");
	const std::string	speed = saveExec("cat other/sysinfo | grep -A 40 'Upgradeable Memory:' | awk '/Speed:/  {printf \"%s \", $2$3;}'");

	mvwprintw(this->_w, y++, 1, "%s", memCap.c_str());
	mvwprintw(this->_w, y++, 1, "%s", upgradeable.c_str());
	mvwprintw(this->_w, y++, 1, "Memory slots: %s", banks.c_str());

	mvwprintw(this->_w, y++, alignCenter(13), "Slots' types:");
	mvwprintw(this->_w, y++, alignCenter(types), "%s", types.c_str());
	mvwprintw(this->_w, y++, alignCenter(13), "Slots' sizes:");
	mvwprintw(this->_w, y++, alignCenter(sizes), "%s", sizes.c_str());
	mvwprintw(this->_w, y++, alignCenter(13), "Slots' speed:");
	mvwprintw(this->_w, y++, alignCenter(speed), "%s", speed.c_str());

	this->refresh();
}

void			RAM::putText(char const *s, int x, int y) const
{
	if (!*s)
		return ;
	SDL_Color textColor = {0, 0, 0, 0 };
	SDL_Surface* textSurface = TTF_RenderText_Solid(GUIDisplay::_font, s, textColor);
	SDL_Texture* text = SDL_CreateTextureFromSurface(GUIDisplay::_renderer, textSurface);
	int text_width = textSurface->w;
	int text_height = textSurface->h;
	SDL_FreeSurface(textSurface);
	SDL_Rect renderQuad = {x, y, text_width, text_height};
	SDL_RenderCopy(GUIDisplay::_renderer, text, NULL, &renderQuad);
	SDL_DestroyTexture(text);
}

void			RAM::putInfoSDL( void ) const
{
	std::string	memCap = saveExec("cat other/sysinfo | grep 'Memory: \\d* ' | sed -e 's/^ *//'");
	std::string	upgradeable = saveExec("cat other/sysinfo | grep 'Upgradeable Memory:' | sed 's/^ *//'");
	std::string	banks = saveExec("cat other/sysinfo | grep -A 40 'Upgradeable Memory:' | grep 'BANK' | wc -l | sed 's/^ *//'");
	std::string	types = saveExec("cat other/sysinfo | grep -A 40 'Upgradeable Memory:' | awk '/Type:/  {printf \"%s \", $2;}'");
	std::string	sizes = saveExec("cat other/sysinfo | grep -A 40 'Upgradeable Memory:' | awk '/Size:/  {printf \"%s \", $2$3;}'");
	std::string	speed = saveExec("cat other/sysinfo | grep -A 40 'Upgradeable Memory:' | awk '/Speed:/  {printf \"%s \", $2$3;}'");

	SDL_Rect rect = {0, _frame_y, WIN_X, _nbColums * __size_y_sdl + 30};
	SDL_RenderCopy(GUIDisplay::_renderer, GUIDisplay::_frame, NULL, &rect);
	putText(memCap.c_str(), _x, _y + 5);
	putText(upgradeable.c_str(), _x, _y + 25);
	putText(("Memory slots: " + banks).c_str(), _x, _y + 45);
	putText("Slots' types:", _x, _y + 65);
	putText(("    " + types).c_str(), _x, _y + 85);
	putText("Slots' sizes:", _x, _y + 105);
	putText(("    " + sizes).c_str(), _x, _y + 125);
	putText("Slots' speed:", _x, _y + 145);
	putText(("    " + speed).c_str(), _x, _y + 165);
}
