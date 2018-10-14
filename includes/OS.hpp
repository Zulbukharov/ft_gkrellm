/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OS.hpp                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azulbukh <azulbukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 22:53:40 by akupriia          #+#    #+#             */
/*   Updated: 2018/10/14 07:59:51 by azulbukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OS_HPP
#define OS_HPP
#include <GUIDisplay.hpp>
#include <ACursesModule.hpp>

class OS : public ACursesModule {

public:
	OS( void );
	OS( std::string, int );
	OS( std::string, int, int);
	OS( const OS & );
	~OS( void );

	OS			&operator=( const OS & );

	void			putInfo( void ) const;
	virtual void	putInfoSDL(void) const;
	virtual void	putText(char const *, int, int) const;


private:


};

#endif												// end of OS_HPP
