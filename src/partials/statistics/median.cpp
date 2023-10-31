#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


// Mohammed Emad
// *******************************************************************
//	median
//
//  task:	       Find median from array of numbers
//  data in:	   array of data
//  data returned: median of data
//
// *******************************************************************

double median(vector<double> data)
{
    double median;

    int size = data.size();
    int mid = size / 2;

    sort(data.begin(), data.end());

    if (size % 2 == 0)
    {
        median = (data[mid] + data[mid - 1]) / 2.0;
        return median;
    }

    return data[mid];
}


// Mohammed Emad
// *******************************************************************
//	showMedianResult
//
//  task:	       Show result from statistical analysis
//  data in:	   rowNum, colNum, columns array, type, data,
//                 median
//  data returned: None
//
// *******************************************************************

void showMedianResult(int rowNum, int colNum, vector<string> columns, char type, vector<double> data, double median)
{
    header(3);
    cout << "+--------------+ MEDIAN +--------------+" << "\n\n"
         << "Data: ";

    showData(rowNum, colNum, columns, type, data);

    cout << "\n\n"
         << "Median: " << median << "\n\n"
         << "+--------------------------------------+" << "\n\n";

    cout << "Go Back <ENTER> ";
    cin.get();
}


// Mohammed Emad
// *******************************************************************
//	OPT_Median
//
//  task:	       Show options for user to select either to
//                 use the Row data or Column data
//  data in:	   None
//  data returned: None
//
// *******************************************************************

void OPT_Median()
{
    cout << "+--------------------------------------+" << "\n\n"

         << " [1]  Median of a Row."                   << '\n'
         << " [2]  Median of a Column."                << "\n\n"

         << " (b)  Back."                              << "\n\n"

         << "+--------------------------------------+" << "\n\n";

    cout << "Choice [12 b]" << '\n'
         << "> ";
}


// Mohammed Emad
// *******************************************************************
//	Median
//
//  task:	       Get data from the data file.
//                 Get the array (row/col) based on user selection.
//                 Show the result (median) of the array.
//  data in:	   None
//  data returned: None
//
// *******************************************************************

void Median(User &user)
{
    int c, r;
    vector<int> computability; vector<string> columns; vector<vector<double>> rows;
    getData(c, r, computability, columns, rows, user.Datafile());

    vector<double> data;
    int rowNum; int colNum; char type;
    do
    {
        header(3); OPT_Median();

        char selection;
        cin >> selection;
        cin.ignore(128, '\n');

        switch (tolower(selection))
        {
            case '1': data = Row(r, rows, computability, rowNum, 3);
                      showMedianResult(rowNum, colNum, columns, 'r', data, median(data));
                      user.Log("Computed Median for Row " + to_string(rowNum) + '\n');
                      break;
            case '2': data = Col(c, columns, rows, computability, colNum, 3);
                      showMedianResult(rowNum, colNum, columns, 'c', data, median(data));
                      user.Log("Computed Median for " + columns[colNum - 1] + " Column" + '\n');
                      break;
            case 'b': return;
            default : ERR_InvalidSelection(); break;
        }
    } while (true);
}
