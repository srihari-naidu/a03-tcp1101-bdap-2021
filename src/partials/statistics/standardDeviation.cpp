#include <iostream>
#include <cmath>
#include <vector>

using namespace std;



// Muhammad Aiman
// *******************************************************************
//	standardDeviation
//
//  task:	       Find standardDeviation from array of numbers
//  data in:	   array of data
//  data returned: standard deviation of data
//
// *******************************************************************

double standardDeviation(vector<double> data)
{
    double _variance = variance(data);
    double standardDeviation = sqrt(_variance);

    return standardDeviation;
}


// Mohammed Emad
// *******************************************************************
//	showStandardDeviationResult
//
//  task:	       Show result from statistical analysis
//  data in:	   rowNum, colNum, columns array, type, data,
//                 standard deviation
//  data returned: None
//
// *******************************************************************

void showStandardDeviationResult(int rowNum, int colNum, vector<string> columns, char type, vector<double> data, double standardDeviation)
{
    header(6);
    cout << "+----------+ STANDARD DEVIATION +----------+" << "\n\n"
         << "Data: ";

    showData(rowNum, colNum, columns, type, data);

    cout << "\n\n"
         << "Standard Deviation: " << standardDeviation << "\n\n"
         << "+------------------------------------------+" << "\n\n";

    cout << "Go Back <ENTER> ";
    cin.get();
}


// Mohammed Emad
// *******************************************************************
//	OPT_StandardDeviation
//
//  task:	       Show options for user to select either to
//                 use the Row data or Column data
//  data in:	   None
//  data returned: None
//
// *******************************************************************

void OPT_StandardDeviation()
{
    cout << "+------------------------------------------+" << "\n\n"

         << " [1]  Standard Deviation of a Row."           << '\n'
         << " [2]  Standard Deviation of a Column."        << "\n\n"

         << " (b)  Back."                                  << "\n\n"

         << "+------------------------------------------+" << "\n\n";

    cout << "Choice [12 b]" << '\n'
         << "> ";
}


// Muhammad Aiman
// *******************************************************************
//	StandardDeviation
//
//  task:	       Get data from the data file.
//                 Get the array (row/col) based on user selection.
//                 Show the result (standardDeviation) of the array.
//  data in:	   None
//  data returned: None
//
// *******************************************************************

void StandardDeviation(User &user)
{
    int c, r;
    vector<int> computability; vector<string> columns; vector<vector<double>> rows;
    getData(c, r, computability, columns, rows, user.Datafile());

    vector<double> data;
    int rowNum; int colNum; char type;
    do
    {
        header(6); OPT_StandardDeviation();

        char selection;
        cin >> selection;
        cin.ignore(128, '\n');

        switch (tolower(selection))
        {
            case '1': data = Row(r, rows, computability, rowNum, 6);
                      showStandardDeviationResult(rowNum, colNum, columns, 'r', data, standardDeviation(data));
                      user.Log("Computed Standard Deviation for Row " + to_string(rowNum) + '\n');
                      break;
            case '2': data = Col(c, columns, rows, computability, colNum, 6);
                      showStandardDeviationResult(rowNum, colNum, columns, 'c', data, standardDeviation(data));
                      user.Log("Computed Standard Deviation for " + columns[colNum - 1] + " Column" + '\n');
                      break;
            case 'b': return;
            default : ERR_InvalidSelection(); break;
        }
    } while (true);
}
