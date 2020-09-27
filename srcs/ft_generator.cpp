/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_generator.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbertola <cbertola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/25 12:23:52 by cbertola          #+#    #+#             */
/*   Updated: 2020/09/27 10:47:05 by cbertola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Accessor.hpp"

void		display(Accessor *accessor, std::string str, std::ofstream	*ofs)
{
	std::string			tmp;
	int 				i = -1;

	//display type
	*ofs << accessor->get_type();
	//display tabs
	while (++i < accessor->get_tab())
		*ofs << '\t';
	//display nameClass::name(
	*ofs << accessor->get_name_class() << "::" << accessor->get_name() << '(';
	//display args) { function }
	if (accessor->get_ind() == 1){
		tmp = str.substr(str.find_first_of("(") + 1, str.length() - str.find_first_of("(") - 2);
		*ofs << tmp  << "{\nreturn (this->" << accessor->get_name_var() << ");\n}\n\n";
	}
	else if (accessor->get_ind() == 2){
		tmp = str.substr(str.find_first_of("(") + 1, str.find_first_of(")") - str.find_first_of("(") - 1);
		*ofs << tmp << " value) {\nthis->" << accessor->get_name_var() << " = value;\n\treturn 1;\n}\n\n";
	}
	else{
		tmp = str.substr(str.find_first_of("(") + 1, str.find_first_of(")") - str.find_first_of("(") - 1);
		*ofs << tmp << ") {}" << std::endl ;
	}
	return ;
}

void		parsing(std::string str, std::string name_class, std::ofstream	*ofs)
{
	std::string 	tmp;
	Accessor		accessor;

	//Set class name
	accessor.set_name_class(name_class);
    //Set function type
    accessor.set_type(str.substr(0, str.find_first_of('\t')));
    //Get function name
   	accessor.set_name(str.substr(str.find_last_of('\t') + 1, str.find_first_of("(") - str.find_last_of('\t') - 1));
	tmp = accessor.get_name();
    //Get name of variable
   	accessor.set_name_var(tmp.substr(3, tmp.length()));
	//Get argument
	accessor.set_args(str.substr(str.find_first_of("(") + 1, str.find_first_of(")") - str.find_first_of("(") - 1));
	//Display all
	display(&accessor, str, ofs);
}

int			ft_generator(std::string ret, std::ifstream	*ifs, std::ofstream	*ofs) {
	std::string		line;
	
	//Incluse
	*ofs << "#include \"" << ret  << ".hpp\"\n\n";
	//Keep going until "public:"
	while (line.compare("\tpublic:")) {
		getline(*ifs, line);
	}
	getline(*ifs, line);
	getline(*ifs, line);
	getline(*ifs, line);
	// //Create Constructor and Destructor
	*ofs << ret << "::" << ret << "() {}\n\n";
	*ofs << ret << "::" << ret << "(" << ret << " const & src) {\n\t*this = src;\n}\n\n";
	*ofs << ret << "::~" << ret << "() {}\n\n";
	//Until "private"
	while (line.compare("\tprivate:")){
		getline(*ifs, line);
		if (!line.empty())
			parsing(line, ret, ofs);
	}
	return 0;
}