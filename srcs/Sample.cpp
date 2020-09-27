/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sample.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbertola <cbertola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/24 10:09:23 by cbertola          #+#    #+#             */
/*   Updated: 2020/09/27 10:46:33 by cbertola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sample.hpp"

Sample::Sample() {}

Sample::Sample(Sample const & src) {
	*this = src;
}

Sample::~Sample() {}

Sample &		Sample::operator=( Sample const & rhs) {
	this->_id = rhs.get_id();

	return (*this);
}

int					get_id(void) {
	return (0);
}

std::ostream &		operator<<(std::ostream & o, Sample const & rhs )
{
	o << rhs.get_id();
	return o;
}