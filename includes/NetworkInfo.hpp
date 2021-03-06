/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NetworkInfo.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azulbukh <azulbukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 22:53:25 by akupriia          #+#    #+#             */
/*   Updated: 2018/10/14 07:13:34 by azulbukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NETWORKINFO_HPP
#define NETWORKINFO_HPP
#include <GUIDisplay.hpp>
#include <ACursesModule.hpp>

class NetworkInfo : public ACursesModule {

public:
	NetworkInfo( void );
	NetworkInfo( std::string, int );
	NetworkInfo( std::string, int, int);
	NetworkInfo( const NetworkInfo & );
	~NetworkInfo( void );

	NetworkInfo			&operator=( const NetworkInfo & );

	void				putInfo( void ) const;
	virtual void	putInfoSDL(void) const;
	virtual void	putText(char const *, int, int) const;

private:


};

#endif												// end of NETWORKINFO_HPP
