#include <iostream>
#include <vector>
#include <cmath>

using namespace std;


// Srihari Naidu
// *******************************************************************
//	correlation
//
//  task:	       Find correlation between 2 array of numbers
//  data in:	   2 array of data
//  data returned: correlation of data
//
// *******************************************************************

double correlation(vector<vector<double>> data)
{
    double correlation = 0.0;

    vector<double> dataX = data[0];
    vector<double> dataY = data[1];

    double meanX = mean(dataX);
    double meanY = mean(dataY);

    double devX = 0.0, devY = 0.0;

    double sumDevXY = 0.0;
    double sumDevXsquare = 0.0;
    double sumDevYsquare = 0.0;


    for (int i = 0; i < dataX.size(); i++)
    {
        devX = dataX[i] - meanX;
        devY = dataY[i] - meanY;

        sumDevXY += (devX * devY);

        sumDevXsquare += pow(devX, 2);
        sumDevYsquare += pow(devY, 2);
    }

    correlation = sumDevXY / (sqrt(sumDevXsquare * sumDevYsquare)) * 1.0;

    return correlation;
}


// Srihari Naidu
// *******************************************************************
//	showCorrelation
//
//  task:	       Show result from statistical analysis
//  data in:	   rowNum, colNum, columns array, type, data,
//                 correlation
//  data returned: None
//
// *******************************************************************

void showCorrelation(int col1Num, int col2Num, vector<string> columns, vector<vector<double>> data, double correlation)
{
    header(7);
    cout << "+-----------------------+ CORRELATION +-----------------------+" << "\n\n"
         << "Data: " << '\n';

    showData(0, col1Num, columns, 'c', data[0]);
    cout << '\n';
    showData(0, col2Num, columns, 'c', data[1]);

    cout << "\n\n"
         << "Correlation: " << correlation << "\n\n"
         << "+-------------------------------------------------------------+" << "\n\n";

    cout << "Go Back <ENTER> ";
    cin.get();
}


// Srihari Naidu
// *******************************************************************
//	PearsonsCorrelation
//
//  task:	       Get data from the data file.
//                 Get the array (row/col) based on user selection.
//                 Show the result (correlation) of the array.
//  data in:	   None
//  data returned: None
//
// *******************************************************************


void PearsonsCorrelation(User &user)
{
    int c, r;
    vector<int> computability;
    vector<string> columns;
    vector<vector<double>> rows;
    getData(c, r, computability, columns, rows, user.Datafile());

    vector<vector<double>> data;
    int col1Num, col2Num;

    header(7);
    data = twoCol(c, columns, rows, computability, col1Num, col2Num, 7);

    showCorrelation(col1Num, col2Num, columns, data, correlation(data));
    user.Log("Computed Pearson's Correlation between " + columns[col1Num - 1] + " Column" + " and " + columns[col2Num - 1] + " Column" + '\n');
}