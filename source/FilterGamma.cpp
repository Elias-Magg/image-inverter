#include "Filter.h"
#include <string>
#include <iostream>
#include "Color.h"
#include "ppm.h"
#include "Image.cpp"
#include "Vec3.h"
#include <math.h> 

using namespace imaging;
namespace filtering {
	class FilterGamma {

	public: float y;

		FilterGamma() {}	//default constructor

		FilterGamma(float y) {
			this->y = y;
		}

		FilterGamma(const FilterGamma &oldfilter) {  //copy constructor
			y = oldfilter.y;
		}

		virtual Image operator << (const Image & image) {			//overriding the << operator
			Image newImg = image;
			for (unsigned int h = 0; h < image.getHeight(); h++) {
				for (unsigned int w = 0; w < image.getWidth(); w++) {
					math::Vec3<float> pixel = image.getItem(w, h);
					pixel.r = pow(pixel.r, y);
					pixel.g = pow(pixel.g, y);
					pixel.b = pow(pixel.b, y);
					newImg.setItem(w, h, pixel);
				}
			}
			return newImg;


		}
	};

}



