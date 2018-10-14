/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NetworkThro.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azulbukh <azulbukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 22:53:33 by akupriia          #+#    #+#             */
/*   Updated: 2018/10/14 08:49:23 by azulbukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NETWORKTHRO_HPP
#define NETWORKTHRO_HPP
#include <GUIDisplay.hpp>
#include <ACursesModule.hpp>

class NetworkThro : public ACursesModule {

public:
	NetworkThro( void );
	NetworkThro( std::string, int );
	NetworkThro( std::string, int , int);
	NetworkThro( const NetworkThro & );
	~NetworkThro( void );

	NetworkThro		&operator=( const NetworkThro & );

	void			putInfo( void ) const;
	virtual void	putInfoSDL(void) const;
	virtual void	putText(char const *, int, int) const;

private:


};

#endif												// end of NETWORKTHRO_HPP
