/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Time.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azulbukh <azulbukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 22:52:16 by akupriia          #+#    #+#             */
/*   Updated: 2018/10/14 08:46:25 by azulbukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Time.hpp>

Time::Time( void )
{
	return ;
}
Time::Time( std::string a, int b ) : ACursesModule(a, b)
{
	return ;
}
Time::Time( const Time &toCopy )
{
	*this = toCopy;
}
Time::~Time( void )
{
	return ;
}

Time			&Time::operator=( const Time &toCopy )
{
	ACursesModule::operator=(toCopy);

	return *this;
}


void			Time::putInfo( void ) const
{
	time_t	rawtime;
	struct	tm* timeinfo;
	char 	buffer[26];

	time (&rawtime);
	timeinfo = localtime (&rawtime);
	strftime (buffer, 26, "%c", timeinfo);
	mvwprintw(this->_w, _winStStr + 4, alignCenter(buffer), " %s", buffer);
	this->refresh();
}