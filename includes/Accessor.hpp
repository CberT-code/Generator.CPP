/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Accessor.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbertola <cbertola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 16:01:14 by cbertola          #+#    #+#             */
/*   Updated: 2020/09/25 12:34:38 by cbertola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#ifndef Accessor_H
#define Accessor_H

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>

# define RESET   		"\033[0m"
# define BLACK   		"\033[30m"				/* Black */
# define RED     		"\033[31m"				/* Red */
# define GREEN   		"\033[32m"				/* Green */
# define YELLOW  		"\033[33m"				/* Yellow */
# define BLUE    		"\033[34m"				/* Blue */
# define MAGENTA 		"\033[35m"				/* Magenta */
# define CYAN    		"\033[36m"				/* Cyan */
# define WHITE   		"\033[37m"				/* White */
# define BOLDBLACK   	"\033[1m\033[30m"      /* Bold Black */
# define BOLDRED     	"\033[1m\033[31m"      /* Bold Red */
# define BOLDGREEN   	"\033[1m\033[32m"      /* Bold Green */
# define BOLDYELLOW  	"\033[1m\033[33m"      /* Bold Yellow */
# define BOLDBLUE    	"\033[1m\033[34m"      /* Bold Blue */
# define BOLDMAGENTA 	"\033[1m\033[35m"      /* Bold Magenta */
# define BOLDCYAN    	"\033[1m\033[36m"      /* Bold Cyan */
# define BOLDWHITE   	"\033[1m\033[37m"      /* Bold White */

class Accessor
{
	public:
		Accessor(void);
		~Accessor(void);

		std::string		get_name(void) const;
		int				set_name(std::string);
		std::string		get_name_var(void) const;
		int				set_name_var(std::string);
		std::string		get_name_class(void) const;
		int				set_name_class(std::string);
		std::string		get_type(void) const;
		int				set_type(std::string);
		std::string		get_args(void) const;
		int				set_args(std::string);
		int				get_ind(void) const;
		int				get_tab(void) const;

	private:
		std::string		_type;
		std::string		_name;
		std::string		_name_var;
		std::string		_name_class;
		std::string		_args;
		int				_ind;
		int				_tab;

};

int					ft_newHpp(std::string str);
int					ft_generator(std::string ret, std::ifstream	*ifs, std::ofstream	*ofs);

#endif
