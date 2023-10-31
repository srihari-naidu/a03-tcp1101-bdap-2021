#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>

using namespace std;



// Srihari Naidu
// *******************************************************************
//	getDistinctData
//
//  task:	       Finds the distinct elements of an array
//  data in:	   data, distinctData array, distinctDataCount array
//  data returned: None
//
// *******************************************************************

void getDistinctData(vector<double> data, vector<double> &distinctData)
{
    distinctData = data;

    // sorts elements in order
    sort(distinctData.begin(), distinctData.end());

    // removes duplicate elements
    for (int i = 0; i < distinctData.size(); i++)
    {
        if (distinctData[i] == distinctData[i-1])
        {
            distinctData.erase(distinctData.begin()+i);
            i--;
        }
    }
}


// Srihari Naidu
// *******************************************************************
//	getDistinctDataCount
//
//  task:	       Finds the frequency of distinct elements
//  data in:	   data, distinctData array, distinctDataCount array
//  data returned: None
//
// *******************************************************************

void getDistinctDataCount(vector<double> data, vector<double> distinctData, vector<int> &distinctDataCount)
{
    for (int i = 0; i < distinctData.size(); i++)
    {
        int count = 0;
        for (int j = 0; j < data.size(); j++)
        {
            if (distinctData[i] == data[j])
            {
                count++;
            }
        }
        distinctDataCount.push_back(count);
    }

}


// Srihari Naidu
// *******************************************************************
//	distinctDataMember
//
//  task:	       Finds the distinct data members in an array
//       	       and their frequencies
//  data in:	   data, distinctData array, distinctDataCount array
//  data returned: None
//
// *******************************************************************

void distinctDataMember(vector<double> data, vector<double> &distinctData, vector<int> &distinctDataCount)
{
    vector<vector<double>> distinctDataSet;

    getDistinctData(data, distinctData);
    getDistinctDataCount(data, distinctData, distinctDataCount);
}


// Srihari Naidu
// *******************************************************************
//	distinctDataTable
//
//  task:	       Formats the distinct data and it's frequencies
//       	       into a table
//  data in:	   distinctData array, distinctDataCount array
//  data returned: None
//
// *******************************************************************

void distinctDataTable(vector<double> distinctData, vector<int> distinctDataCount)
{
    cout << "+---------------+-----------+" << '\n';
    cout << "| Distinct Data | Frequency |" << '\n';
    cout << "+---------------+-----------+" << '\n';

    for (int i = 0; i < distinctData.size(); i++)
    {
        cout << "| "
             << setw(13) << distinctData[i]
             << " |";
        cout << setw(10) << distinctDataCount[i]
             << " |";
        cout << '\n';
    }

    cout << "+---------------+-----------+" << '\n';
}


// Srihari Naidu
// *******************************************************************
//	showDistinctData
//
//  task:	       Show result from statistical analysis
//  data in:	   rowNum, colNum, columns array, type, data,
//                 distinct data array, distinct data count
//  data returned: None
//
// *******************************************************************

void showDistinctData(int rowNum, int colNum, vector<string> columns, char type, vector<double> data, vector<double> distinctData, vector<int> distinctDataCount)
{
    header(8);
    cout << "+-------------+ DIST. DATA MEMBER +-------------+" << "\n\n"
         << "Data: ";
    showData(rowNum, colNum, columns, type, data);


    cout << "\n\n"
         << "Distinct Data: ";
    showData(distinctData);

    cout << "\n\n\n";
    distinctDataTable(distinctData, distinctDataCount);

    cout << '\n'
         << "+-----------------------------------------------+" << "\n\n";

    cout << "Go Back <ENTER> ";
    cin.get();
}


// Mohammed Emad
// *******************************************************************
//	OPT_DistinctDataMember
//
//  task:	       Show options for user to select either to
//                 use the Row data or Column data
//  data in:	   None
//  data returned: None
//
// *******************************************************************

void OPT_DistinctDataMember()
{
    cout << "+-----------------------------------------------+" << "\n\n"

         << " [1]  Distinct Data Member of a Row."              << '\n'
         << " [2]  Distinct Data Member of a Column."           << "\n\n"

         << " (b)  Back."                                       << "\n\n"

         << "+-----------------------------------------------+" << "\n\n";

    cout << "Choice [12 b]" << '\n'
         << "> ";
}


// Srihari Naidu
// *******************************************************************
//	DistinctDataMember
//
//  task:	       Get data from the data file.
//                 Get the array (row/col) based on user selection.
//                 Show the result (distinct data member) of the array.
//  data in:	   None
//  data returned: None
//
// *******************************************************************

void DistinctDataMember(User &user)
{
    int c, r;
    vector<int> computability; vector<string> columns; vector<vector<double>> rows;
    getData(c, r, computability, columns, rows, user.Datafile());

    vector<double> data; int rowNum; int colNum;
    vector<double> distinctData; vector<int> distinctDataCount;
    do
    {
        header(8); OPT_DistinctDataMember();

        char selection;
        cin >> selection;
        cin.ignore(128, '\n');

        switch (tolower(selection))
        {
            case '1': data = Row(r, rows, computability, rowNum, 8);
                      distinctDataMember(data, distinctData, distinctDataCount);
                      showDistinctData(rowNum, colNum, columns, 'r', data, distinctData, distinctDataCount);
                      user.Log("Displayed Distinct Data Members for Row " + to_string(rowNum) + '\n'); break;
            case '2': data = Col(c, columns, rows, computability, colNum, 8);
                      distinctDataMember(data, distinctData, distinctDataCount);
                      showDistinctData(rowNum, colNum, columns, 'c', data, distinctData, distinctDataCount);
                      user.Log("Displayed Distinct Data Members for " + columns[colNum - 1] + " Column" + '\n'); break;
            case 'b': return;
            default : ERR_InvalidSelection(); break;
        }
    } while (true);
}
