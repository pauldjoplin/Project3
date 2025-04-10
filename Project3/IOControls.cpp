#include "IOControls.h"

#include <iostream>

void IOControls::displayMenu(const map<string, int>& mapData) {
	
	cout << "File uploaded..backup created...choose a menu option to continue.\n";

	cout << "1: Check the frequency of a product via word search.\n" <<
		"2: Print a list of items and their purchase frequency.\n" <<
		"3: Print a histogram of items and their purchase frequency.\n" <<
		"4: Exit the program.\n"
		"Enter the menu option (1-4): ";
	
	do {
		menuChoice = (GetValidatedInput<int>(""));

	} while (menuChoice != 4);
}

