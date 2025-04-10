/*
* Paul Joplin
* 04-07-2025
* CS - 210
* Project Three - Corner Grocer
*
* Project Three is a culmination of all concepts observed involving C++ in CS - 210. The client, Corner Grocer, has requested a text file analyzer to help with the future changes of their produce department. The program will analyze
* a text record for word frequency via sstream. The program will implement the use of a class system and strong input validation practices. The same approach to data gathering will be used as the module 5 assignment.
*
*/

#include <iostream>
#include <fstream>

#include "GatherFileData.h"
#include "IOControls.h"

using namespace std;

int main() {
	IOControls controls;

	GatherFileData reader("ProduceList.txt", "frequency.dat");
	controls.displayMenu(reader.GetFrequency());

	return 0;
}