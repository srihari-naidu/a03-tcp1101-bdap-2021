#include "../Login.cpp"
#include "../preRegister.cpp"
#include "../utils/file.cpp"


// Srihari Naidu
// *******************************************************************
//	preWelcome
//
//  task:	       Welcome screen when there are no registered
//                 registered accounts
//  data in:	   selection variable passed-by-reference
//  data returned: selection
//
// *******************************************************************

char preWelcome(char &selection)
{
    cout << "+----------------------------------------------+" << "\n\n"
         << " [1]  Register Admin."                            << "\n\n"
         << " (q)  Quit."                                      << "\n\n"
         << "+----------------------------------------------+" << "\n\n";

    cout << "Choice [1 q]" << '\n'
         << "> ";
    cin >> selection;
    cin.ignore(128, '\n');

    return selection;
}


// Srihari Naidu
// *******************************************************************
//	postWelcome
//
//  task:	       Welcome screen when there's at least one user
//                 registered accounts
//  data in:	   selection variable passed-by-reference
//  data returned: selection
//
// *******************************************************************

char postWelcome(char &selection)
{
    cout << "+----------------------------------------------+" << "\n\n"
         << " [1]  Login"                                      << "\n\n"
         << " (q)  Quit."                                      << "\n\n"
         << "+----------------------------------------------+" << "\n\n";

    cout << "Choice [1 q]" << '\n'
         << "> ";
    cin >> selection;
    cin.ignore(128, '\n');

    return selection;
}


// Srihari Naidu
// *******************************************************************
//	Welcome
//
//  task:	       Regulates which Welcome screen/options should
//                 be shown at the start of the program
//  data in:	   None
//  data returned: None
//
// *******************************************************************

void Welcome()
{
    do
    {
        header("WELCOME");

        bool empty = fileIsEmpty(userDAT);
        char selection;

        if (empty) {                    // there are no accounts (first time)
            preWelcome(selection);
        }
        else {                          // there's are accounts
            postWelcome(selection);
        }

        if (!empty && selection == '1') {        // postWelcome opt
            Login();
        }
        else if (empty && selection == '1') {    // preWelcome opt
            PreRegister();
        }
        else if (tolower(selection) == 'q') {
            STS_Quit();
            break;
        }
        else { ERR_InvalidSelection(); }

    } while (true);
}
