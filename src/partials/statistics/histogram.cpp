#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>

using namespace std;



// Srihari Naidu
// *******************************************************************
//	histogram
//
//  task:	       Get distinct data and data count of each data
//                 Print out histogram in text mode
//
// *******************************************************************

void histogram(vector<double> data, vector<string> columns, int colNum)
{
    vector<double> values;
    vector<int> valueCount;
    distinctDataMember(data, values, valueCount);

    string column = columns[colNum - 1];
    cout << setw(5) << left << "Count" << "  ";
    cout << setw(9) << right << column << endl;

    for (int i = 0; i < values.size(); i++)
    {
        cout << setw(5) << right << valueCount[i] << "  ";
        cout << setw(9) << right << values[i] << "|";

        for (int j = 0; j < valueCount[i]; j++)
        {
            cout << "=";
        }
        cout << endl;
    }
}


// Srihari Naidu
// *******************************************************************
//	showHistogram
//
//  task:	       Show histogram for selected column
//  data in:	   Data array
//  data returned: None
//
// *******************************************************************

void showHistogram(vector<double> data, vector<string> columns, int colNum)
{
    header(9);
    cout << "+---------------------+ HISTOGRAM +---------------------+" << "\n\n";
    cout << "Data: ";
    showData(0, colNum, columns, 'c', data);
    cout << "\n\n";

    histogram(data, columns, colNum);

    cout << '\n';
    cout << "+-------------------------------------------------------+" << "\n\n";

    cout << "Go Back <ENTER> ";
    cin.get();
}


// Srihari Naidu
// *******************************************************************
//	Histogram
//
//  task:	       Get data from the data file.
//                 Get the array (row/col) based on user selection.
//                 Show the result (histogram) of the array.
//  data in:	   None
//  data returned: None
//
// *******************************************************************

void Histogram(User &user)
{
    int c, r;
    vector<int> computability;
    vector<string> columns;
    vector<vector<double>> rows;
    getData(c, r, computability, columns, rows, user.Datafile());

    vector<double> data;
    int colNum;

    header(9);
    data = Col(c, columns, rows, computability, colNum, 9);

    showHistogram(data, columns, colNum);
    user.Log("Plotted Histogram for " + columns[colNum - 1] + " Column" + '\n');
}
