#include <iostream>
#include <cmath>
#include <vector>

using namespace std;



// Muhammad Aiman
// *******************************************************************
//	variance
//
//  task:	       Find variance from array of numbers
//  data in:	   array of data
//  data returned: variance of data
//
// *******************************************************************

double variance(vector<double> data)
{
    int n = data.size();
    double _mean = 0.0;
    double dev;
    double sumDev = 0.0;
    double variance = 0.0;

    _mean = mean(data);

    for (int i = 0; i < n; i++)
    {
        dev = pow((data[i] - _mean), 2);
        sumDev += dev;
    }

    variance = sumDev / (1.0*(n - 1));

    return variance;
}


// Mohammed Emad
// *******************************************************************
//	showVarianceResult
//
//  task:	       Show result from statistical analysis
//  data in:	   rowNum, colNum, columns array, type, data,
//                 variance
//  data returned: None
//
// *******************************************************************

void showVarianceResult(int rowNum, int colNum, vector<string> columns, char type, vector<double> data, double variance)
{
    header(5);
    cout << "+------------------+ VARIANCE +------------------+" << "\n\n"
         << "Data: ";

    showData(rowNum, colNum, columns, type, data);

    cout << "\n\n"
         << "Variance: " << variance << "\n\n"
         << "+-----------------------------------------------+" << "\n\n";

    cout << "Go Back <ENTER> ";
    cin.get();
}


// Mohammed Emad
// *******************************************************************
//	OPT_Variance
//
//  task:	       Show options for user to select either to
//                 use the Row data or Column data
//  data in:	   None
//  data returned: None
//
// *******************************************************************

void OPT_Variance()
{
    cout << "+-----------------------------------------------+" << "\n\n"

         << " [1]  Variance of a Row."                          << '\n'
         << " [2]  Variance of a Column."                       << "\n\n"

         << " (b)  Back."                                       << "\n\n"

         << "+-----------------------------------------------+" << "\n\n";

    cout << "Choice [12 b]" << '\n'
         << "> ";
}


// Muhammad Aiman
// *******************************************************************
//	Variance
//
//  task:	       Get data from the data file.
//                 Get the array (row/col) based on user selection.
//                 Show the result (variance) of the array.
//  data in:	   None
//  data returned: None
//
// *******************************************************************

void Variance(User &user)
{
    int c, r;
    vector<int> computability; vector<string> columns; vector<vector<double>> rows;
    getData(c, r, computability, columns, rows, user.Datafile());

    vector<double> data;
    int rowNum; int colNum; char type;
    do
    {
        header(5); OPT_Variance();

        char selection;
        cin >> selection;
        cin.ignore(128, '\n');

        switch (tolower(selection))
        {
            case '1': data = Row(r, rows, computability, rowNum, 5);
                      showVarianceResult(rowNum, colNum, columns, 'r', data, variance(data));
                      user.Log("Computed Variance for Row " + to_string(rowNum) + '\n');
                      break;
            case '2': data = Col(c, columns, rows, computability, colNum, 5);
                      showVarianceResult(rowNum, colNum, columns, 'c', data, variance(data));
                      user.Log("Computed Variance for " + columns[colNum - 1] + " Column" + '\n');
                      break;
            case 'b': return;
            default : ERR_InvalidSelection(); break;
        }
    } while (true);
}
