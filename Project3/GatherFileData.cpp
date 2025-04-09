#include "GatherFileData.h"

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <map>

using namespace std;

GatherFileData::GatherFileData(const string& file, const string& file2) : fileName(file), fileName2(file2) {}

string GatherFileData::read() {
	ifstream produceStream(fileName);
	ofstream ammendedStream(fileName2);

	string produce;
	string line;
	map<string, int>produceList;

	if (!produceStream.is_open()) {
		cerr << "Failed to open file: " << fileName << endl;
		return "";
	}

	if (!ammendedStream.is_open()) {
		cerr << "Failed to open file: " << fileName2 << endl;
		return "";
	}

	while (getline(produceStream, line)) {
		istringstream stream(line);

		if (!(stream >> produce)) {
			cerr << "Error parsing file: " << fileName << endl;
			continue;
		}
		else {
			produceList[produce]++;
		}
	}

	for (const auto& pair : produceList) {
		if (pair.second >= 1) {
			ammendedStream << pair.first << ": " << pair.second << endl;
		}
	}

	produceStream.close();
	ammendedStream.close();

	return "";
}