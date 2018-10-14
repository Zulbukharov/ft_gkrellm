/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CursesDisplay.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azulbukh <azulbukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 22:52:58 by akupriia          #+#    #+#             */
/*   Updated: 2018/10/14 02:17:36 by azulbukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURSESDISPLAY_HPP
#define CURSESDISPLAY_HPP

#include <IMonitorDisplay.hpp>
#include <Name.hpp>
#include <OS.hpp>
#include <Time.hpp>
#include <CPU.hpp>
#include <RAM.hpp>
#include <NetworkInfo.hpp>
#include <NetworkThro.hpp>
#include <Cat.hpp>

class CursesDisplay : public IMonitorDisplay {

public:
	CursesDisplay( void );
	CursesDisplay( const CursesDisplay & );
	virtual ~CursesDisplay( void );

	CursesDisplay			&operator=( const CursesDisplay & );

	void					run( void );

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
	int								_nbColums;

	virtual void					refresh( void ) const;
	virtual void					init( void );

	virtual void					allocAll( void );
	virtual void					deleteAll( void );
	virtual void					reAllocAll( void );

	/* Module switchers */
	virtual void					switchName( void );
	virtual void					switchOSinfo( void );
	virtual void					switchTime( void );
	virtual void					switchCPU( void );
	virtual void					switchRAM( void );
	virtual void					switchNetworkThro( void );
	virtual void					switchNetworkInfo( void );
	virtual void					switchCat( void );
	virtual void					switchCols( int );

};

#endif												// end of CURSESDISPLAY_HPP
