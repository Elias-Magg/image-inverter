#ifndef FILTER_H
#define FILTER_H

#include "Image.cpp"

using namespace imaging;
namespace filtering {
	class Filter {
	public:

		virtual Image operator << (const Image & image) = 0;

		Filter();		//default constructor

		Filter(const Filter &oldfilter);		//copy constructor
	};
}


#endif