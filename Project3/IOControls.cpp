#include "IOControls.h"

#include <iostream>
#include <iomanip>
#include <cstdlib>	// For exit
#include <thread>   // For sleep_for
#include <chrono>   // For chrono::seconds

/*
* Displays the static menu options available to the user.
* This function is called at the start of the displayMenu loop.
*/
void mainMenu() {
	cout<<"\n1: Check the frequency of a product via word search.\n"
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

			input[0] = toupper(input[0]); //Sets the first letter to uppercase and the rest to lowercase for QOL.
			for (size_t i = 1; i < input.length(); ++i) {
				input[i] = tolower(input[i]);
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
*  - Displays full list of produce frequencies (option 2)
*  - Displays histogram of frequencies (option 3)
*  - Exits the program (option 4)
*
* The loop runs until the user selects option 4.
*/
void IOControls::displayMenu(const map<string, int>& mapData) {
	cout << "To continue, choose from the menu options below (1-4): \n";

	do { 
		mainMenu();
		menuChoice = GetValidatedInputInt<int>("\nEnter the menu option (1-4): ");
		cout << endl;

		switch (menuChoice) {
		case 1: { // If the usere chooses 1, they will be prompted to enter a produce item. Their entry is checked with a validator and returns the frequency of that item if it exists. 
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
		case 2: { // If the user chooses option 2, the list of produce and their frequency is displayed.
			for (const auto& pair : mapData) {
				cout << pair.first << " " << pair.second << endl;
			}
			break;

		case 3: { // If the user chooses option 3, the list of produce and their frequency is displayed. This time as a style histogram. 
			cout << "\033[32m";  // Sets the color to green.
			cout << "\nItem Name         | Frequency\n";
			cout << "------------------+---------------------------\n";

			for (const auto& pair : mapData) { // Handles minor styling and changing the output of the number to '*' of the same amount, so (4) = (****).
				cout << left << setw(18) << pair.first << "| ";
				for (int i = 0; i < pair.second; ++i) {
					cout << '*';
				}
				cout << endl;
			}
			cout << "\033[37m"; //Changes the text back to white after the histogram. 
			break;
		}
		case 4: { // If the user chooses option 4, a exit messaage is displayed for 4 seconds and then the program terminates. 
			cout << "Closing in 4 seconds... You may view your backup in frequency.dat! ";
			this_thread::sleep_for(chrono::seconds(4));  // Waits 4 seconds
			exit(1);
		}
		}
		}
	} while (menuChoice != 4);
}