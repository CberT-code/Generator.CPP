/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sample.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbertola <cbertola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/24 10:09:23 by cbertola          #+#    #+#             */
/*   Updated: 2020/09/25 11:10:32 by cbertola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sample.hpp"

Sample::Sample() {}

Sample::Sample(Sample const & src) {
	*this = src;
}

Sample::~Sample() {}

int					get_value(void) {
	return (0);
}

std::ostream &		operator<<(std::ostream & o, Sample const & rhs )
{
	o << rhs.get_value();
	return o;
}