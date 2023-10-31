#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;



// Mohammed Emad, Muhammad Aiman, Srihari Naidu, Najmuddin
// =====================================================================================

// *******************************************************************
//	preHTML, Style, preBody, Title             : Partial of initHTML
//  bodySTYLE, tableSTYLE, tablePartStyle      : Partial of Style
// *******************************************************************

void preHTML(fstream &file)
{
    file << "<!DOCTYPE html>\n";
    file << "<html>\n";
    file << "<head>\n";
}

void bodySTYLE(fstream &file)
{
    file << "\tbody\n";
    file << "\t{\n";
    file << "\t\tfont-family: 'Segoe UI', Tahoma, Geneva, Verdana, sans-serif;\n";
    file << "\t\tbackground-color: #F8F9FD;\n";
    file << "\t\tpadding: 50px 500px;\n";
    file << "\t}\n";

    file << "\thr\n";
    file << "\t{\n";
    file << "\t\theight: 3px;\n";
    file << "\t\tborder-width: 0;\n";
    file << "\t\tmargin-top: 50px;\n";
    file << "\t\tmargin-bottom: 50px;\n";
    file << "\t\tcolor: gray;\n";
    file << "\t\tbackground-color: gray;\n";
    file << "\t}\n";

    file << "\tpre\n";
    file << "\t{\n";
    file << "\t\tfont-family: monospace;\n";
    file << "\t}\n";
}

void tableSTYLE(fstream &file)
{
    file << "\ttable\n";
    file << "\t{\n";
    file << "\t\twidth: 100%;\n";
    file << "\t\tcolor: #212529;\n";
    file << "\t\tbackground-color: #ffffff;\n";
    file << "\t\tborder-collapse: collapse;\n";
    file << "\t\tborder-width: 1px;\n";
    file << "\t}\n";
}

void tablePartSTYLE(fstream &file)
{
    file << "\ttd, th\n";
    file << "\t{\n";
    file << "\t\ttext-align: center;\n";
    file << "\t\tborder-width: 1px;\n";
    file << "\t\tborder-style: solid;\n";
    file << "\t\tpadding: 15px;\n";
    file << "\t}\n";

    file << "\tth\n";
    file << "\t{\n";
    file << "\t\tfont-size: 17px;\n";
    file << "\t\tcolor: #ffffff;\n";
    file << "\t\tborder-color: #4d4d4d;\n";
    file << "\t\tbackground-color: #343A40;\n";
    file << "\t}\n";

    file << "\ttd\n";
    file << "\t{\n";
    file << "\t\tfont-weight: 500;\n";
    file << "\t\tborder-color: #F2F2F2;\n";
    file << "\t}\n";
}

void Style(fstream &file)
{
    file << "<style>\n";

    bodySTYLE(file);
    tableSTYLE(file);
    tablePartSTYLE(file);

    file << "</style>\n";
}

void preBody(fstream &file)
{
    file << "</head>\n";
    file << "<body>";
}

void ReportTitle(string name, fstream &file)
{
    string title = "<h1 style=\"text-align:center\">" + name + "'s Report" + "</h1>\n";
    file << title;
}

void Title(string title, fstream &file)
{
    title = "<h1 style=\"text-align:center; margin-top:100px\">" + title + "</h1>\n";
    file << title;
}
// =====================================================================================




// =====================================================================================

// Muhammad Aiman
// *******************************************************************
//	initHTML
//
//  task:  Writes HTML codes preceeding the Report
// *******************************************************************

void initHTML(User &user, fstream &file)
{
    preHTML(file);
    Style(file);
    preBody(file);
    ReportTitle(user.Username(), file);
}


// Muhammad Aiman
// *******************************************************************
//	endHTML
//
//  task:  Writes HTML codes following the Report
// *******************************************************************

void endHTML(fstream &file)
{
    file << "</body>\n";
    file << "</html>";
    file.close();
}
// =====================================================================================




// =====================================================================================

// Srihari Naidu
// *******************************************************************
//	getComputables --> for Pearson's correlation
//
//  task:  Gets all the computable columns and their data
// *******************************************************************

void getComputables(int c, int r,
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

// Muhammad Aiman
// *******************************************************************
//	dataAnalysis_BASIC
//
//  task:  Computes all basic stat. analysis and formats them in HTML
// *******************************************************************

void dataAnalysis_BASIC(vector<double> data, fstream &file)
{
    file << "<br />\n";
    file << "<p><b>Minimum : </b>" << minimum(data) << "</p>\n";
    file << "<p><b>Maximum : </b>" << maximum(data) << "</p>\n";
    file << "<p><b>Median : </b>" << median(data) << "</p>\n";
    file << "<p><b>Mean : </b>" << mean(data) << "</p>\n";
    file << "<p><b>Variance : </b>" << variance(data) << "</p>\n";
    file << "<p><b>Standard Deviation : </b>" << standardDeviation(data) << "</p>\n";
}


// Srihari Naidu
// *******************************************************************
//	dataAnalysis_PearsonsCorrelation
//
//  task:  Computes Pearson's Correlation and formats them in HTML
// *******************************************************************

void dataAnalysis_PearsonsCorrelation(int c, int col,
                                      const vector<string> &columns,
                                      vector<vector<double>> &columnsData,
                                      const vector<int> &computability,
                                      vector<int> &computableColumnsIndex,
                                      fstream &file)
{
    int lastComputableIndex = computableColumnsIndex[computableColumnsIndex.size()-1];

    if (col < lastComputableIndex)
    {
        file << "<br />\n";
        file << "<p><b>Pearson's Correlation between Columns : </b></p>\n";
    }
    for (int i = col+1; i < c; i++)
    {
        if (computability[i] == 1)
        {
            vector<vector<double>> datas;
            datas.push_back(columnsData[col]);
            datas.push_back(columnsData[i]);

            file << "<p style=\"margin-left: 40px\"><b>"
                 << columns[col] << " and " << columns[i]
                 << " : </b>" << correlation(datas) <<"</p>\n";
        }

    }
}


// Srihari Naidu
// *******************************************************************
//	dataAnalysis_DistinctDataMember
//
//  task:  Finds the Distinct Data Members and formats them in HTML
// *******************************************************************

void dataAnalysis_DistinctDataMember(vector<double> data, fstream &file)
{
    file << "<br />\n";
    file << "<p><b>Distinct Data Members : </b></p>\n";

    vector<double> distinctData;
    vector<int> distinctDataCount;
    distinctDataMember(data, distinctData, distinctDataCount);

    file << "<table style=\"width:30%\">\n";
    file << "\t<thead>\n";
    file << "\t\t<tr>\n";
    file << "\t\t\t<th style=\"padding:10px\">" << "Distinct Data" << "</th>\n";
    file << "\t\t\t<th style=\"padding:10px\">" << "Count" << "</th>\n";
    file << "\t\t</tr>\n";
    file << "\t</thead>\n";

    file << "\t<tbody>\n";
    for (int i = 0; i < distinctData.size(); i++)
    {
        file << "\t\t<tr>\n";
        file << "\t\t\t<td style=\"padding:10px\">" << distinctData[i] << "</td>\n";
        file << "\t\t\t<td style=\"padding:10px\">" << distinctDataCount[i] << "</td>\n";
        file << "\t\t</tr>\n";
    }
    file << "\t</tbody>\n";
    file << "</table>\n";

    file << "<br />\n";
}


// Srihari Naidu
// *******************************************************************
//	dataAnalysis_Histogram
//
//  task:  Outputs the histogram of a column in HTML
// *******************************************************************

void Histogram_cont(int valueCount, int value, fstream &file);

void dataAnalysis_Histogram(int col,
                               vector<double> data,
                               const vector<string> &columns,
                               fstream &file)
{
    file << "<br />\n";
    file << "<p><b>Histogram : </b></p>\n";

    vector<double> values;
    vector<int> valueCount;
    distinctDataMember(data, values, valueCount);
    string column = columns[col];

    file << "<pre><b>Count  |";

    int spaceCol = 9 - column.length();
    for (int s = 0; s < spaceCol; s++)
        file << " ";

    file << column << "</b></pre>\n";

    for (int i = 0; i < values.size(); i++)
    {
        Histogram_cont(valueCount[i], values[i], file);
    }
    file << '\n';
}


void Histogram_cont(int valueCount, int value, fstream &file)
{
    file << "<pre>" << valueCount;

    int spaceCount = 7 - to_string(valueCount).length();
    for (int s = 0; s < spaceCount; s++)
        file << " ";

    file << '|';

    for (int s = 0; s < spaceCount; s++)
        file << " ";
    file << value << "|";

    string plot = "";
    for (int j = 0; j < valueCount; j++)
        plot += '=';

    file << plot << "</pre>\n";

    file << '\n';
}
// =====================================================================================



// =====================================================================================

// Najmuddin
// *******************************************************************
//	dataHeader
//
//  task:  Writes HTML code to show the general Data Title
// *******************************************************************

void dataHeader(string header, fstream &file)
{
    header = "<h2>" + header + "</h2>\n";

    file << "<hr>\n";
    file << header;
}


// Najmuddin
// *******************************************************************
//	dataTable
//
//  task:  Generates a HTML table for the whole data
// *******************************************************************

void dataTable(int c, int r,
               const vector<string> &columns,
               const vector<vector<double>> &rows,
               const vector<int> &computability,
               fstream &file)
    {
    dataHeader("Data", file);
    file << "<table>\n";

    file << "\t<thead>\n";
    file << "\t\t<tr>\n";
    for (int col = 0; col < c; col++)
        file << "\t\t\t<th>" << columns[col] << "</th>\n";
    file << "\t\t</tr>\n";
    file << "\t</thead>\n";

    file << "\t<tbody>\n";
    for (int row = 0; row < r; row++)
    {
        file << "\t\t<tr>\n";
        for (int col = 0; col < c; col++)
        {
            if (computability[col] != 1)
                file << "\t\t\t<td style=\"background-color:#EEEEEE\">" << rows[row][col] << "</td>\n";
            else
                file << "\t\t\t<td>" << rows[row][col] << "</td>\n";
        }
        file << "\t\t</tr>\n";
    }
    file << "\t</tbody>\n";

    file << "</table>\n";
}
// =====================================================================================



// =====================================================================================

// Mohammed Emad
// *******************************************************************
//	dataHeader_COL
//
//  task:  Writes HTML code to show the Column Title
// *******************************************************************

void dataHeader_COL(string header, fstream &file)
{
    header = "<h2>" + header + " Column" + "</h2>\n";

    file << "<hr>\n";
    file << header;
}

// Mohammed Emad
// *******************************************************************
//	dataTable_COL
//
//  task:  Generates a HTML table with the given data and
//         simultaneously collect Column Data for computation
// *******************************************************************

void dataTable_COL(int col, int r,
                   const vector<string> &columns,
                   const vector<vector<double>> &rows,
                   vector<double> &data, fstream &file)
{
    file << "<table>\n";
    file << "\t<thead>\n";
    file << "\t\t<tr>\n";
    file << "\t\t\t<th>" << columns[col] << "</th>\n";
    file << "\t\t</tr>\n";
    file << "\t</thead>\n";

    file << "\t<tbody>\n";
    for (int row = 0; row < r; row++)
    {
        file << "\t\t<tr>\n";
        file << "\t\t\t<td>" << rows[row][col] << "</td>\n";
        file << "\t\t</tr>\n";

        data.push_back(rows[row][col]);
    }
    file << "\t</tbody>\n";
    file << "</table>\n";
}


// Mohammed Emad
// *******************************************************************
//	ReportHTML_COL
//
//  task:  Covers all column-related Report generation
// *******************************************************************

void ReportHTML_COL(int c, int r,
                    const vector<string> &columns,
                    const vector<vector<double>> &rows,
                    const vector<int> &computability,
                    vector<string> &computableColumns,
                    vector<int> &computableColumnsIndex,
                    vector<vector<double>> &columnsData,
                    fstream &file)
{
    Title("Columns' Statistical Computation", file);
    for (int col = 0; col < c; col++)
    {
        vector<double> data;

        if (computability[col] == 1)
        {
            dataHeader_COL(columns[col], file);
            dataTable_COL(col, r, columns, rows, data, file);

            dataAnalysis_BASIC(data, file);
            dataAnalysis_PearsonsCorrelation(c, col, columns, columnsData, computability, computableColumnsIndex, file);
            dataAnalysis_DistinctDataMember(data, file);
            dataAnalysis_Histogram(col, data, columns, file);
        }
    }
}

// =====================================================================================




// =====================================================================================

// Mohammed Emad
// *******************************************************************
//	dataHeader_ROW
//
//  task:	       Writes HTML code to show the Row Number
// *******************************************************************

void dataHeader_ROW(int row, fstream &file)
{
    string header = "<h2>Row " + to_string(row+1) + "</h2>\n";

    file << "<hr>\n";
    file << header;
}

// Mohammed Emad
// *******************************************************************
//	dataTable_ROW
//
//  task:  Generates a HTML table with the given data and
//         simultaneously collect Row Data for computation
// *******************************************************************

void dataTable_ROW(int row, int c, int r,
                   const vector<string> &columns,
                   const vector<vector<double>> &rows,
                   const vector<int> &computability,
                   vector<double> &data, fstream &file)
{
    file << "<table>\n";

    file << "\t<thead>\n";
    file << "\t\t<tr>\n";
    for (int col = 0; col < c; col++)
    {
        if (computability[col] == 1)
        {
            file << "\t\t\t<th>" << columns[col] << "</th>\n";
            data.push_back(rows[row][col]);
        }
    }
    file << "\t\t</tr>\n";
    file << "\t</thead>\n";

    file << "\t<tbody>\n";
    file << "\t\t<tr>\n";
    for (int col = 0; col < c; col++)
    {
        if (computability[col] == 1)
        {
            file << "\t\t\t<td>" << rows[row][col] << "</td>\n";
        }
    }
    file << "\t\t</tr>\n";
    file << "\t</tbody>\n";

    file << "</table>\n";
}


// Mohammed Emad
// *******************************************************************
//	ReportHTML_ROW
//
//  task:  Covers all row-related Report generation
// *******************************************************************

void ReportHTML_ROW(int c, int r,
                    const vector<string> &columns,
                    const vector<vector<double>> &rows,
                    const vector<int> &computability,
                    fstream &file)
{
    Title("Rows' Statistical Computation", file);
    for (int row = 0; row < r; row++)
    {
        vector<double> data;

        dataHeader_ROW(row, file);
        dataTable_ROW(row,c, r, columns, rows, computability, data, file);

        dataAnalysis_BASIC(data, file);
        dataAnalysis_DistinctDataMember(data, file);
    }
}
// =====================================================================================




// =====================================================================================

// Srihari Naidu
// *******************************************************************
//	viewReportHTML
//
//  task:  Opens the browser to view the generated HTML Report.
// *******************************************************************

void viewReportHTML(User &user)
{
    STS_HTML_ReportGenerated();

    user.Log("Generated HTML Report for " + user.Datafile() + '\n');

    string repFile = "report-" + user.Username() + ".html";

    // WSL command
    string command = "cd reports/ && explorer.exe " + repFile;

    // Brave command
    // string command = "cd reports/ && brave(" + repFile + ")";

    system(command.c_str());
}
// =====================================================================================



// =========================================================================================================

// Mohammed Emad, Muhammad Aiman, Srihari Naidu, Najmuddin
// *******************************************************************
//	ReportHTML
//
//  task:  Main HTML Report function blanketing all related functions
// *******************************************************************

void ReportHTML(User &user)
{
    int c, r;
    vector<int> computability;
    vector<string> columns;
    vector<vector<double>> rows;
    getData(c, r, computability, columns, rows, user.Datafile());

    vector<string> computableColumns;
    vector<int> computableColumnsIndex;
    vector<vector<double>> columnsData;
    getComputables(c, r, columns, rows, computability, computableColumns, computableColumnsIndex, columnsData);

    string reportFile = "reports/report-" + user.Username() + ".html";
    fstream clearFile(reportFile, ios::out); // clear & reset file
    clearFile.close();
    fstream file(reportFile, ios::app);

    initHTML(user, file);
    dataTable(c, r, columns, rows, computability, file);
    ReportHTML_COL(c, r, columns, rows, computability, computableColumns, computableColumnsIndex, columnsData, file);
    ReportHTML_ROW(c, r, columns, rows, computability, file);

    endHTML(file);

    viewReportHTML(user);
}
// =========================================================================================================