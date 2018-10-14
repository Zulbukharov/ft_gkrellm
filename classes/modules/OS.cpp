/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OS.cpp                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azulbukh <azulbukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 22:52:04 by akupriia          #+#    #+#             */
/*   Updated: 2018/10/14 12:41:26 by azulbukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <OS.hpp>

OS::OS( void )
{
	return ;
}
OS::OS( std::string a, int b ) : ACursesModule(a, b)
{
	return ;
}
OS::OS( std::string a, int b, int c ) : ACursesModule(a, b, c)
{
	return ;
}
OS::OS( const OS &toCopy )
{
	*this = toCopy;
}
OS::~OS( void )
{
	return ;
}

OS			&OS::operator=( const OS &toCopy )
{
	ACursesModule::operator=(toCopy);

	return *this;
}


void			OS::putInfo(void) const
{
	int					y = _winStStr;
	const std::string	kernel = saveExec("uname -v");
	const std::string	hardware = saveExec("uname -m");
	const std::string	genInfo = saveExec("sw_vers | sed -e 's/Ver/ ver/' -e 's/Name/ name/' -e 's/\t/ /'");
	std::size_t			spos;
	std::size_t			epos;

	mvwprintw(this->_w, y++, 1, "%s", kernel.substr(0, kernel.find(": ")).c_str());
	mvwprintw(this->_w, y++, 1, "Platform: %s", hardware.c_str());
	epos = genInfo.find('\n');
	mvwprintw(this->_w, y++, 1, "%s", genInfo.substr(0, epos).c_str());
	spos = epos + 1;
	epos = genInfo.find('\n', spos);
	mvwprintw(this->_w, y++, 1, "%s", genInfo.substr(spos, epos).c_str());
	spos = epos + 1;
	epos = genInfo.find('\n', spos);
	mvwprintw(this->_w, y++, 1, "%s", genInfo.substr(spos, epos).c_str());

	this->refresh();
}

void			OS::putText(char const *s, int x, int y) const
{
	SDL_Color textColor = { 0, 0, 0, 0 };
	SDL_Surface* textSurface = TTF_RenderText_Solid(GUIDisplay::_font, s, textColor);
	SDL_Texture* text = SDL_CreateTextureFromSurface(GUIDisplay::_renderer, textSurface);
	int text_width = textSurface->w;
	int text_height = textSurface->h;
	SDL_FreeSurface(textSurface);
	SDL_Rect renderQuad = {x, y, text_width, text_height};
	SDL_RenderCopy(GUIDisplay::_renderer, text, NULL, &renderQuad);
	SDL_DestroyTexture(text);
}

void			OS::putInfoSDL(void) const
{
	const std::string	kernel = saveExec("uname -v");
	const std::string	hardware = saveExec("uname -m");
	const std::string	genInfo = saveExec("sw_vers | sed -e 's/Ver/ ver/' -e 's/Name/ name/' -e 's/\t/ /'");
	std::size_t			spos;
	std::size_t			epos;

	SDL_Rect rect = {0, _frame_y, WIN_X, _nbColums * __size_y_sdl + 30};
	SDL_RenderCopy(GUIDisplay::_renderer, GUIDisplay::_frame, NULL, &rect);

	putText(kernel.substr(0, kernel.find(": ")).c_str(), _x, _y + 5);
	putText(("Platform: " + hardware).c_str(), _x, _y + 25);
	epos = genInfo.find('\n');
	putText(genInfo.substr(0, epos).c_str(), _x, _y + 45);
	spos = epos + 1;
	epos = genInfo.find('\n', spos);
	putText(genInfo.substr(spos, epos).c_str(), _x, _y + 65);
	spos = epos + 1;
	epos = genInfo.find('\n', spos);
	putText(genInfo.substr(spos, epos).c_str(), _x, _y + 85);
}