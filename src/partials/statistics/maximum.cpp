#include <iostream>
#include <vector>

using namespace std;


// Najmuddin
// *******************************************************************
//	maximum
//
//  task:	       Find maximum from array of numbers
//  data in:	   array of data
//  data returned: maximum of data
//
// *******************************************************************

double maximum(vector<double> data)
{
    double max = data[0];
    for (int i = 0; i < data.size(); i++)
    {
        if (data[i] > max)
        {
            max = data[i];
        }
    }

    return max;
}


// Mohammed Emad
// *******************************************************************
//	showMaximumResult
//
//  task:	       Show result from statistical analysis
//  data in:	   rowNum, colNum, columns array, type, data,
//                 maximum
//  data returned: None
//
// *******************************************************************

void showMaximumResult(int rowNum, int colNum, vector<string> columns, char type, vector<double> data, double maximum)
{
    header(2);
    cout << "+-----------------+ MAXIMUM +-----------------+" << "\n\n"
         << "Data: ";

    showData(rowNum, colNum, columns, type, data);

    cout << "\n\n"
         << "Maximum: " << maximum << "\n\n"
         << "+---------------------------------------------+" << "\n\n";

    cout << "Go Back <ENTER> ";
    cin.get();
}


// Mohammed Emad
// *******************************************************************
//	OPT_Maximum
//
//  task:	       Show options for user to select either to
//                 use the Row data or Column data
//  data in:	   None
//  data returned: None
//
// *******************************************************************

void OPT_Maximum()
{
    cout << "+---------------------------------------------+" << "\n\n"

         << " [1]  Maximum of a Row."                         << '\n'
         << " [2]  Maximum of a Column."                      << "\n\n"

         << " (b)  Back."                                     << "\n\n"

         << "+---------------------------------------------+" << "\n\n";

    cout << "Choice [12 b]" << '\n'
         << "> ";
}


// Najmuddin
// *******************************************************************
//	Maximum
//
//  task:	       Get data from the data file.
//                 Get the array (row/col) based on user selection.
//                 Show the result (maximum) of the array.
//  data in:	   None
//  data returned: None
//
// *******************************************************************

void Maximum(User &user)
{
    int c, r;
    vector<int> computability; vector<string> columns; vector<vector<double>> rows;
    getData(c, r, computability, columns, rows, user.Datafile());

    vector<double> data;
    int rowNum; int colNum; char type;
    do
    {
        header(2); OPT_Maximum();

        char selection;
        cin >> selection;
        cin.ignore(128, '\n');

        switch (tolower(selection))
        {
            case '1': data = Row(r, rows, computability, rowNum, 2);
                      showMaximumResult(rowNum, colNum, columns, 'r', data, maximum(data));
                      user.Log("Computed Maximum for Row " + to_string(rowNum) + '\n');
                      break;
            case '2': data = Col(c, columns, rows, computability, colNum, 2);
                      showMaximumResult(rowNum, colNum, columns, 'c', data, maximum(data));
                      user.Log("Computed Maximum for " + columns[colNum - 1] + " Column" + '\n');
                      break;
            case 'b': return;
            default : ERR_InvalidSelection(); break;
        }
    } while (true);
}
