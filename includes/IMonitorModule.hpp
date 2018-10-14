/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMonitorModule.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azulbukh <azulbukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 22:53:08 by akupriia          #+#    #+#             */
/*   Updated: 2018/10/14 11:00:37 by azulbukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <main.hpp>
#ifndef IMONITORMODULE_HPP
#define IMONITORMODULE_HPP

class IMonitorModule {

public:
	virtual ~IMonitorModule( void ) { return ; };

	virtual void			putInfo( void ) const = 0;
	virtual void			putInfoSDL( void ) const = 0;
protected:

};

#endif												// end of IMONITORMODULE_HPP
