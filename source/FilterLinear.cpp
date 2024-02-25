#include "Filter.h"
#include <string>
#include <iostream>
#include "Color.h"
#include "ppm.h"
#include "Image.cpp"
#include "Vec3.h"

using namespace imaging;
namespace filtering {
	class FilterLinear {

		public: 
		
		math::Vec3<float> a, c;

		FilterLinear() {}		//default constructor


		FilterLinear(math::Vec3<float> a, math::Vec3<float> c) {
			this->a = a;
			this->c = c;
		}


		FilterLinear(const FilterLinear &oldfilter) {		//copy constructor
			a = oldfilter.a;
			c = oldfilter.c;

		}

		virtual Image operator << (const Image & image) {			//overriding the << operator
			Image newImg = image;
			for (unsigned int h = 0; h < image.getHeight(); h++) {
				for (unsigned int w = 0; w < image.getWidth(); w++) {
					math::Vec3<float> pixel = image.getItem(w, h);
					pixel = a * pixel + c;		//using the component-wise vector multiplication operator *
					newImg.setItem(w, h, pixel);
				}
			}
			return newImg;
		}
	};
}
