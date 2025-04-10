#ifndef GATHERFILEDATA_H //Define guards per best practices.
#define GATHERFILEDATA_H


#include <string>
#include <vector>
#include <map>

using namespace std;

/*
* The header file for a class that gathers data from a produce list, creates a map and writes it to a new file. 
* See documentation on the corresponding .cpp file for more. 
*/
class GatherFileData {
public:

	GatherFileData(const string& file, const string& file2);
	const map <string, int>& GetFrequency() const;

private:
	string fileName;
	string fileName2;
	void read();
	map <string, int> frequency;
};

#endif