#include <fstream>
#include <iostream>
#include <sstream>
#include "ppm.h"
using namespace std; 

namespace imaging {

	float * ReadPPM(const char * filename, int * w, int * h) {
		ifstream infile(filename, ios_base::binary);		//opening file
		char word[10];
		if (infile.is_open()) {		//test to see if file was loaded properly
			cout << "File load successful" << endl;
		}
		else {
			cerr << "Failure to open file" << endl;
			return nullptr;
		}
		infile >> word;
		if (strcmp(word, "P6") != 0) {		//header must start with "P6"
			cout << "ppm file not P6 type" << endl;
			return nullptr;
		}
		for (int i = 0; i < 2; i++) {
			infile >> word;
			if (strcmp(word, "P6") == 0 && i == 0) {			//check if width and height values exist
				cout << "Height and Width values missing from header";
				return nullptr;
			}
			if (strcmp(word, "P6") == 0 && i == 1) {		//check if width and height values exist	
				cout << "Height or Width values missing from header";
				return nullptr;

			}
			if (i == 0) {
				*w = atoi(word);
			}
			if (i == 1) {
				*h = atoi(word);
			}
		}
		if (w == nullptr || h == nullptr) {
			return nullptr;
		}

		infile >> word;
		if (strcmp(word, "255") != 0) {		//check if maximum pixel value exists and that it is equal to 255 
			cout << "Illegal maximum pixel value" << endl;
			return nullptr;
		}
		infile.seekg(1, ios_base::cur);
		unsigned int byte = 0;
		const int size = (*h)*(*w)*3;
		float *pixelData = new float[size];
		for (int i = 0; i < size; i++) {
			infile.read((char *)&byte, 1);
			pixelData[i] = float(byte)/ 255;
		}
		infile.close();
		return pixelData;
	}

	bool WritePPM(const float * data, int w, int h, const char * filename) {
		ofstream outfile(filename, ios_base::binary);
		if (outfile.is_open()) {		//cheking if file can be opened proeprly
			cout << "File load successful" << endl;
		}
		else {
			cerr << "Failure to open file" << endl;
			return false;
		}
		string header = "P6\n";		//Writing the header
		stringstream s;
		s << w;
		header += s.str() + " ";
		s.str(string());
		s << h;
		header += s.str() + "\n255\n";
		outfile.write(header.c_str(), header.size());
		for (int i = 0; i < w*h*3;i++) {		//Writing the pixel values
			outfile.put(data[i] * 255);
		}
		outfile.flush();
		outfile.close();
		return true;
		}
}