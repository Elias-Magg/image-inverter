#include<iostream>
#include"Array.cpp"
#include"Image.cpp"
#include<vector>
#include "FilterGamma.cpp"
using namespace std;


int main(int argc, const char *argv[]) {
	if (argc = 0) {
		cerr << "no image data /n Terminating..." << endl;
		exit(EXIT_FAILURE);
	}
	Image img;
	bool state;
	state = img.load(argv[argc-1], "ppm");
	if (state) {
		cout << "data loaded successfuly" << endl;
	}
	for (int i = 0; i < argc-1; i++) {
		if (strcmp(argv[i], "-f")) {
			i++;
			if (strcmp(argv[i], "gamma")) {
				
			
			
			}
			else if (strcmp(argv[i], "linear")) {}
			else {
				cerr << "no filters applied /n Terminating..." << endl;
				exit(EXIT_FAILURE);
			}
		
		
		
		
		}
	
	
	
	}
	
	
	filtering::FilterGamma gamma(0.5f);
	img= gamma << img;
	filtering::FilterGamma gamma2(1.5f);
	std::cout << "works" << std::endl;
	img.save("neg.ppm", "ppm");
	system("pause");
	return 0;
	



};