/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ACursesModule.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azulbukh <azulbukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 22:51:09 by akupriia          #+#    #+#             */
/*   Updated: 2018/10/14 12:52:10 by azulbukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ACursesModule.hpp>

ACursesModule::ACursesModule( void ) :
	_motto(""),
	_nbColums(2)
{
	_mode = 0;
	init();
}
ACursesModule::ACursesModule( std::string &str, int nbColums ) :
	_motto(str),
	_nbColums(nbColums)
{
	_mode = 0;
	init();
}

ACursesModule::ACursesModule( std::string &str, int nbColums, int fuck)
{
	fuck = 0;
	_nbColums = nbColums;
	_motto = str;
	_mode = 1;
	initGUI();
}

ACursesModule::ACursesModule( const ACursesModule &toCopy )
{
	*this = toCopy;
}
ACursesModule::~ACursesModule( void )
{
	if (!_mode)
	{
		decInitYX();
		wborder(_w, ' ', ' ', ' ',' ',' ',' ',' ',' ');
		wrefresh(_w);
		delwin(_w);
	}
	else
	{
		initial_y = 35;
		initial_x = 40;
		frame_y = 0;
		frame_x = 0;
	}
}
ACursesModule				&ACursesModule::operator=( const ACursesModule &toCopy )
{
	_w = toCopy._w;
	_motto = toCopy._motto;
	_nbColums = toCopy._nbColums;
	_initial_y = toCopy._initial_y;
	_initial_x = toCopy._initial_x;

	return *this;
}


void			ACursesModule::init( void )
{
	static int			initial_y = 0;
	static int			initial_x = 0;

	_initial_y = &initial_y;
	_initial_x = &initial_x;
	_w = newwin(__size_y, __size_x, initial_y, initial_x);
	initial_x += __size_x;
	if ( initial_x == (__size_x * _nbColums) ) {
		initial_y += __size_y;
		initial_x = 0;
	}
	this->refresh();
}
void			ACursesModule::putInfo( void ) const
{
	return ;
}


void			ACursesModule::refresh( void ) const
{
	wattron( _w, COLOR_PAIR(HEADING) | A_BOLD );
	mvwprintw(this->_w, 1, alignCenter(_motto), "%s", _motto.c_str());
	wattroff( _w, COLOR_PAIR(HEADING) | A_BOLD );

	box(_w, 0, 0);

	wrefresh(_w);
}
int				ACursesModule::alignCenter( const std::string &str ) const
{
	const int		len = (__size_x - str.length()) / 2;

	if ( len > _borderThick ) {
		return len;
	}
	else {
		return _borderThick;
	}
}
int				ACursesModule::alignCenter( const int slen ) const
{
	const int		len = (__size_x - slen) / 2;

	if ( len > _borderThick ) {
		return len;
	}
	else {
		return _borderThick;
	}
}
int				ACursesModule::alignRight( const std::string &str ) const
{
	const int		len = __size_x - str.length() - _borderThick;

	if ( len > _borderThick ) {
		return len;
	}
	else {
		return _borderThick;
	}
}
int				ACursesModule::alignRight( const int slen ) const
{
	const int		len = __size_x - slen - _borderThick;

	if ( len > _borderThick ) {
		return len;
	}
	else {
		return _borderThick;
	}
}
void			ACursesModule::decInitYX( void )
{
	*_initial_y = 0;
	*_initial_x = 0;
}
void			ACursesModule::clearLine( int line ) const
{
	std::string		spaces( __size_x - (_borderThick * 2), ' ' );

	mvwprintw(this->_w, line, _borderThick, "%s", spaces.c_str());
}
void			ACursesModule::clearWindow( void ) const
{
	const int	bottom = __size_y - _borderThick;

	for ( int i = _borderThick; i < bottom; i++ ) {
		this->clearLine(i);
	}
}


															/* GETTERS */
WINDOW			*ACursesModule::getWin( void ) const
{
	return this->_w;
}

//GUI
// int				ACursesModule::getWinY(void) const
// {
// 	return (_winY);
// }

void			ACursesModule::initGUI( void )
{
	_y = ACursesModule::initial_y;
	_x = ACursesModule::initial_x;
	_frame_y = ACursesModule::frame_y;
	_frame_x = ACursesModule::frame_x;

	ACursesModule::initial_y += _nbColums * __size_y_sdl + 30;
	ACursesModule::frame_y +=  _nbColums * __size_y_sdl + 30;
}

void			ACursesModule::putInfoSDL( void ) const
{
	return ;
}

int			ACursesModule::initial_y = 35;
int			ACursesModule::initial_x = 40;
int			ACursesModule::frame_y = 0;
int			ACursesModule::frame_x = 0;