#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;



// *******************************************************************
//	fileIsEmpty
//
//  task:	       Check if file is empty
//  data in:	   File name string
//  data returned: True if file is empty, false otherwise
//
// *******************************************************************

bool fileIsEmpty(string filename)
{
    fstream file;
    file.open(filename, ios::in);

    string line;
    if (!(file >> line)) // if there are no contents in the first line
    {
        file.close();
        return true;
    }
    else
    {
        file.close();
        return false;
    }
}