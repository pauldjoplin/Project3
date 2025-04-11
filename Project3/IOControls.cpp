#include "IOControls.h"

#include <iostream>

/*
* Displays the static menu options available to the user.
* This function is called at the start of the displayMenu loop.
*/
void mainMenu() {
	cout << "1: Check the frequency of a product via word search.\n"
		<< "2: Print a list of items and their purchase frequency.\n"
		<< "3: Print a histogram of items and their purchase frequency.\n"
		<< "4: Exit the program.\n\n";
}

/*
* Prompts the user to enter a string (produce item) and checks that the input is not blank
* and that the item exists in the frequency map
*
* If validation fails, the user is prompted again until valid input is received.
*/
string IOControls::GetValidatedInputString(const string& prompt, const map<string, int>& mapData) {
	string input;
	bool valid;

	do {
		valid = true;
		cout << prompt;

		try {
			getline(cin, input); // Reads entire line from user input

			if (input.empty()) {
				throw runtime_error("Input cannot be blank. Please enter a value.");
			}

			if (mapData.find(input) == mapData.end()) {
				throw runtime_error("Item does not exist in this file.");
			}

			return input; // Return only after input passes all checks
		}
		catch (const runtime_error& e) {
			cerr << "Error: " << e.what() << endl;
			valid = false; // Loop continues if an error was thrown
		}
	} while (!valid);

	// Should never be reached, but included for completeness
	return "";
}

/*
* Handles the core menu loop and user interaction.
* Based on user selection, the program:
*  - Searches for a specific item's frequency (option 1)
*  - (Future) Displays full list of produce frequencies (option 2)
*  - (Future) Displays histogram of frequencies (option 3)
*  - Exits the program (option 4)
*
* The loop runs until the user selects option 4.
*/
void IOControls::displayMenu(const map<string, int>& mapData) {

	cout << "To continue, choose from the menu options below (1-4): \n\n";
	mainMenu();

	do {
		menuChoice = GetValidatedInputInt<int>("Enter the menu option (1-4): ");

		switch (menuChoice) {
		case 1: {
			produceChoice = GetValidatedInputString("Enter a produce item to find the frequency of sale: ", mapData);

			auto it = mapData.find(produceChoice);
			if (it != mapData.end()) {
				cout << "Found in file. Frequency: " << it->second << endl;
			}
			else {
				cout << "Not found in map. Something is mismatched.\n";
			}
			break;
		}

			  // Future cases (2 and 3) can be added here
		}
	} while (menuChoice != 4);
}