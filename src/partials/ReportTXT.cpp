#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;



// Mohammed Emad, Muhammad Aiman, Srihari Naidu, Najmuddin
// =====================================================================================

// *******************************************************************
//	drawLine
//
//  task  :  Draws dash lines for the given length
// *******************************************************************

void drawLine(int length, fstream &file, int padding = 0)
{
    string line = "";
    for (int i = 0; i < length; i++)
        line += "-";

    file << line;

    for (int i = 0; i < padding; i++)
        file << '\n';
}

// Muhammed Aiman
// *******************************************************************
//	titleTXT
//
//  task:  Writes passed-in title to text file
// *******************************************************************

void titleTXT(string header, fstream &file, int padding = 0)
{
    for (int i = 0; i < padding; i++)
        file << '\n';

    file << header << '\n';
    drawLine(header.length(), file, 1);
}
// =====================================================================================




// =====================================================================================

// Srihari Naidu
// *******************************************************************
//	getComputablesTXT --> for Pearson's correlation
//
//  task:  Gets all the computable columns and their data
// *******************************************************************

void getComputablesTXT(int c, int r,
                    const vector<string> &columns,
                    const vector<vector<double>> &rows,
                    const vector<int> &computability,
                    vector<string> &computableColumns,
                    vector<int> &computableColumnsIndex,
                    vector<vector<double>> &columnsData)
{
    for (int i = 0; i < c; i++)
    {
        if (computability[i] == 1)
        {
            computableColumns.push_back(columns[i]);
            computableColumnsIndex.push_back(i);
        }
        vector<double> columnData;
        for (int j = 0; j < r; j++)
        {
            columnData.push_back(rows[j][i]);
        }
        columnsData.push_back(columnData);
    }
}


// Muhammed Aiman
// *******************************************************************
//	dataAnalysisTXT_BASIC
//
//  task:  Computes all basic stat. analysis and formats them in text
// *******************************************************************

void dataAnalysisTXT_BASIC(vector<double> data, fstream &file)
{
    file << '\n';

    file << "Minimum            : " << minimum(data)           << '\n';
    file << "Maximum            : " << maximum(data)           << '\n';
    file << "Median             : " << median(data)            << '\n';
    file << "Mean               : " << mean(data)              << '\n';
    file << "Variance           : " << variance(data)          << '\n';
    file << "Standard Deviation : " << standardDeviation(data) << '\n';
}


// Srihari Naidu
// *******************************************************************
//	dataAnalysisTXT_PearsonsCorrelation
//
//  task:  Computes Pearson's Correlation and formats them in txt
// *******************************************************************

void dataAnalysisTXT_PearsonsCorrelation(int c, int col,
                                      const vector<string> &columns,
                                      vector<vector<double>> &columnsData,
                                      const vector<int> &computability,
                                      vector<int> &computableColumnsIndex,
                                      fstream &file)
{
    int lastComputableIndex = computableColumnsIndex[computableColumnsIndex.size()-1];

    if (col < lastComputableIndex)
    {
        file << '\n';
        file << "Pearson's Correlation between Columns :" << '\n';
    }
    for (int i = col+1; i < c; i++)
    {
        if (computability[i] == 1)
        {
            vector<vector<double>> datas;
            datas.push_back(columnsData[col]);
            datas.push_back(columnsData[i]);

            file << "\t"
                 << columns[col] << " and " << columns[i]
                 << " : " << correlation(datas)<< '\n';
        }

    }
}


// Srihari Naidu
// *******************************************************************
//	dataAnalysisTXT_DistinctDataMember
//
//  task:  Finds the Distinct Data Members and formats them in text
// *******************************************************************

void dataAnalysisTXT_DistinctDataMember(vector<double> data, fstream &file)
{
    file << '\n';
    file << "Distinct Data Members :\n";

    vector<double> distinctData;
    vector<int> distinctDataCount;
    distinctDataMember(data, distinctData, distinctDataCount);

    file << "+---------------+-----------+" << '\n';
    file << "| Distinct Data | Frequency |" << '\n';
    file << "+---------------+-----------+" << '\n';

    for (int i = 0; i < distinctData.size(); i++)
    {
        file << "| "
             << setw(13) << distinctData[i]
             << " |";
        file << setw(10) << distinctDataCount[i]
             << " |";
        file << '\n';
    }

    file << "+---------------+-----------+" << '\n';
    file << '\n';
}


// Srihari Naidu
// *******************************************************************
//	dataAnalysisTXT_Histogram
//
//  task:  Outputs the histogram of a column in text mode
// *******************************************************************

void dataAnalysisTXT_Histogram(int col,
                               vector<double> data,
                               const vector<string> &columns,
                               fstream &file)
{
    file << "Histogram :\n\n";

    vector<double> values;
    vector<int> valueCount;
    distinctDataMember(data, values, valueCount);

    string column = columns[col];
    file << setw(5) << left << "Count" << "  ";
    file << setw(9) << right << column << endl;

    for (int i = 0; i < values.size(); i++)
    {
        file << setw(5) << right << valueCount[i] << "  ";
        file << setw(9) << right << values[i] << '|';

        for (int j = 0; j < valueCount[i]; j++)
        {
            file << '=';
        }
        file << '\n';
    }
    file << '\n';
}
// =====================================================================================




// =====================================================================================
// Muhammed Aiman
// *******************************************************************
//	dataHeaderTXT
//
//  task:  Writes passed-in data header to text file
// *******************************************************************

void dataHeaderTXT(string header, fstream &file, int padding = 0)
{
    drawLine(80, file , 1);

    for (int i = 0; i < padding; i++)
        file << '\n';

    file << header << '\n';
}

// Muhammed Aiman
// *******************************************************************
//	tLine --> dataTableTXT
//
//  task:  Draw table lines with respective column length
// *******************************************************************

void tLine(int c, const vector<string> &columns, fstream &file)
{
    file << '+';
    for (int col = 0; col < c; col++)
    {
        int colLen = 11; // base colLen
        if (columns[col].length() > colLen)
            colLen = columns[col].length();

        drawLine(colLen, file);
        file << '+';
    }
    file << '\n';
}

// Muhammed Aiman
// *******************************************************************
//	tHead --> dataTableTXT
//
//  task:  Write column titles in respective column length
// *******************************************************************

void tHead(int c, const vector<string> &columns, fstream &file)
{
    tLine(c, columns, file);
    file << '|';
    for (int col = 0; col < c; col++)
    {
        int colLen = 11;
        if (columns[col].length() > colLen)
            colLen = columns[col].length();

        string content = " " + columns[col] + " ";
        file << setw(colLen) << left << content;
        file << '|';
    }
    file << '\n';
    tLine(c, columns, file);
}

// Muhammed Aiman
// *******************************************************************
//	tBody --> dataTableTXT
//
//  task:  Write column data in respective column length
// *******************************************************************

void tBody(int c, int r,
            const vector<string> &columns,
            const vector<vector<double>> &rows,
            fstream &file)
{
    for (int row = 0; row < r; row++)
    {
        file << '|';
        for (int col = 0; col < c; col++)
        {
            int colLen = 11;
            if (columns[col].length() > colLen)
                colLen = columns[col].length();

            string content;
            stringstream ss;

            ss << rows[row][col];
            ss >> content;

            content = " " + content + " ";
            file << setw(colLen) << left << content;
            file << '|';
        }
        file << '\n';
    }
    tLine(c, columns, file);
}

// Muhammed Aiman
// *******************************************************************
//	dataTableTXT --> general
//
//  task:  Generates a TXT table for the data
// *******************************************************************

void dataTableTXT(int c, int r,
               const vector<string> &columns,
               const vector<vector<double>> &rows,
               fstream &file)
{
    dataHeaderTXT("Data", file, 1);

    tHead(c, columns, file);
    tBody(c, r, columns, rows, file);
}
// =====================================================================================




// =====================================================================================
// Najmuddin
// *******************************************************************
//	tLine_COL --> dataTableTXT_COL
//
//  task:  Draw table line with respective column length
// *******************************************************************

void tLine_COL(int col, const vector<string> &columns, fstream &file)
{
    file << '+';

    int colLen = 11;
    if (columns[col].length() > colLen)
        colLen = columns[col].length();

    drawLine(colLen, file);

    file << '+';
    file << '\n';
}

// Najmuddin
// *******************************************************************
//	tHead_COL --> dataTableTXT_COL
//
//  task:  Write column title in respective column length
// *******************************************************************

void tHead_COL(int col, const vector<string> &columns, fstream &file)
{
    tLine_COL(col, columns, file);
    file << '|';

    int colLen = 11;
    if (columns[col].length() > colLen)
        colLen = columns[col].length();

    string content = " " + columns[col] + " ";
    file << setw(colLen) << left << content;
    file << '|';

    file << '\n';
    tLine_COL(col, columns, file);
}

// Najmuddin
// *******************************************************************
//	tBody_COL --> dataTableTXT_COL
//
//  task:  Write column data in respective column length
// *******************************************************************

void tBody_COL(int col, int r,
            const vector<string> &columns,
            const vector<vector<double>> &rows,
            fstream &file)
{

    for (int row = 0; row < r; row++)
    {
        file << '|';

        int colLen = 11;
        if (columns[col].length() > colLen)
            colLen = columns[col].length();

        string content;
        stringstream ss;

        ss << rows[row][col];
        ss >> content;

        content = " " + content + " ";
        file << setw(colLen) << left << content;
        file << '|';

        file << '\n';
    }
    tLine_COL(col, columns, file);
}

// Najmuddin
// *******************************************************************
//	dataTableTXT_COL --> Column
//
//  task:  Generates a text formatted table with the given data and
//         simultaneously collects Column Data for computation
// *******************************************************************

void dataTableTXT_COL(int col, int r,
                      const vector<string> &columns,
                      const vector<vector<double>> &rows,
                      vector<double> &data, fstream &file)
{
    dataHeaderTXT("Column " + columns[col], file, 1);

    tHead_COL(col, columns, file);
    tBody_COL(col, r, columns, rows, file);

    for (int row = 0; row < r; row++)
        data.push_back(rows[row][col]);
}

// Najmuddin
// *******************************************************************
//	ReportTXT_COL
//
//  task:  Covers all column-related Report generation
// *******************************************************************

void ReportTXT_COL(int c, int r,
                   const vector<string> &columns,
                   const vector<vector<double>> &rows,
                   const vector<int> &computability,
                   vector<string> &computableColumns,
                   vector<int> &computableColumnsIndex,
                   vector<vector<double>> &columnsData,
                   fstream &file)
{
    titleTXT("Columns' Statistical Computation", file, 3);

    for (int col = 0; col < c; col++)
    {
        vector<double> data;

        if (computability[col] == 1)
        {
            dataTableTXT_COL(col, r, columns, rows, data, file);

            dataAnalysisTXT_BASIC(data, file);
            dataAnalysisTXT_PearsonsCorrelation(c, col, columns, columnsData, computability, computableColumnsIndex, file);
            dataAnalysisTXT_DistinctDataMember(data, file);
            dataAnalysisTXT_Histogram(col, data, columns, file);
        }
    }
}

// =====================================================================================




// =====================================================================================

// Mohammed Emad
// *******************************************************************
//	tLine_ROW --> dataTableTXT_ROW
//
//  task:  Draw table line with respective column length
// *******************************************************************

void tLine_ROW(int c,
               const vector<string> &columns,
               const vector<int> &computability,
               fstream &file)
{
    file << '+';
    for (int col = 0; col < c; col++)
    {
        if (computability[col] == 1)
        {
            int colLen = 11; // base colLen
            if (columns[col].length() > colLen)
                colLen = columns[col].length();

            drawLine(colLen, file);
            file << '+';
        }
    }
    file << '\n';
}


// Mohammed Emad
// *******************************************************************
//	tHead_ROW --> dataTableTXT_ROW
//
//  task:  Write column title in respective column length
// *******************************************************************

void tHead_ROW(int c,
               const vector<string> &columns,
               const vector<int> &computability,
               fstream &file)
{
    tLine(c, columns, file);
    file << '|';
    for (int col = 0; col < c; col++)
    {
        if (computability[col] == 1)
        {
            int colLen = 11;
            if (columns[col].length() > colLen)
                colLen = columns[col].length();

            string content = " " + columns[col] + " ";
            file << setw(colLen) << left << content;
            file << '|';
        }
    }
    file << '\n';
    tLine(c, columns, file);
}


// Mohammed Emad
// *******************************************************************
//	tBody_ROW --> dataTableTXT_ROW
//
//  task:  Write row data in respective column length
// *******************************************************************

void tBody_ROW(int row, int c, int r,
            const vector<string> &columns,
            const vector<int> &computability,
            const vector<vector<double>> &rows,
            fstream &file)
{

    file << '|';
    for (int col = 0; col < c; col++)
    {
        if (computability[col] == 1)
        {
            int colLen = 11;
            if (columns[col].length() > colLen)
                colLen = columns[col].length();

            string content;
            stringstream ss;

            ss << rows[row][col];
            ss >> content;

            content = " " + content + " ";
            file << setw(colLen) << left << content;
            file << '|';
        }
    }
    file << '\n';
    tLine(c, columns, file);
}


// Mohammed Emad
// *******************************************************************
//	dataTableTXT_ROW
//
//  task:  Generates a TXT table with the given data and
//         simultaneously collect Row Data for computation
// *******************************************************************

void dataTableTXT_ROW(int row, int c, int r,
                   const vector<string> &columns,
                   const vector<vector<double>> &rows,
                   const vector<int> &computability,
                   vector<double> &data, fstream &file)
{
    dataHeaderTXT("Row " + to_string(row+1), file, 1);

    tHead_ROW(c, columns, computability, file);
    tBody_ROW(row, c, r, columns, computability, rows, file);

    for (int col = 0; col < c; col++)
        if (computability[col] == 1)
            data.push_back(rows[row][col]);
}


// Mohammed Emad
// *******************************************************************
//	ReportTXT_ROW
//
//  task:  Covers all row-related Report generation
// *******************************************************************

void ReportTXT_ROW(int c, int r,
                    const vector<string> &columns,
                    const vector<vector<double>> &rows,
                    const vector<int> &computability,
                    fstream &file)
{
    file << "\n\n";
    titleTXT("Rows' Statistical Computation", file);

    for (int row = 0; row < r; row++)
    {
        vector<double> data;

        dataTableTXT_ROW(row,c, r, columns, rows, computability, data,file);

        dataAnalysisTXT_BASIC(data, file);
        dataAnalysisTXT_DistinctDataMember(data, file);
    }
}
// =====================================================================================




// =====================================================================================

// Srihari Naidu
// *******************************************************************
//	viewReportTXT
//
//  task:  Opens the browser to view the generated TXT Report.
// *******************************************************************

void viewReportTXT(User &user)
{
    STS_TXT_ReportGenerated();

    user.Log("Generated Text Report for " + user.Datafile() + '\n');

    string repFile = "report-" + user.Username() + ".txt";
    string command = "cd reports/ && explorer.exe " + repFile;
    system(command.c_str());
}
// =====================================================================================




// =========================================================================================================

// Mohammed Emad, Muhammad Aiman, Srihari Naidu, Najmuddin
// *******************************************************************
//	ReportTXT
//
//  task:  Main Text Report function blanketing all related functions
// *******************************************************************

void ReportTXT(User &user)
{
    int c, r;
    vector<int> computability;
    vector<string> columns;
    vector<vector<double>> rows;
    getData(c, r, computability, columns, rows, user.Datafile());

    vector<string> computableColumns;
    vector<int> computableColumnsIndex;
    vector<vector<double>> columnsData;
    getComputablesTXT(c, r, columns, rows, computability, computableColumns, computableColumnsIndex, columnsData);

    string reportFile = "reports/report-" + user.Username() + ".txt";
    fstream clearFile(reportFile, ios::out); // clear & reset file
    clearFile.close();
    fstream file(reportFile, ios::app);

    titleTXT(user.Username() + "'s Report", file);
    dataTableTXT(c, r, columns, rows ,file);
    ReportTXT_COL(c, r, columns, rows, computability, computableColumns, computableColumnsIndex, columnsData, file);
    ReportTXT_ROW(c, r, columns, rows, computability, file);
    viewReportTXT(user);
}
// =========================================================================================================