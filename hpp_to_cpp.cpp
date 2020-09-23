/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hpp_to_cpp.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbertola <cbertola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 14:57:46 by cbertola          #+#    #+#             */
/*   Updated: 2020/09/23 21:23:00 by cbertola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Accessor.hpp"

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
		*ofs << tmp  << "{\n\treturn (this->" << accessor->get_name_var() << ");\n}\n\n";
	}
	else if (accessor->get_ind() == 2){
		tmp = str.substr(str.find_first_of("(") + 1, str.find_first_of(")") - str.find_first_of("(") - 1);
		*ofs << tmp << " value) {\n\tthis->" << accessor->get_name_var() << " = value;\n\treturn 1;\n}\n\n";
	}
	else{
		tmp = str.substr(str.find_first_of("(") + 1, str.find_first_of(")") - str.find_first_of("(") - 1);
		*ofs << tmp << ") {}" << std::endl << '\t' ;
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

int			main(int argc, const char** argv) {
	
		
	std::string		name_class;
	std::string		line;
	std::ifstream	hpp;
	std::ofstream	ofs;
	std::string		str;
	

	if (argc != 2){
		std::cout << RED << "WRONG ARGUMENT" << std::endl;
		exit(0);
	}
	str = argv[1];
	if (str.substr(str.find('.'), str.length() - str.find('.')).compare(".hpp")){
		std::cout << RED << "The argument has to be an .hpp file" << std::endl;
		exit(0);
	}
	//If file already exist create file-new.cpp
	name_class = str.substr(0, str.find('.'));
	hpp.open(name_class + ".cpp");
	if (!hpp.fail())
		ofs.open(name_class + "-new.cpp");
	else
		ofs.open(name_class + ".cpp");
	hpp.close();
	hpp.open(str);
	if (hpp.fail()){
		std::cout << RED << "Can't open the file" << std::endl;
		exit(0);
	}

	//Incluse
	ofs << "#include \"" << name_class  << ".hpp\"\n\n";
	//Keep going until "public:"
	while (line.compare("public:")){
		getline(hpp, line);
		if (!line.empty())
			line = line.substr(line.find_first_not_of('\t'), line.length());
	}
	getline(hpp, line);
	getline(hpp, line);
	//Create Constructor and Destructor
	ofs << name_class << "::" << name_class << "() {}\n\n";
	ofs << name_class << "::~" << name_class << "() {}\n\n";
	//Until "private"
	while (getline(hpp, line)){
		if (!line.empty())
		{
			line = line.substr(line.find_first_not_of('\t'), line.length());
			if (line.compare("private:") == 0)
				break ;
			parsing(line, name_class, &ofs);
		}
	}
	return 0;
}