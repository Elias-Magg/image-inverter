#ifndef _ARRAY
#define _ARRAY

#include <vector>
#include <iostream>

namespace math

{
	template <typename T>

	class Array {
	public:

	protected:
		std::vector<T> buffer;

		unsigned int height, width;

	public:

		const unsigned int getWidth() const { return width; }


		const unsigned int getHeight() const { return height; }


		T * getRawDataPtr();


		T getItem(unsigned int x, unsigned int y) const;


		void setItem(unsigned int x, unsigned int y, T & value);


		void setData(const T * & data_ptr);


		Array();


		Array(unsigned int width, unsigned int height);


		Array(unsigned int width, unsigned int height, const T * data_ptr);

		Array(const Array &src);


		~Array();


		Array & operator = (const Array & right);

		Array & operator ()(unsigned int x, unsigned int y);

	};
}
#endif