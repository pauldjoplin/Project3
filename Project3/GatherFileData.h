#ifndef GATHERFILEDATA_H //Define guards per best practices.
#define GATHERFILEDATA_H
#pragma once

#include <string>
#include <vector>

using namespace std;

class GatherFileData {
public:

	GatherFileData(const string& file, const string& file2);

	string read();

private:
	string fileName;
	string fileName2;
};

#endif