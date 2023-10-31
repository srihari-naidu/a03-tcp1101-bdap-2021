#include "../Register.cpp"
#include "../SaveAs.cpp"
#include "manageAcct.cpp"
#include "statAnalysis.cpp"
#include "report.cpp"



// Srihari Naidu
// *******************************************************************
//	adminMenu
//
//  task:	       Main menu screen shown when the user logged in
//                 is an admin
//
// *******************************************************************

void OPT_adminMenu(User &user)
{
    string greet = "Welcome, " + user.Username();
    int padding = 17 + (greet.length() / 2);
    cout << '\n' << setw(padding) << greet << '\n';

    cout << "+--------------------------------+" << "\n\n"
         << " [1]  Register Account."            << '\n'
         << " [2]  Manage Account."              << "\n\n"

         << " (l)  Logout."                      << "\n\n"
         << "+--------------------------------+" << "\n\n";

    cout << "Choice [12 l]" << '\n'
         << "> ";
}

void adminMenu(User &user)
{
    do
    {
        header("ADMIN");
        OPT_adminMenu(user);

        char selection;
        cin >> selection;
        cin.ignore(128, '\n');

        switch (tolower(selection))
        {
            case '1': Register(); break;
            case '2': AccountManager(user); break;
            case 'l': STS_LoggingOut(); return;

            default: ERR_InvalidSelection(); break;
        }

    } while (true);
}


// Srihari Naidu
// *******************************************************************
//	userMenu
//
//  task:	       Main menu screen shown when the user logged in
//                 is a buyer
//  data in:	   User object passed by reference
//  data returned: None
//
// *******************************************************************

void OPT_userMenu(User &user)
{
    string greet = "Welcome, " + user.Username();
    int padding = 17 + (greet.length() / 2);
    cout << '\n' << setw(padding) << greet << '\n';

    cout << "+--------------------------------+" << "\n\n"
         << " [1]  Statistical Analysis."        << '\n'
         << " [2]  Save Data File."              << '\n'
         << " [3]  Report."                      << '\n'
         << " [4]  Manage Account."              << "\n\n"

         << " (l)  Logout."                      << "\n\n"
         << "+--------------------------------+" << "\n\n";

    cout << "Choice [1234 l]" << '\n'
         << "> ";
}

void userMenu(User &user)
{
    do
    {
        header("B.D.A.P");
        OPT_userMenu(user);

        char selection;
        cin >> selection;
        cin.ignore(128, '\n');

        switch (tolower(selection))
        {
            case '1': StatisticalAnalysis(user); break;
            case '2': SaveAs(user); break;
            case '3': Report(user); break;
            case '4': AccountManager(user); break;

            case 'l': STS_LoggingOut();
                      user.Log("Logged out\n");
                      return;

            default :  ERR_InvalidSelection(); break;
        }
    } while (true);
}


// Srihari Naidu
// *******************************************************************
//	Menu
//
//  task:	       Regulates which main menu screen should
//                 be shown based on the User type
//  data in:	   User object
//  data returned: None
//
// *******************************************************************

void Menu(User &user)
{
    if (user.isAdmin())
    {
        adminMenu(user);
    }
    else
    {
        userMenu(user);
    }
}