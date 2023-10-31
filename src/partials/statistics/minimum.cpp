#include <iostream>
#include <vector>

using namespace std;



// Najmuddin
// *******************************************************************
//	minimum
//
//  task:	       Find minimum from array of numbers
//  data in:	   array of data
//  data returned: minimum of data
//
// *******************************************************************

double minimum(vector<double> data)
{
    double min = data[0];
    for (int i = 0; i < data.size(); i++)
    {
        if (data[i] < min)
        {
            min = data[i];
        }
    }

    return min;
}


// Mohammed Emad
// *******************************************************************
//	showMinimumResult
//
//  task:	       Show result from statistical analysis
//  data in:	   rowNum, colNum, columns array, type, data,
//                 minimum
//  data returned: None
//
// *******************************************************************

void showMinimumResult(int rowNum, int colNum, vector<string> columns, char type, vector<double> data, double minimum)
{
    header(1);
    cout << "+----------------+ MINIMUM +----------------+" << "\n\n"
         << "Data: ";

    showData(rowNum, colNum, columns, type, data);

    cout << "\n\n"
         << "Minimum: " << minimum << "\n\n"
         << "+-------------------------------------------+" << "\n\n";

    cout << "Go Back <ENTER> ";
    cin.get();
}


// Mohammed Emad
// *******************************************************************
//	OPT_Minimum
//
//  task:	       Show options for user to select either to
//                 use the Row data or Column data
//  data in:	   None
//  data returned: None
//
// *******************************************************************

void OPT_Minimum()
{
    cout << "+-------------------------------------------+" << "\n\n"

         << " [1]  Minimum of a Row."                       << '\n'
         << " [2]  Minimum of a Column."                    << "\n\n"

         << " (b)  Back."                                   << "\n\n"

         << "+-------------------------------------------+" << "\n\n";

    cout << "Choice [12 b]" << '\n'
         << "> ";
}


// Najmuddin
// *******************************************************************
//	Minimum
//
//  task:	       Get data from the data file.
//                 Get the array (row/col) based on user selection.
//                 Show the result (minimum) of the array.
//  data in:	   None
//  data returned: None
//
// *******************************************************************

void Minimum(User &user)
{
    int c, r;
    vector<int> computability; vector<string> columns; vector<vector<double>> rows;
    getData(c, r, computability, columns, rows, user.Datafile());

    vector<double> data;
    int rowNum; int colNum; char type;
    do
    {
        header(1); OPT_Minimum();

        char selection;
        cin >> selection;
        cin.ignore(128, '\n');

        switch (tolower(selection))
        {
            case '1': data = Row(r, rows, computability, rowNum, 1);
                      showMinimumResult(rowNum, colNum, columns, 'r', data, minimum(data));
                      user.Log("Computed Minimum for Row " + to_string(rowNum) + '\n');
                      break;
            case '2': data = Col(c, columns, rows, computability, colNum, 1);
                      showMinimumResult(rowNum, colNum, columns, 'c', data, minimum(data));
                      user.Log("Computed Minimum for " + columns[colNum - 1] + " Column" + '\n');
                      break;
            case 'b': return;
            default : ERR_InvalidSelection(); break;
        }
    } while (true);
}
