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


		T * getRawDataPtr() {
			return Array::buffer;
		}


		T getItem(unsigned int x, unsigned int y) const {
			T item;
			if (x <= width && y <= height) {
				item = buffer[y*width + x];
			}
			else {
				std::cout << "out of bounds" << std::endl;
				return NULL;
			}
			return item;



		}


		void setItem(unsigned int x, unsigned int y, T & value) {

			if (x <= width && y <= height) {
				buffer[y*width + x] = value;
			}
			else {
				std::cout << "out of bounds" << std::endl;
			}

		}


		void setData(const T * & data_ptr) {
			if (width == 0 || height == 0 || buffer != nullptr) return;
			else {
				for (int i = 0; i < sizeof(data_ptr) / sizeof(data_ptr[0]); i++) {
					buffer[i] = data_ptr[i];
				}
			}
		}

		Array() {
			width = 0;
			height = 0;
		}


		Array(unsigned int width, unsigned int height):height(height),width(width){
			
		}


		Array(unsigned int width, unsigned int height, const T * data_ptr) {
			this->height = height;
			this->width = width;
			for (unsigned int i = 0; i < width*height; i++) {
				buffer.push_back(data_ptr[i]);
			}

		}

		Array(const Array &src) {
			width = src.getWidth();
			height = src.getHeight();

			unsigned int size = height * width;

			for (unsigned int i = 0; i < size; i++) {
				buffer.push_back(src.buffer[i]);
			}
		}


		~Array() {
			buffer.clear();
		}


		Array & operator = (const Array & right) {
			if (&right == this)return *this;
			if (!buffer.empty()) { buffer.clear();}
			width = right.getWidth();
			height = right.getHeight();
			for (unsigned int i = 0; i < width*height; i++) {
				buffer.push_back(right.buffer[i]);
			}
			return *this;
		}

		Array & operator ()(unsigned int x, unsigned int y) {
			return this->getItem(x, y);
		}

	};
}

#endif