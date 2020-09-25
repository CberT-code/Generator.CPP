/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbertola <cbertola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 14:57:46 by cbertola          #+#    #+#             */
/*   Updated: 2020/09/25 14:50:08 by cbertola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Accessor.hpp"

std::string			check_error(int argc, const char** argv, std::ifstream	*ifs, std::ofstream	*ofs){

	std::string		str = argv[1];
	
	if (str.compare("new") && argc != 3){
		if (argc != 2){
			std::cout << RED << "WRONG ARGUMENT" << std::endl;
			return NULL;
		}
		//Check if file is .hpp
		if (str.substr(str.find('.'), str.length() - str.find('.')).compare(".hpp")){
			std::cout << RED << "The argument has to be an .hpp file" << std::endl;
			return NULL;
		}
		//Try to open the file
		ifs->open(str);
		if (ifs->fail()){
			std::cout << RED << "Can't open the file" << std::endl;
			return NULL;
		}
		//If file already exist create file-new.cpp
		ifs->open(str + ".cpp");
		if (!ifs->fail())
			ofs->open(str + "-new.cpp");
		else
			ofs->open(str + "t.cpp");
		str = str.substr(0, str.find('.'));
	}
	return str;	
}

int			main(int argc, const char** argv) {
	std::string		ret;
	std::ifstream	ifs;
	std::ofstream	ofs;
	
	ret = check_error(argc, argv, &ifs, &ofs) ;
	if (ret.empty())
		return 0;
	if (argc == 3)
	{
		std::string		str(argv[2]);
		return (ft_newHpp(str));
	}
	else
		ft_generator(ret, &ifs, &ofs);
	return (0);
}



