/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ACursesModule.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azulbukh <azulbukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 22:52:28 by akupriia          #+#    #+#             */
/*   Updated: 2018/10/14 12:52:13 by azulbukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ACURSESMODULE_HPP
#define ACURSESMODULE_HPP

#include <IMonitorModule.hpp>

class ACursesModule : public virtual IMonitorModule {

public:
	ACursesModule( void );
	ACursesModule( std::string &, int );
	ACursesModule( std::string &, int, int); // SDL[GUI]
	ACursesModule( const ACursesModule & );
	virtual ~ACursesModule( void );

	ACursesModule			&operator=( const ACursesModule & );

	void					refresh( void ) const;
	virtual void			putInfo( void ) const;
	virtual void			putInfoSDL( void ) const;
	static int				initial_x;
	static int				frame_y;
	static int				frame_x;
	/* GETTERS */
	WINDOW					*getWin( void ) const;

	// int						getWinY(void) const;
protected:
	WINDOW				*_w;
	std::string			_motto;
	int					_nbColums;
	int					*_initial_y;
	int					*_initial_x;
	static const int	_borderThick = 1;
	static const int	_winStStr = 3;
	static const int	__size_y = 20;
	static const int	__size_x = 30;

	void				init( void );
	void				decInitYX( void );

	int					alignCenter( const std::string & ) const;
	int					alignCenter( const int ) const;
	int					alignRight( const std::string &str ) const;
	int					alignRight( const int slen ) const;

	void				clearLine( int ) const;
	void				clearWindow( void ) const;


	//GUI
	void				initGUI(void);
	int					_frame_x;
	int					_frame_y;
	int					_x;
	int					_y;
	static const int	__size_y_sdl = 30;
	int 				_mode;
	static int			initial_y;
	// int					_winY;
	

};

#endif												// end of ACURSESMODULE_HPP
