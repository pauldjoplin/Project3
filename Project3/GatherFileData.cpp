#include "GatherFileData.h"

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <map>

using namespace std;

/*
* Corresponds with GatherFileData header and works with main.cpp and IOControls.cpp. 
* This class gathers data from one file(Produce List), creates a map with one occurrence of the word and 
* how many times it was used, and then copies the map to a new file for data retention purposes. 
* Lastly, it prepares the map to be used in the IOControls class so users can view the data, but not mutate it. 
*/

GatherFileData::GatherFileData(const string& file, const string& file2) 
	: fileName(file), fileName2(file2) { read();
} // Constructor initializes the object with input and output file names for reading and writing. It also calls the read() function so it will not need to be called in main. 

void GatherFileData::read() { // Handles reading input, building the frequency map, and writing the results to a file. 

	ifstream inputStream(fileName); // Variable for reading the produce list.
	ofstream outputStream(fileName2); // Variable for writing to frequency.dat. 
	string produce, line;

	//Line 29 and 33 check to see if the file failed to open.
	if (!inputStream.is_open()) { 
		cerr << "Failed to open file: " << fileName << endl; 
		return;
	}

	if (!outputStream.is_open()) {
		cerr << "Failed to open file: " << fileName2 << endl;
		return;
	}

	while (getline(inputStream, line)) { // Parses each line of the file until it reaches the end. Stores the word in "produce" and updates the frequency. 
		istringstream stream(line);

		if (!(stream >> produce)) { // If parsing fails. 
			cerr << "Error parsing file: " << fileName << endl;
			continue; // The parsing must continue even if one line fails. 
		}
		else { // Otherwise update frequency. 
			frequency[produce]++;
		}
	}

	for (const auto& pair : frequency) { // Writes each produce item once and its frequency to the output file. 
		if (pair.second >= 1) {
			outputStream << pair.first << " " << pair.second << endl;
			
		}
	}
	inputStream.close(); // Closes the files per proper and best practices. 
	outputStream.close();
}

const map <string, int>& GatherFileData::GetFrequency() const { // Allows the data from frequency map to be used throughout the program. 
	return frequency;
}


  
