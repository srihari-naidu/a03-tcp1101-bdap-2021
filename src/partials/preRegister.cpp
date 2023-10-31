#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;


// Mohammed EmadEldin
// *******************************************************************
//	getAdminUsername
//
//  task:	       Prompts admin to enter username
//  data in:	   None
//  data returned: Validated username entered by admin
//
// *******************************************************************

string getAdminUsername()
{
    string usernameToReg;
    do
    {
        header("REGISTER");
        cout << "+-----------------+ USERNAME +-----------------+" <<"\n\n";
        cout << "Admin Username" << endl;
        cout << "> ";
        getline(cin, usernameToReg);

        User user(usernameToReg);
        if (user.usernameIsValid())
        {
            cout << "\n+----------------------------------------------+\n\n";
            STS_UsernameSet(); break;
        }
        else if (!user.usernameIsValid())
        {
            if (user.Username().empty()) {
                ERR_UsernameEmpty();
            }
            else { ERR_InvalidUsername(); }
        }
    } while (true);
    return usernameToReg;
}


// Srihari Naidu
// *******************************************************************
//	getAdminPassword
//  task:	       Prompts admin to enter username
//  data in:	   None
//  data returned: Validated username entered by admin
//
// *******************************************************************

string getAdminPassword()
{
    string passwordToReg;
    do
    {
        header("REGISTER");
        cout << "+-----------------+ PASSWORD +-----------------+" <<"\n\n";
        cout << "Password should"            << "\n"
            << "-> Start with a letter"      << "\n"
            << "-> Contain a digit"          << "\n"
            << "-> Contain a capital letter" << "\n"
            << "-> Not contain spaces"       << "\n\n";

        cout << "Admin Password" << endl;
        cout << "> ";
        getline(cin, passwordToReg);

        User user("", passwordToReg);

        if (user.passwordIsValid())
        {
            cout << "\n+----------------------------------------------+\n\n";
            STS_PasswordSet(); break;
        }
        else { ERR_InvalidPassword(); }
    } while (true);

    return passwordToReg;
}


// Mohammed Emad
// *******************************************************************
//	reviewAdminInfo
//
//  task:	       Prompts user to enter username
//  data in:	   None
//  data returned: Validated username entered by user
//
// *******************************************************************

void reviewAdminInfo(User &adminReg)
{
    header("REGISTER");
    cout << "+---------------+ ACCOUNT INFO +---------------+" << "\n\n"
         << "Username: " << adminReg.Username() << '\n'
         << "Password: " << adminReg.Password() << '\n'
         << "    Type: " << adminReg.Type()     << "\n\n"
         << "+----------------------------------------------+" << "\n\n";

    cout << "Go Back <ENTER> ";
    cin.get();
}


// Srihari Naidu
// *******************************************************************
//	saveAdmin
//
//  task:	       Save admin in the database
//  data in:	   Username, Password & Usertype
//  data returned: None
//
// *******************************************************************

void saveAdmin(string username, string password, string type)
{
    fstream file;
    file.open(userDAT, ios::app);

    User adminReg(username, password, type, "active", "data.dat");
    file << adminReg.info();
    file << endl;

    file.close();

    reviewAdminInfo(adminReg);
}


// Srihari Naidu
// *******************************************************************
//	PreRegister
//
//  task:	       Comprise of all partial pre-register functions
//  data in:	   None
//  data returned: None
//
// *******************************************************************

void PreRegister()
{
    string usernameReg = getAdminUsername();
    string passwordReg = getAdminPassword();
    string typeReg = "admin";

    saveAdmin(usernameReg, passwordReg, typeReg);
}
