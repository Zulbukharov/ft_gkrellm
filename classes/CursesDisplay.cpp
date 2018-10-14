/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CursesDisplay.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akupriia <akupriia@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 22:52:22 by akupriia          #+#    #+#             */
/*   Updated: 2018/10/12 23:07:23 by akupriia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <CursesDisplay.hpp>

CursesDisplay::CursesDisplay( void ) : 
	_isName(true),
	_isOSinfo(true),
	_isTime(true),
	_isCPU(true),
	_isRAM(true),
	_isNetworkThro(true),
	_isNetworkInfo(true),
	_isCat(true),
	_modules(0),
	_nbColums(2)
{
	this->init();
}
CursesDisplay::CursesDisplay( const CursesDisplay &toCopy )
{
	*this = toCopy;
}
CursesDisplay::~CursesDisplay( void )
{
	this->deleteAll();
	endwin();

	system("reset; clear; echo '\t\t\t\t\t\tTWAS NICE TO SEE YOU!'");
}
CursesDisplay				&CursesDisplay::operator=( const CursesDisplay &toCopy )
{
	_isName = toCopy._isName;
	_isOSinfo = toCopy._isOSinfo;
	_isTime = toCopy._isTime;
	_isCPU = toCopy._isCPU;
	_isRAM = toCopy._isRAM;
	_isNetworkThro = toCopy._isNetworkThro;
	_isNetworkInfo = toCopy._isNetworkInfo;
	_isCat = toCopy._isCat;
	_modules = toCopy._modules;
	_nbColums = toCopy._nbColums;

	return *this;
}


void						CursesDisplay::init( void )
{
	initscr();
	keypad(stdscr, true);
	nodelay(stdscr, true);
	curs_set(false);
	clear();
	noecho();
	cbreak();

	start_color();
	init_pair(CAT1, COLOR_CYAN, COLOR_BLACK);
	init_pair(CAT2, COLOR_WHITE, COLOR_BLACK);
	init_pair(HEADING, COLOR_YELLOW, COLOR_BLACK);

	this->allocAll();
}
void						CursesDisplay::deleteAll( void )
{
	for ( ; _modules.size(); )
	{
		delete _modules.front();
		_modules.erase(_modules.begin());
	}
}
void						CursesDisplay::allocAll( void )
{
	if ( _isName )			_modules.push_back(new Name("1. User info", _nbColums));
	if ( _isOSinfo )		_modules.push_back(new OS("2. OS info", _nbColums));
	if ( _isTime )			_modules.push_back(new Time("3. Date info", _nbColums));
	if ( _isCPU )			_modules.push_back(new CPU("4. CPU info", _nbColums));
	if ( _isRAM )			_modules.push_back(new RAM("5. RAM info", _nbColums));
	if ( _isNetworkThro )	_modules.push_back(new NetworkThro("6. Network info", _nbColums));
	if ( _isNetworkInfo )	_modules.push_back(new NetworkInfo("7. Network interfaces", _nbColums));
	if ( _isCat )			_modules.push_back(new Cat("8. Zaz's pet", _nbColums));
}
void						CursesDisplay::reAllocAll( void )
{
	this->deleteAll();

	this->allocAll();

	clear();
}
void						CursesDisplay::refresh( void ) const
{
	for (	std::vector<int>::size_type i = 0;
			i < _modules.size();
			i++ )
	{
		_modules[i]->putInfo();
	}
}


void						CursesDisplay::run( void )
{
	time_t			t = time(NULL);
	int				c;

	while (true)
	{
		c = getch();
		if ( c == KEY_ONE )				this->switchName();
		else if ( c == KEY_TWO )		this->switchOSinfo();
		else if ( c == KEY_THREE )		this->switchTime();
		else if ( c == KEY_FOUR )		this->switchCPU();
		else if ( c == KEY_FIVE )		this->switchRAM();
		else if ( c == KEY_SIX )		this->switchNetworkThro();
		else if ( c == KEY_SEVEN )		this->switchNetworkInfo();
		else if ( c == KEY_EIGHT )		this->switchCat();

		else if ( c == COL_ONE )		this->switchCols(1);
		else if ( c == COL_TWO )		this->switchCols(2);
		else if ( c == COL_THREE )		this->switchCols(3);
		else if ( c == COL_FOUR )		this->switchCols(4);
		else if ( c == COL_FIVE )		this->switchCols(5);
		else if ( c == COL_SIX )		this->switchCols(6);
		else if ( c == COL_SEVEN )		this->switchCols(7);
		else if ( c == COL_EIGHT )		this->switchCols(8);
		else if ( c == COL_NINE )		this->switchCols(9);
		else if ( c == COL_TEN )		this->switchCols(10);

		else if ( c == EXIT_KEY1 || c == EXIT_KEY2 || c == EXIT_KEY3 )
			break ;

		if ( t != time(NULL) ) { // Refreshing happens one time per 1 second
			this->refresh();
			t = time(NULL);
		}
	}
}


																	/* Module switchers */
void						CursesDisplay::switchName( void )
{
	_isName = !_isName;
	this->reAllocAll();
}
void						CursesDisplay::switchOSinfo( void )
{
	_isOSinfo = !_isOSinfo;
	this->reAllocAll();
}
void						CursesDisplay::switchTime( void )
{
	_isTime = !_isTime;
	this->reAllocAll();
}
void						CursesDisplay::switchCPU( void )
{
	_isCPU = !_isCPU;
	this->reAllocAll();
}
void						CursesDisplay::switchRAM( void )
{
	_isRAM = !_isRAM;
	this->reAllocAll();
}
void						CursesDisplay::switchNetworkThro( void )
{
	_isNetworkThro = !_isNetworkThro;
	this->reAllocAll();
}
void						CursesDisplay::switchNetworkInfo( void )
{
	_isNetworkInfo = !_isNetworkInfo;
	this->reAllocAll();
}
void						CursesDisplay::switchCat( void )
{
	_isCat = !_isCat;
	this->reAllocAll();
}

void						CursesDisplay::switchCols( int nbColums )
{
	_nbColums = nbColums;
	this->reAllocAll();
}
