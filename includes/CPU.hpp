/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CPU.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azulbukh <azulbukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 22:52:51 by akupriia          #+#    #+#             */
/*   Updated: 2018/10/14 05:42:26 by azulbukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CPU_HPP
#define CPU_HPP

#include <GUIDisplay.hpp>
#include <ACursesModule.hpp>

class CPU : public ACursesModule {

public:
	CPU( std::string, int );
	CPU( std::string, int, int);
	CPU( const CPU & );
	~CPU( void );

	CPU				&operator=( const CPU & );

	virtual void	putInfo( void ) const;
	virtual void	putInfoSDL(void) const;
	virtual void	putText(char const *, int, int) const;

};

#endif												// end of CPU_HPP
