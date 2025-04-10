#ifndef IOCONTROLS_H //Define guards per best practices.
#define IOCONTROLS_H

#include <map>
#include <string>
#include <iostream>

using namespace std;



class IOControls
{
public:

	void displayMenu(const map<string, int>& mapData);
	int menuChoice;

};
#endif
