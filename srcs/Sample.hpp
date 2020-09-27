
#ifndef SAMPLE_H
#define SAMPLE_H

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

class Sample
{
	public:
		Sample(void);
		Sample(Sample const & src);
		~Sample(void);

		Sample &		operator=( Sample const & rhs);
		int					get_id(void) const;

	private:
		int				_id;
};

std::ostream &		operator<<(std::ostream & o, Sample const & rhs );

#endif