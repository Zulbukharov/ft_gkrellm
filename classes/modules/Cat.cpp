/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akupriia <akupriia@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 22:51:16 by akupriia          #+#    #+#             */
/*   Updated: 2018/10/12 23:04:51 by akupriia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Cat.hpp>

Cat::Cat( void ) : _catskiy()
{
	catskiyInit();
}
Cat::Cat( std::string a, int b ) : ACursesModule(a, b), _catskiy()
{
	catskiyInit();
}
Cat::Cat( const Cat &toCopy )
{
	*this = toCopy;
}
Cat::~Cat( void )
{
	return ;
}
Cat			&Cat::operator=( const Cat &toCopy )
{
	ACursesModule::operator=(toCopy);
	_catskiy = toCopy._catskiy;

	return *this;
}


void		Cat::catskiyInit( void )
{
	_catskiy.push_back("     ,     ,\n");
	_catskiy.push_back("     |\\.\"./|\n");
	_catskiy.push_back("    /       \\\n");
	_catskiy.push_back("   /  _   _  \\   ______\n");
	_catskiy.push_back("   \\==  Y  ==/\"'`      `.\n");
	_catskiy.push_back("   /`-._^_.-'\\     ,-  . \\\n");
	_catskiy.push_back("  /     `     \\   /     \\ \\\n");
	_catskiy.push_back("  \\  \\.___./  /_ _\\     / /\n");
	_catskiy.push_back("   `, \\   / ,'  (,-----' /\n");
	_catskiy.push_back("     \"\"' '\"\"     '------'");
	_catskiy.push_back("     ,     ,\n");
	_catskiy.push_back("     |\\.\"./|\n");
	_catskiy.push_back("    / _   _ \\\n");
	_catskiy.push_back("   / {|} {|} \\   ______\n");
	_catskiy.push_back("   \\==  Y  ==/\"'`      `.\n");
	_catskiy.push_back("   /`-._^_.-'\\     ,-  . \\\n");
	_catskiy.push_back("  /     `     \\   /     \\ \\\n");
	_catskiy.push_back("  \\  \\.___./  /_ _\\     / /\n");
	_catskiy.push_back("   `, \\   / ,'  (,-----' / \n");
	_catskiy.push_back("     \"\"' '\"\"     '------' ");
}
void		Cat::putInfo( void ) const
{
	int					y = _winStStr + 1;

	static const std::vector<std::string>::size_type	part = _catskiy.size() / 2;// 2 is number of frames
	static std::vector<std::string>::size_type			start = 0;
	static std::vector<std::string>::size_type			end = part;

	for (	std::vector<std::string>::size_type i = start;
			i < end;
			i++ )
	{	
		clearLine(y);
		mvwprintw(this->_w, y++, 1, "%s", _catskiy[i].c_str());
	}

	if ( end != _catskiy.size() ) {
		start += part;
		end += part;
	}
	else {
		start = 0;
		end = part;
	}

	this->refresh();
}
