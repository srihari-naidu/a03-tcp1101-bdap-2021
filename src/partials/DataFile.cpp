#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;



// *******************************************************************
//	verifyN
//
//  task:	       Check if numeric data is valid and formatted
//  data in:	   Data string
//  data returned: None
//
// *******************************************************************

void verifyN(string data)
{
    data = trim(data);
    for (int i = 0; i < data.length(); i++)
    {
        if (!isdigit(data[i]) && data[i] != '.')
        {
            cout << "\n\nERROR! Invalid data format.\n"
                 << "Data contains invalid non-numeric characters.";
            break;
        }
    }
}



// *******************************************************************
//	verifyLCol
//
//  task:	       Check if lencolumn length is valid and formatted
//  data in:	   Number of columns, 1Data string
//  data returned: None
//
// *******************************************************************

void verifyLCol(int nCol, int sData)
{
    if (sData > nCol)
    {
        cout << "\n\nERROR! Invalid data format.\n"
             << "Data provided exceeds number of columns.";
        exit(EXIT_FAILURE);
    }
    else if (nCol > sData)
    {
        cout << "\n\nERROR! Invalid data format.\n"
             << "Data provided falls short of the number of columns.";
        exit(EXIT_FAILURE);
    }
}



// *******************************************************************
//	verifyLRow
//
//  task:	       Check if row length is valid and formatted
//  data in:	   Number of rows, Data string
//  data returned: None
//
// *******************************************************************

void verifyLRow(int nRow, int sData)
{
    if (sData > nRow)
    {
        cout << "\n\nERROR! Invalid data format.\n"
             << "Data provided exceeds number of rows.";
        exit(EXIT_FAILURE);
    }
    else if (nRow > sData)
    {
        cout << "\n\nERROR! Invalid data format.\n"
             << "Data provided falls short of the number of rows.";
        exit(EXIT_FAILURE);
    }
}



// *******************************************************************
//	verifyComputability
//
//  task:	       Check if there is at least one computable
//                 data column
//  data in:	   Number of rows, Data string
//  data returned: None
//
// *******************************************************************

void verifyComputability(vector<int> computability)
{
    bool oneComputable = false;

    for (int i = 0; i < computability.size(); i++)
    {
        if (computability[i] == 1)
        {
            oneComputable = true;
            break;
        }
    }
    if (!oneComputable)
    {
        cout << "\n\nERROR! Invalid data.\n"
             << "Data provided has no computable column.";
        exit(EXIT_FAILURE);
    }
}



// *******************************************************************
//	showData - simple
//
//  task:	       Prettify and print the passed-in data array
//  data in:	   data array
//  data returned: None
//
// *******************************************************************

void showData(vector<double> data)
{
    int sz = data.size();

    for (int i = 0; i < sz; i++)
    {
        if (i == 0)
        {
            cout << '\n' << "| " <<  data[i] << " | ";
        }
        else
        {
            cout << data[i] << " | ";
        }
    }
}



// *******************************************************************
//	showData - complex
//
//  task:	       Prettify and print the passed-in data array
//  data in:	   rowNum, colNum, columns array, ary type, data,
//  data returned: None
//
// *******************************************************************

void showData(int rowNum, int colNum, vector<string> columns, char type, vector<double> data)
{
    int sz = data.size();

    for (int i = 0; i < sz; i++)
    {
        if (i == 0)
        {
            if (type == 'r')
            {
                cout << "Row " << rowNum << '\n' << "| " <<  data[i] << " | ";
            }
            else if (type == 'c')
            {
                cout << columns[colNum-1] << " Column\n" << "| " << data[i] << " | ";
            }
        }
        else
        {
            cout << data[i] << " | ";
        }
    }
}



// *******************************************************************
//	getData
//
//  task:	       Retrived data to analyze from the data file
//  data in:	   variables passed by reference
//                 c - number of columns
//                 r - number of rows
//                 computability - computability of certain column
//                 columns - column array
//                 rows - row array
//  data returned: respective data from the data file
//
// *******************************************************************

void getData(int &c, int&r, vector<int> &computability, vector<string> &columns, vector<vector<double>> &rows, string datafile)
{
    string dataDAT = "datafiles/" + datafile;
    fstream file;
    file.open(dataDAT, ios::in);

    if (file.is_open())
    {
        string line;

        // get c --> number of colums
        getline(file, line);
        verifyN(line);
        stringstream ssCol(line);
        ssCol >> c;

        // get columns
        while (getline(file, line))
        {
            stringstream ss(line);
            while (getline(ss, line, ','))
            {
                columns.push_back(trim(line));
            }
            verifyLCol(c, columns.size());
            break;
        }

        // get computability
        while (getline(file, line))
        {
            stringstream ss(line);
            while (getline(ss, line, ','))
            {
                verifyN(trim(line));
                computability.push_back(stoi(trim(line)));
            }
            verifyLCol(c, computability.size());
            break;
        }
        verifyComputability(computability);

        // get r --> number of rows
        getline(file, line);
        verifyN(line);
        stringstream ssRow(line);
        ssRow >> r;

        // get rows
        while (getline(file, line))
        {
            vector<double> row;
            stringstream ss(line);
            while (getline(ss, line, ','))
            {
                verifyN(line);
                row.push_back(stold(line));
            }
            verifyLCol(c, row.size());

            rows.push_back(row);
        }
        verifyLRow(r, rows.size());
    }
    else
    {
        cout << "\n\nERROR! File doesn't exist.\n"
             << datafile << " was not found.\n";
        exit(EXIT_FAILURE);
    }

    file.close();
}



// ***********************************************************************************************************

void TOP_Row(int htype)
{
    switch (htype)
    {
        case 1: cout << "+------------------+ ROW +------------------+" << "\n\n"; break;
        case 2: cout << "+-------------------+ ROW +-------------------+" << "\n\n"; break;
        case 3: cout << "+---------------+ ROW +----------------+" << "\n\n"; break;
        case 4: cout << "+----------+ ROW +-----------+" << "\n\n"; break;
        case 5: cout << "+--------------------+ ROW +---------------------+" << "\n\n"; break;
        case 6: cout << "+-----------------+ ROW +------------------+" << "\n\n"; break;
        case 7: cout << "+---------------------------+ ROW +---------------------------+" << "\n\n"; break;
        case 8: cout << "+--------------------+ ROW +--------------------+" << "\n\n"; break;
        case 9: cout << "+------------------------+ ROW +------------------------+" << "\n\n"; break;
        default: break;
    }
}



// *******************************************************************
//	Row
//
//  task:	       Prompt the user to enter the row number, and
//                 retrieve the respective row data.
//  data in:	   r - number of rows
//                 rows - arrays of row data
//                 computability - computability of certain column
//                 htype - type of header
//  data returned: array of retrieved row
//
// *******************************************************************

vector<double> Row(int r, vector<vector<double>> rows, vector<int> computability, int &rowNum, int htype)
{
    vector<double> data;

    do
    {
        header(htype);
        TOP_Row(htype);

        cout << "Row Number (1-" << r << ")" << '\n';
        cout << "> ";
        cin >> rowNum;
        cin.clear();
        cin.ignore(128, '\n');

        if (rowNum > 0 && rowNum <= r)
        {
            vector<double> row = rows[rowNum-1];
            for (int i = 0; i < r; i++)
            {
                if (computability[i] == 1)
                    data.push_back(row[i]);
            }
            break;
        }
        else { ERR_InvalidRow(); }

    } while (true);

    return data;
}

// ***********************************************************************************************************



// ***********************************************************************************************************

// *******************************************************************
//	TOP_Col
//
//  task:	       Print different top borders for different
//                 header types
//  data in:	   header type
//  data returned: None
//
// *******************************************************************

void TOP_Col(int htype)
{
    switch (htype)
    {
        case 1: cout << "+-----------------+ COLUMN +----------------+" << "\n\n"; break;
        case 2: cout << "+------------------+ COLUMN +-----------------+" << "\n\n"; break;
        case 3: cout << "+--------------+ COLUMN +--------------+" << "\n\n"; break;
        case 4: cout << "+---------+ COLUMN +---------+" << "\n\n"; break;
        case 5: cout << "+-------------------+ COLUMN +-------------------+" << "\n\n"; break;
        case 6: cout << "+----------------+ COLUMN +----------------+" << "\n\n"; break;
        case 7: cout << "+-------------------------+ COLUMN +--------------------------+" << "\n\n"; break;
        case 8: cout << "+-------------------+ COLUMN +------------------+" << "\n\n"; break;
        case 9: cout << "+----------------------+ COLUMN +-----------------------+" << "\n\n"; break;
        default: break;
    }
}

// *******************************************************************
//	BOTTOM_Col
//
//  task:	       Print different bottom borders for different
//                 header types
//  data in:	   header type
//  data returned: None
//
// *******************************************************************

void BOTTOM_Col(int htype)
{
    switch (htype)
    {
        case 1: cout << "+-------------------------------------------+" << "\n\n"; break;
        case 2: cout << "+---------------------------------------------+" << "\n\n"; break;
        case 3: cout << "+--------------------------------------+" << "\n\n"; break;
        case 4: cout << "+----------------------------+" << "\n\n"; break;
        case 5: cout << "+------------------------------------------------+" << "\n\n"; break;
        case 6: cout << "+------------------------------------------+" << "\n\n"; break;
        case 7: cout << "+-------------------------------------------------------------+" << "\n\n"; break;
        case 8: cout << "+-----------------------------------------------+" << "\n\n"; break;
        case 9: cout << "+-------------------------------------------------------+" << "\n\n"; break;
        default: break;
    }
}



// *******************************************************************
//	OPT_Col
//
//  task:	       Show columns options
//  data in:	   c - number of columns
//                 columns - arrays of columns
//                 computability - computability of certain column
//                 htype - type of header
//  data returned: None
//
// *******************************************************************

void OPT_Col(int c, vector<string> columnns, vector<int>computability, int htype, int col1Num = -1)
{
    string choices;

    TOP_Col(htype);
    for (int i = 0; i < c; i++)
    {
        if (computability[i] == 1 && (i+1) != col1Num)
        {
            cout << "[" << i+1 << "]  " << columnns[i] << '\n';
            choices += to_string(i+1);

        }
    }
    cout << '\n';
    BOTTOM_Col(htype);

    cout << "Choice [" << choices << "]" << '\n'
         << "> ";
}

// *******************************************************************
//	Col
//
//  task:	       Prompt the user to enter the column number, and
//                 retrieve the respective column data.
//  data in:	   c - number of columns
//                 columns - arrays of columns
//                 rows - arrays of row data
//                 computability - computability of certain column
//                 colNum - selected column number passed by reference
//                 htype - type of header
//  data returned: array of retrieved column
//
// *******************************************************************

vector<double> Col(int c, vector<string> columns, vector<vector<double>> rows, vector<int> computability, int &colNum, int htype)
{
    vector<double> data;

    do
    {
        header(htype);
        OPT_Col(c, columns, computability, htype);

        cin >> colNum;
        cin.clear();
        cin.ignore(128, '\n');

        if (colNum > 0 && colNum <= c && computability[colNum-1] == 1)
        {
            for (int i = 0; i < rows.size(); i++)
            {
                data.push_back(rows[i][colNum-1]);
            }
            break;
        }
        else { ERR_InvalidColumn(); }
    } while (true);

    return data;
}



// *******************************************************************
//	Col1
//
//  task:	       Prompt the user to enter the 1st column number
//                 Retrieve the respective column data
//  data in:	   c - number of columns
//                 columns - arrays of columns
//                 rows - arrays of row data
//                 computability - computability of certain column
//                 col1Num - column number 1 passed by reference
//                 col2Num - column number 2 passed by reference
//                 htype - type of header
//  data returned: array of retrieved column
//
// *******************************************************************

vector<double> Col1(int c, vector<string> columns, vector<vector<double>> rows, vector<int> computability, int &col1Num, int &col2Num, int htype)
{
    vector<double> data1;
    do
    {
        header(htype);
        OPT_Col(c, columns, computability, htype);

        cin >> col1Num;
        cin.clear();
        cin.ignore(128, '\n');

        if (col1Num > 0 && col1Num <= c && computability[col1Num-1] == 1)
        {
            for (int i = 0; i < rows.size(); i++)
            {
                data1.push_back(rows[i][col1Num-1]);
            }
            break;
        }
        else { ERR_InvalidColumn(); }

    } while (true);

    return data1;
}



// *******************************************************************
//	Col2
//
//  task:	       Prompt the user to enter the 2nd column number
//                 Retrieve the respective column data
//  data in:	   c - number of columns
//                 columns - arrays of columns
//                 rows - arrays of row data
//                 computability - computability of certain column
//                 col1Num - column number 1 passed by reference
//                 col2Num - column number 2 passed by reference
//                 htype - type of header
//  data returned: array of retrieved column
//
// *******************************************************************

vector<double> Col2(int c, vector<string> columns, vector<vector<double>> rows, vector<int> computability, int &col1Num, int &col2Num, int htype)
{
    vector<double> data2;

    do
    {
        header(htype);
        OPT_Col(c, columns, computability, htype, col1Num);

        cin >> col2Num;
        cin.clear();
        cin.ignore(128, '\n');

        if (col2Num > 0 && col2Num <= c && computability[col2Num-1] == 1 && col2Num != col1Num)
        {
            for (int i = 0; i < rows.size(); i++)
            {
                data2.push_back(rows[i][col2Num-1]);
            }
            break;
        }

        else { ERR_InvalidColumn(); }

    } while (true);

    return data2;
}



// *******************************************************************
//	twoCol
//
//  task:	       Prompt the user to enter 2 column numbers, and
//                 retrieve the respective column datas.
//  data in:	   c - number of columns
//                 columns - arrays of columns
//                 rows - arrays of row data
//                 computability - computability of certain column
//                 col1Num - column number 1 passed by reference
//                 col2Num - column number 2 passed by reference
//                 htype - type of header
//  data returned: array of an array of retrieved column
//
// *******************************************************************
vector<vector<double>> twoCol(int c, vector<string> columns, vector<vector<double>> rows, vector<int> computability, int &col1Num, int &col2Num, int htype)
{
    vector<vector<double>> data;

    vector<double> data1 = Col1(c, columns, rows, computability, col1Num, col2Num, htype);
    vector<double> data2 = Col2(c, columns, rows, computability, col1Num, col2Num, htype);

    data.push_back(data1);
    data.push_back(data2);

    return data;
}

// ***********************************************************************************************************
