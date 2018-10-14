/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Name.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azulbukh <azulbukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 22:53:19 by akupriia          #+#    #+#             */
/*   Updated: 2018/10/14 05:25:17 by azulbukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NAME_HPP
#define NAME_HPP

#include <GUIDisplay.hpp>
#include <ACursesModule.hpp>

class Name : public ACursesModule {

public:
	Name( void );
	Name( std::string, int);
	Name( std::string, int, int);
	Name( const Name & );
	~Name( void );

	Name			&operator=( const Name & );

	virtual void			putInfo( void ) const;
	virtual void			putInfoSDL(void) const;
	virtual void			putText(char *, int, int) const;

private:


};

#endif												// end of NAME_HPP
