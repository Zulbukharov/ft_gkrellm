/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Time.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azulbukh <azulbukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 22:53:50 by akupriia          #+#    #+#             */
/*   Updated: 2018/10/14 08:46:18 by azulbukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TIME_HPP
#define TIME_HPP
#include <GUIDisplay.hpp>
#include <ACursesModule.hpp>

class Time : public ACursesModule {

public:
	Time( void );
	Time( std::string, int );
	Time( const Time & );
	~Time( void );

	Time			&operator=( const Time & );

	void			putInfo( void ) const;
private:


};

#endif
