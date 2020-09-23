/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Accessor.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbertola <cbertola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 18:33:59 by cbertola          #+#    #+#             */
/*   Updated: 2020/09/23 19:56:14 by cbertola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Accessor.hpp"

Accessor::Accessor(void){};
Accessor::~Accessor(void){};

std::string			Accessor::get_name(void) const{
	return (this->_name);
}

int			Accessor::set_name(std::string value) {
	this->_name = value;
	this->_ind = value.substr(0,3).compare("get") ? 0 : 1;
	if (this->_ind == 0)
    	this->_ind = value.substr(0,3).compare("set") ? 0 : 2;
	return 1;
}

std::string			Accessor::get_name_var(void) const{
	return (this->_name_var);
}

int			Accessor::set_name_var(std::string value) {
	this->_name_var = value;
	return 1;

}
std::string			Accessor::get_name_class(void) const{
	return (this->_name_class);
}

int			Accessor::set_name_class(std::string value) {
	this->_name_class = value;
	return 1;
}

std::string			Accessor::get_type(void) const{
	return (this->_type);
}

int			Accessor::set_type(std::string value) {
	int i;

	this->_type = value;
	i = (20 - value.length()) / 4;
	if ((20 - value.length()) % 4 > 0)
		i += 1;
	this->_tab = i;
	return 1;
}

std::string			Accessor::get_args(void) const{
	return (this->_args);
}

int			Accessor::set_args(std::string value) {
	this->_args = value;
	return 1;
}

int			Accessor::get_ind(void) const{
	return (this->_ind);
}

int			Accessor::get_tab(void) const{
	return (this->_tab);
}