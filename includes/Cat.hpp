/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akupriia <akupriia@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 22:52:35 by akupriia          #+#    #+#             */
/*   Updated: 2018/10/12 23:05:01 by akupriia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include <ACursesModule.hpp>

class Cat : public ACursesModule {

public:
	Cat( void );
	Cat( std::string, int );
	Cat( const Cat & );
	~Cat( void );

	Cat			&operator=( const Cat & );

	void		putInfo( void ) const;

private:
	std::vector<std::string>		_catskiy;

	void				catskiyInit( void );

};

#endif												// end of CAT_HPP
