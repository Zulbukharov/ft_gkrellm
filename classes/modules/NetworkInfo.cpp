/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NetworkInfo.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azulbukh <azulbukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 22:51:50 by akupriia          #+#    #+#             */
/*   Updated: 2018/10/14 12:42:07 by azulbukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <NetworkInfo.hpp>

NetworkInfo::NetworkInfo( void )
{
	return ;
}
NetworkInfo::NetworkInfo( std::string a, int b ) : ACursesModule(a, b)
{
	return ;
}
NetworkInfo::NetworkInfo( std::string a, int b, int c ) : ACursesModule(a, b, c)
{
	return ;
}
NetworkInfo::NetworkInfo( const NetworkInfo &toCopy )
{
	*this = toCopy;
}
NetworkInfo::~NetworkInfo( void )
{
	return ;
}

NetworkInfo			&NetworkInfo::operator=( const NetworkInfo &toCopy )
{
	ACursesModule::operator=(toCopy);

	return *this;
}


void				NetworkInfo::putInfo( void ) const
{
	int									y = _winStStr;
	const std::string					interfaces = saveExec(\
	"cat other/sysinfo | grep -A 29 'Network:' | grep '\\w:$' | awk '{gsub(\"Network:\", \"\", $1); printf \"%s %s \", $1, $2}'");
	const std::string					types = saveExec("cat other/sysinfo | grep -A 29 'Network:' | grep 'Type: '");
	const std::string					bsd = saveExec("cat other/sysinfo | grep -A 29 'Network:' | grep 'BSD' | awk '{print $4}'");
	const std::vector<std::string>		Ivec = explode(interfaces, ':');
	const std::vector<std::string>		Tvec = explode(types, '\n');
	const std::vector<std::string>		Bvec = explode(bsd, '\n');


	const std::vector<std::string>::size_type	smallestSize = std::min( Ivec.size(), std::min(Tvec.size(), Bvec.size()) );

	for (	std::vector<std::string>::size_type i = 0;
			i < smallestSize;
			i++ )
	{
		mvwprintw(this->_w, y++, 1, "%d. %s:", i + 1, Ivec[i].c_str());
		mvwprintw(this->_w, y++, alignRight(Bvec[i]), "%s", Bvec[i].c_str());
		mvwprintw(this->_w, y++, 1, "   %s", Tvec[i].c_str());
		y++;
	}

	this->refresh();
}

void			NetworkInfo::putText(char const *s, int x, int y) const
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

void			NetworkInfo::putInfoSDL( void ) const
{
	const std::string					interfaces = saveExec(\
	"cat other/sysinfo | grep -A 29 'Network:' | grep '\\w:$' | awk '{gsub(\"Network:\", \"\", $1); printf \"%s %s \", $1, $2}'");
	const std::string					types = saveExec("cat other/sysinfo | grep -A 29 'Network:' | grep 'Type: '");
	const std::string					bsd = saveExec("cat other/sysinfo | grep -A 29 'Network:' | grep 'BSD' | awk '{print $4}'");
	const std::vector<std::string>		Ivec = explode(interfaces, ':');
	const std::vector<std::string>		Tvec = explode(types, '\n');
	const std::vector<std::string>		Bvec = explode(bsd, '\n');

	const std::vector<std::string>::size_type	smallestSize = std::min( Ivec.size(), std::min(Tvec.size(), Bvec.size()) );
	SDL_Rect rect = {0, _frame_y, WIN_X, __size_y_sdl * _nbColums + 30};
	SDL_RenderCopy(GUIDisplay::_renderer, GUIDisplay::_frame, NULL, &rect);
	int q = _y;
	for (	std::vector<std::string>::size_type i = 0;
			i < smallestSize;
			i++ )
	{
		putText((std::to_string(i + 1) + ". " + Ivec[i]).c_str(), _x, q + 5);
		putText(("    " + Bvec[i]).c_str(), _x, q + 25);
		putText(("    " + Tvec[i]).c_str(), _x, q + 45);
		q+= 60;
	}	

}
