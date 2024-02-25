#include <string>
#include <iostream>
#include "Color.h"
#include "Array.cpp"
#include "Image.cpp"
#include "FilterGamma.cpp"
#include "FilterLinear.cpp"

using namespace filtering;
using namespace imaging;


int main(int argc, const char *argv[]) {
	Image Img; 
	bool status = Img.load((std::string)argv[argc-1],"ppm");
	if (status) {
		std::cout << "Pixel data loaded from file successfuly" << std::endl;
	}
	
	for (int i = 0; i < argc; i++) {
		if ((string)argv[i] == "-f" && (string)argv[i + 1] == "gamma") {
			FilterGamma filter(stof(argv[i+2]));
			Image tmp = filter << Img;
			std::string newFileName = argv[argc - 1];
			newFileName.insert(argc - 1, "filtered_");
			status = tmp.save(newFileName, "ppm");
			i = +3;
		}
		/*else if ((string)argv[i] == "-f" && (string)argv[i + 1] == "linear") {
			FilterLinear filter(argv[i + 2], argv[i + 3], argv[i + 4]), (argv[i + 5], argv[i + 6], argv[i + 7]));
			Image tmp = filter << Img;
			std::string newFileName = argv[argc - 1];
			newFileName.insert(argc - 1, "filtered_");
			status = tmp.save(newFileName, "ppm");
			i = +6;
		}*/
		else if (((string)argv[i] == "-f" && (string)argv[i + 1] != "gamma") || ((string)argv[i] == "-f" && (string)argv[i + 1] != "linear")) {
			std::cout << "Please provide the correct input.";
		}

	}
	

	std::string newFileName = argv[argc-1];
	newFileName.insert(0, "filtered_");
	status = Img.save(newFileName,"ppm");
	if (status) {
		std::cout << "Pixel data saved to file successfuly" << std::endl;
	}
	system("pause");
	return 0;
}