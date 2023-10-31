#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

#include "menus/mainMenu.cpp"

using namespace std;


// Mohammed Emad
// *******************************************************************
//	getUsernameAtt
//
//  task:	       Prompts user to enter username during login
//  data in:	   None
//  data returned: Username attempt
//
// *******************************************************************

string getUsernameAtt()
{
    header("LOGIN");
    cout << "+---------+ USERNAME +---------+"
         << "\n\n";

    string usernameAttempt;
    cout << "Username" << endl;
    cout << "> ";
    cin >> usernameAttempt;
    cin.ignore(128, '\n');

    cout << "\n\n";

    return usernameAttempt;
}


// Mohammed Emad
// *******************************************************************
//	getPasswordAtt
//
//  task:	       Prompts user to enter password during login
//  data in:	   None
//  data returned: Password attempt
//
// *******************************************************************

string getPasswordAtt()
{
    cout << "+---------+ PASSWORD +---------+"
         << "\n\n";

    string passwordAttempt;
    cout << "Password" << endl;
    cout << "> ";
    cin >> passwordAttempt;
    cin.ignore(128, '\n');

    return passwordAttempt;
}


// Srihari Naidu
// *******************************************************************
//	loginValid
//
//  task:	       Checks and validates the login attempt by the user
//  data in:	   Username, Password, User object
//  data returned: True if username and password mathces
//                 and the user active (not deleted)
//                 False otherwise
//
// *******************************************************************

bool loginValid(string username, string password, User &user)
{
    string fusername, fpassword, ftype, fstatus, fdatafile;
    bool matchUserPass;

    fstream file;
    file.open(userDAT, ios::in);

    while (file >> fusername >> fpassword >> ftype >> fstatus >> fdatafile)
    {
        User fUser(fusername, fpassword, ftype, fstatus, fdatafile);

        matchUserPass = (
            (fUser.Username() == username) &&
            (fUser.Password() == password) &&
            (fUser.isActive())
        );

        if (matchUserPass) {
            file.close();
            user = fUser;
            return true;
        }
    }
    file.close();
    return false;
}


// Srihari Naidu
// *******************************************************************
//	loginUser
//
//  task:	       Sends user to the main menu if the login is valid,
//                 else the user has to re-attempt the login
//  data in:	   Username, Password
//  data returned: None
//
// *******************************************************************

void loginUser(string username, string password)
{
    User user(username, password);

    if(loginValid(username, password, user)) {
        STS_LoggingIn();

        user.Log(getChrono(),0);
        user.Log("Logged in\n");

        Menu(user);
    }
    else {
        cout << '\n';
        ERR_InvalidCredentials();

        string usernameAtt = getUsernameAtt();
        string passwordAtt = getPasswordAtt();

        loginUser(usernameAtt, passwordAtt);
    }
}


// Mohammed Emad
// *******************************************************************
//	Login
//
//  task:	       Main login function comprising all all partial
//                 login functions
//  data in:	   None
//  data returned: None
//
// *******************************************************************

void Login()
{
    string usernameAtt = getUsernameAtt();
    string passwordAtt = getPasswordAtt();

    loginUser(usernameAtt, passwordAtt);
}