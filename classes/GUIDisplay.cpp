/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GUIDisplay.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azulbukh <azulbukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/13 22:49:23 by azulbukh          #+#    #+#             */
/*   Updated: 2018/10/14 12:53:28 by azulbukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "GUIDisplay.hpp"
#include <iostream>

GUIDisplay::GUIDisplay(SDL_Window *window, SDL_Renderer *renderer) :
	_isName(true),
	_isOSinfo(true),
	_isTime(true),
	_isCPU(true),
	_isRAM(true),
	_isNetworkThro(true),
	_isNetworkInfo(true),
	_isCat(true),
	_nbColums(2)
{
	GUIDisplay::_window = window;
	GUIDisplay::_renderer = renderer;
	if (!(GUIDisplay::_font = TTF_OpenFont("font.ttf", 24)))
		std::cout << TTF_GetError();
	if (!(GUIDisplay::_frame = IMG_LoadTexture(GUIDisplay::_renderer, "art.jpg")))
		std::cout << "Error";
	this->init();
}

GUIDisplay::~GUIDisplay(void)
{
	this->deleteAll();
	if (_renderer)
	{
		SDL_DestroyRenderer(_renderer);
	}
	if (_window)
	{
		SDL_DestroyWindow(_window);
	}
	TTF_Quit();
	SDL_Quit();
}

GUIDisplay::GUIDisplay(GUIDisplay const &rhs)
{
	*this = rhs;
}

GUIDisplay &GUIDisplay::operator=(GUIDisplay const &other)
{
	_isName = other._isName;
	_isOSinfo = other._isOSinfo;
	_isTime = other._isTime;
	_isCPU = other._isCPU;
	_isRAM = other._isRAM;
	_isNetworkThro = other._isNetworkThro;
	_isNetworkInfo = other._isNetworkInfo;
	_isCat = other._isCat;
	_modules = other._modules;
	_nbColums = other._nbColums;

	return *this;
}

void						GUIDisplay::allocAll( void )
{
	if ( _isName )			_modules.push_back(new Name("1. User info", 2, 1));
	if ( _isOSinfo )		_modules.push_back(new OS("2. OS info", 5, 1));
	if ( _isCPU )			_modules.push_back(new CPU("4. CPU info", 7, 1));
	if ( _isRAM )			_modules.push_back(new RAM("5. RAM info", 9, 1));
	if ( _isNetworkThro )	_modules.push_back(new NetworkThro("6. Network info", 8, 1));
	if ( _isNetworkInfo )	_modules.push_back(new NetworkInfo("7. Network interfaces", 9, 1));
	SDL_SetWindowSize(_window, WIN_X, ACursesModule::frame_y);
}

void						GUIDisplay::deleteAll( void )
{
	for ( ; _modules.size(); )
	{
		delete _modules.front();
		_modules.erase(_modules.begin());
	}
}

void						GUIDisplay::reAllocAll( void )
{
	this->deleteAll();
	this->allocAll();
	SDL_RenderClear(_renderer);
}

void						GUIDisplay::refresh( void ) const
{
	for (	std::vector<int>::size_type i = 0;
			i < _modules.size();
			i++ )
	{
		_modules[i]->putInfoSDL();
	}
}

void	GUIDisplay::run(void)
{
	SDL_bool		done = SDL_FALSE;
	SDL_Event		event;
	clock_t			t1, t2;

	t2 = clock() / 50000;
	while (!done)
	{
		t1 = clock() / 50000;
		if (t1 > t2)
		{
			SDL_SetRenderDrawColor(_renderer, 255, 255, 255, 255);
			SDL_RenderClear(_renderer);
			while (SDL_PollEvent(&event))
			{
				if (event.type == SDL_QUIT)
					done = SDL_TRUE;
				if(event.type == SDL_KEYDOWN)
				{
					if (event.key.keysym.sym == SDLK_1)
							this->switchName();
					if (event.key.keysym.sym == SDLK_2)
						this->switchOSinfo();
					if (event.key.keysym.sym == SDLK_3)
						this->switchCPU();
					if (event.key.keysym.sym == SDLK_4)
						this->switchRAM();
					if (event.key.keysym.sym == SDLK_5)
						this->switchNetworkThro();
					if (event.key.keysym.sym == SDLK_6)
						this->switchNetworkInfo();
					if (event.key.keysym.sym == SDLK_ESCAPE)
						done = SDL_TRUE;
				}
			}
			this->refresh();
			SDL_RenderPresent(_renderer);
			t2 = clock() / 50000;
		}
	}
}

void	GUIDisplay::init(void)
{
	this->allocAll();
	this->run();
}

void						GUIDisplay::switchName( void )
{
	_isName = !_isName;
	this->reAllocAll();
}
void						GUIDisplay::switchOSinfo( void )
{
	_isOSinfo = !_isOSinfo;
	this->reAllocAll();
}
void						GUIDisplay::switchTime( void )
{
	_isTime = !_isTime;
	this->reAllocAll();
}
void						GUIDisplay::switchCPU( void )
{
	_isCPU = !_isCPU;
	this->reAllocAll();
}
void						GUIDisplay::switchRAM( void )
{
	_isRAM = !_isRAM;
	this->reAllocAll();
}
void						GUIDisplay::switchNetworkThro( void )
{
	_isNetworkThro = !_isNetworkThro;
	this->reAllocAll();
}
void						GUIDisplay::switchNetworkInfo( void )
{
	_isNetworkInfo = !_isNetworkInfo;
	this->reAllocAll();
}
void						GUIDisplay::switchCat( void )
{
	_isCat = !_isCat;
	this->reAllocAll();
}

void						GUIDisplay::switchCols( int nbColums )
{
	_nbColums = nbColums;
	this->reAllocAll();
}

SDL_Window *GUIDisplay::_window = 0;
SDL_Renderer *GUIDisplay::_renderer = 0;
TTF_Font *GUIDisplay::_font = 0;
SDL_Texture *GUIDisplay::_texture = 0;
SDL_Texture *GUIDisplay::_frame = 0;