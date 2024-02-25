#ifndef _IMAGE
#define _IMAGE
#include <iostream>
#include <string>
#include "Vec3.h"
#include "Image.h"
#include "Array.h"
#include "ppm.h"

using namespace std; 

namespace imaging
{
	class Image : public math::Array<math::Vec3<float>>
	{
	public:

	public:




		Image():Array() {}



		Image(unsigned int width, unsigned int height):Array(width, height) {}


		Image(unsigned int width, unsigned int height, const math::Vec3<float> * data_ptr):Array(width, height, data_ptr) {}

		Image(const Image &src):Array(src){}


		bool load(const std::string & filename, const std::string & format) {
			if (strcmp(filename.substr(filename.size() - 3).c_str(),format.c_str())!=0 || strcmp(format.c_str(),"ppm")!=0) {
				return false;
			}
			int h;
			int w;
			float * rawData;
			rawData	= imaging::ReadPPM(filename.c_str(), &w, &h);
			this->height = h;
			this->width = w;	
			std::vector<math::Vec3<float>> Data;
			int rawDataIndex = 0;
			for (int i = 0; i < h*w; i++) {
				math::Vec3<float> pixel(rawData[rawDataIndex], rawData[rawDataIndex + 1], rawData[rawDataIndex + 2]);
				Data.push_back(pixel);
				rawDataIndex += 3;
			}
			buffer = Data;
			return true;
		}



		bool save(const std::string & filename, const std::string & format) {
			if(strcmp(filename.substr(filename.size() - 3).c_str(), format.c_str()) != 0 || strcmp(format.c_str(), "ppm") != 0) {
				return false;
			}
			float *rawData=new float[(this->height*this->width)*3];
			int rawDataIndex = 0;
			for (unsigned int i = 0; i < this->height*this->width; i++) {
				rawData[rawDataIndex] = (float)this->buffer[i].r;
				rawDataIndex++;
				rawData[rawDataIndex] = (float)this->buffer[i].g;
				rawDataIndex++;
				rawData[rawDataIndex] = (float)this->buffer[i].b;
				rawDataIndex++;

			}
			return imaging::WritePPM(rawData, this->width, this->height, filename.c_str());

		}
	};
}


#endif