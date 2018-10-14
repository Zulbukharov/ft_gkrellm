/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RAM.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azulbukh <azulbukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 22:53:45 by akupriia          #+#    #+#             */
/*   Updated: 2018/10/14 08:22:46 by azulbukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAM_HPP
#define RAM_HPP

#include <GUIDisplay.hpp>
#include <ACursesModule.hpp>

class RAM : public ACursesModule {

public:
	RAM( void );
	RAM( std::string, int );
	RAM( std::string, int, int );
	RAM( const RAM & );
	~RAM( void );

	RAM			&operator=( const RAM & );

	void		putInfo( void ) const;
	virtual void	putInfoSDL(void) const;
	virtual void	putText(char const *, int, int) const;

private:


};

#endif												// end of RAM_HPP
