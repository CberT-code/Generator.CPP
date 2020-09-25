/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_newHpp.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbertola <cbertola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/24 20:50:09 by cbertola          #+#    #+#             */
/*   Updated: 2020/09/25 14:55:44 by cbertola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../includes/Accessor.hpp"

int					check_error(std::ifstream		*ifs, std::string str){
	if (ifs->fail()){
		std::cout << RED << "Can't open the file Sample.hpp, please check the \
		folder Generator is at : ~/Generator" << std::endl;
		return (0);
	}
	if (str.empty()){
		std::cout << RED << "argument to replace can't be empty!" << std::endl;
		ifs->close();
	}
	return (1);
}

std::string			replace(std::string line, std::string str, std::string str2)
{
	size_t found;
	found = -1;

	while ((found = line.find(str, found + 1)) != std::string::npos )
		line.replace(found, str.length(), str2);
	return (line);
}

void				init_replace(std::ifstream		*ifs, std::string str)
{
	std::ofstream		ofs(str + ".hpp");
	std::string			line;
	std::string			strup = str;

	//Format strup
	for(unsigned j = 0; j < strup.length(); ++j) {
		strup.at(j) = std::toupper(strup.at(j));
	}
	//Replace
	while (getline(*ifs, line))
	{
		line = replace(line, "Sample", str);
		line = replace(line, "SAMPLE", strup);
		ofs << line << std::endl;
	}
}

int					ft_newHpp(std::string str) {
	std::ifstream		ifs("./srcs/Sample.hpp");

	if (!check_error(&ifs, str))
		return (0);
	init_replace(&ifs, str);
	return 0;
}
