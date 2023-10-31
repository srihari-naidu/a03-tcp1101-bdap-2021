#include "../ReportHTML.cpp"
#include "../ReportTXT.cpp"


// Najmuddin
// *******************************************************************
//	Report
//
//  task:	       Menu for genrating reports
//
// *******************************************************************

void OPT_Report()
{
    cout << "+--------------------------------------+" << "\n\n"
         << " [1]  Generate Text Report. (.txt)"        << '\n'
         << " [2]  Generate HTML Report. (.html)"       << "\n\n"

         << " (b)  Back."                              << "\n\n"
         << "+--------------------------------------+" << "\n\n";

    cout << "Choice [12 b]" << '\n'
         << "> ";
}


void Report(User &user)
{
    do
    {
        header("REPORT");

        OPT_Report();

        char selection;
        cin >> selection;
        cin.ignore(128, '\n');

        switch (tolower(selection))
        {
            case '1': ReportTXT(user); break;
            case '2': ReportHTML(user); break;
            case 'b': return;

            default : ERR_InvalidSelection(); break;
        }

    } while (true);
}