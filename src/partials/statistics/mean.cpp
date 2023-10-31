#include <iostream>
#include <vector>

using namespace std;


// Mohammed Emad
// *******************************************************************
//	mean
//
//  task:	       Find mean from array of numbers
//  data in:	   array of data
//  data returned: mean of data
//
// *******************************************************************

double mean(vector<double> data)
{
    double mean = 0.0;

    double sum = 0;
    int n = data.size();

    for (int i = 0; i < n; i++)
    {
        sum += data[i];
    }

    mean = 1.0*(sum / n);

    return mean;
}


// Mohammed Emad
// *******************************************************************
//	showMeanResult
//
//  task:	       Show result from statistical analysis
//  data in:	   rowNum, colNum, columns array, type, data,
//                 mean
//  data returned: None
//
// *******************************************************************

void showMeanResult(int rowNum, int colNum, vector<string> columns, char type, vector<double> data, double mean)
{
    header(4);
    cout << "+----------+ MEAN +----------+" << "\n\n"
         << "Data: ";

    showData(rowNum, colNum, columns, type, data);

    cout << "\n\n"
         << "Mean: " << mean << "\n\n"
         << "+----------------------------+" << "\n\n";

    cout << "Go Back <ENTER> ";
    cin.get();
}


// Mohammed Emad
// *******************************************************************
//	OPT_Mean
//
//  task:	       Show options for user to select either to
//                 use the Row data or Column data
//  data in:	   None
//  data returned: None
//
// *******************************************************************

void OPT_Mean()
{
    cout << "+----------------------------+" << "\n\n"

         << " [1]  Mean of a Row."           << '\n'
         << " [2]  Mean of a Column."        << "\n\n"

         << " (b)  Back."                    << "\n\n"

         << "+----------------------------+" << "\n\n";

    cout << "Choice [12 b]" << '\n'
         << "> ";
}


// Mohammed Emad
// *******************************************************************
//	Mean
//
//  task:	       Get data from the data file.
//                 Get the array (row/col) based on user selection.
//                 Show the result (mean) of the array.
//  data in:	   None
//  data returned: None
//
// *******************************************************************

void Mean(User &user)
{
    int c, r;
    vector<int> computability; vector<string> columns; vector<vector<double>> rows;
    getData(c, r, computability, columns, rows, user.Datafile());

    vector<double> data;
    int rowNum; int colNum; char type;
    do
    {
        header(4); OPT_Mean();

        char selection;
        cin >> selection;
        cin.ignore(128, '\n');

        switch (tolower(selection))
        {
            case '1': data = Row(r, rows, computability, rowNum, 4);
                      showMeanResult(rowNum, colNum, columns, 'r', data, mean(data));
                      user.Log("Computed Mean for Row " + to_string(rowNum) + '\n');
                      break;
            case '2': data = Col(c, columns, rows, computability, colNum, 4);
                      showMeanResult(rowNum, colNum, columns, 'c', data, mean(data));
                      user.Log("Computed Mean for " + columns[colNum - 1] + " Column" + '\n'); break;
            case 'b': return;
            default : ERR_InvalidSelection(); break;
        }

    } while (true);
}
