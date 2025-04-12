#ifndef IOCONTROLS_H // Define guards per best practices.
#define IOCONTROLS_H
#pragma once

#include <map>
#include <string>
#include <iostream>
#include <sstream>
#include <stdexcept>

using namespace std;

/*
* The IOControls class handles user interaction via the console.
* It provides input validation and menu display functionality.
* This class receives a frequency map of produce items, and allows the user to
* interact with that data by selecting menu options or searching for item frequency.
*/

class IOControls {
public:

	// Displays the main menu and handles user selection based on map data.
	void displayMenu(const map<string, int>& mapData);

	// Templated function that validates numeric input from the user.
	// Only accepts values between 1 and 4. Uses a string prompt for input guidance.
	template<typename T>
	T GetValidatedInputInt(const string&);

	// Validates string input from the user and ensures the produce item exists in the provided map.
	string GetValidatedInputString(const string&, const map<string, int>& mapData);

	// Holds the current menu choice selected by the user.
	int menuChoice;

	// Holds the last produce item entered by the user for frequency lookup.
	string produceChoice;
};

/*
* Templated function definition that ensures the user enters a valid integer input.
* The input must be within a defined range (1-4), and blank or invalid inputs are rejected.
* Prompts are passed in as a string to customize the message shown to the user.
*/
template<typename T>
T IOControls::GetValidatedInputInt(const string& prompt) {
	T value;
	string input;
	bool valid;

	do {
		valid = true;
		cout << prompt;

		try {
			getline(cin, input); // Capture full line from user

			if (input.empty()) {
				throw runtime_error("Input cannot be blank. Please enter a value.");
			}

			stringstream ss(input);
			ss >> value;

			// Checks for non-numeric input, range violations, or leftover characters
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
