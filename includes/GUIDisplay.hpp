/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GUIDisplay.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azulbukh <azulbukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/13 22:49:42 by azulbukh          #+#    #+#             */
/*   Updated: 2018/10/14 09:14:17 by azulbukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GUIDISPLAY_HPP
# define GUIDISPLAY_HPP
#include <IMonitorDisplay.hpp>
#include <Name.hpp>
#include <OS.hpp>
#include <CPU.hpp>
#include <RAM.hpp>
#include <NetworkInfo.hpp>
#include <NetworkThro.hpp>
#include <Cat.hpp>

class	GUIDisplay : public IMonitorDisplay
{
	public:
		GUIDisplay(SDL_Window *window, SDL_Renderer *renderer);
		virtual ~GUIDisplay(void);
		GUIDisplay(GUIDisplay const &rhs);
		GUIDisplay &operator=(GUIDisplay const &rhs);
		void	run(void);
		static SDL_Window *_window;
		static SDL_Renderer *_renderer;
		static TTF_Font *_font;
		static SDL_Texture *_texture;
		static SDL_Texture *_frame;
	protected:
		bool		_isName;
		bool		_isOSinfo;
		bool		_isTime;
		bool		_isCPU;
		bool		_isRAM;
		bool		_isNetworkThro;
		bool		_isNetworkInfo;
		bool		_isCat;
		std::vector<IMonitorModule*>	_modules;
		int			_nbColums;
		
		virtual void					allocAll( void );
		virtual void					deleteAll( void );
		virtual void					reAllocAll( void );

		virtual void					switchTime( void );
		virtual void					switchName( void );
		virtual void					switchOSinfo( void );
		virtual void					switchCPU( void );
		virtual void					switchRAM( void );
		virtual void					switchNetworkThro( void );
		virtual void					switchNetworkInfo( void );
		virtual void					switchCat( void );
		virtual void					switchCols( int );

		virtual void					refresh( void ) const;
		virtual void					init( void );
	private:
		GUIDisplay(void);
};

#endif

