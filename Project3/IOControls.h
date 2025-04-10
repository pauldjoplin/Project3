#ifndef IOCONTROLS_H //Define guards per best practices.
#define IOCONTROLS_H

#include <map>
#include <string>
#include <iostream>
#include <sstream>
#include <stdexcept>

using namespace std;



class IOControls
{
public:

	void displayMenu(const map<string, int>& mapData);

	template<typename T>
	T GetValidatedInput(const string&);

	int menuChoice;
	string produceChoice;

};

template<typename T>
T IOControls::GetValidatedInput(const string&) {
	T value;
	string input;

	bool valid;

	do {
		valid = true;

		try {
			getline(cin, input);

			if (input.empty()) {
				throw runtime_error("Input cannot be blank. Please enter a value.");
			}

			stringstream ss(input);
			ss >> value;

			if (ss.fail() || value <= 0 || value > 4 || !ss.eof()) {
				throw runtime_error("Invalid input, please enter (1-4).");
			}
			
		}
		catch (const runtime_error& e) {
			cerr << "Error: " << e.what() << endl; 
			valid = false;
		}
	} while (!valid);

	return value;
}

#endif
