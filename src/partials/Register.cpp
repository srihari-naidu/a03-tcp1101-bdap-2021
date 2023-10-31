#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;


// Mohammed EmadEldin
// *******************************************************************
//	getUsername
//
//  task:	       Prompts user to enter username
//  data in:	   None
//  data returned: Validated username entered by user
//
// *******************************************************************

string getUsername()
{
    string usernameToReg;
    do
    {
        header("REGISTER");
        cout << "+-----------------+ USERNAME +-----------------+" <<"\n\n";
        cout << "Username" << '\n';
        cout << "> ";
        getline(cin, usernameToReg);

        User user(usernameToReg);
        if (!user.usernameTaken() && user.usernameIsValid())
        {
            cout << "\n+----------------------------------------------+\n\n";
            STS_UsernameSet(); break;
        }
        else if (user.usernameTaken()) {
            ERR_UsernameTaken();
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
//	getPassword
//
//  task:	       Prompts user to enter password
//  data in:	   None
//  data returned: Validated password entered by user
//
// *******************************************************************

string getPassword()
{
    string passwordToReg;
    do
    {
        header("REGISTER");
        cout << "+-----------------+ PASSWORD +-----------------+" <<"\n\n";
        cout << "Password should"                                  << "\n"
            << "-> Start with a letter"                            << "\n"
            << "-> Contain a digit"                                << "\n"
            << "-> Contain a capital letter"                       << "\n"
            << "-> Not contain spaces"                             << "\n\n";

        cout << "Password" << endl;
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


// Srihari Naidu
// *******************************************************************
//	getType
//
//  task:	       Prompts admin to select usertype
//  data in:	   None
//  data returned: Usertype selected by admin
//
// *******************************************************************

string getType()
{
    string typeToReg;
    do
    {
        header("REGISTER");
        cout << "+-----------------+ USERTYPE +-----------------+" << "\n\n"
            << "(1)  Admin"                                        << '\n'
            << "(2)  Buyer"                                        <<"\n\n";

        char typeSelect;
        cout << "Choice [12]" << endl;
        cout << "> ";
        cin >> typeSelect;
        cin.ignore(128, '\n');

        if (typeSelect == '1') {
            typeToReg = "admin"; break;
        }
        else if (typeSelect == '2') {
            typeToReg = "buyer"; break;
        }
        else { ERR_InvalidSelection(); }

    } while(true);

    cout << "\n+----------------------------------------------+\n\n";
    STS_UsertypeSet();

    return typeToReg;
}


// Mohammed EmadEldin
// *******************************************************************
//	reviewUserInfo
//
//  task:	       Prompts user to enter username
//  data in:	   None
//  data returned: Validated username entered by user
//
// *******************************************************************

void reviewUserInfo(User &userReg)
{
    header("REGISTER");
    cout << "+---------------+ ACCOUNT INFO +---------------+" << "\n\n"
         << "Username: " << userReg.Username() << '\n'
         << "Password: " << userReg.Password() << '\n'
         << "    Type: " << userReg.Type()     << "\n\n"
         << "+----------------------------------------------+" << "\n\n";

    cout << "Go Back <ENTER> ";
    cin.get();
}


// Srihari Naidu
// *******************************************************************
//	saveUser
//
//  task:	       Save user in the database
//  data in:	   Username, Password & Usertype
//  data returned: None
//
// *******************************************************************

void saveUser(string username, string password, string type)
{
    fstream file;
    file.open(userDAT, ios::app);

    User userReg(username, password, type, "active", "data.dat");
    file << userReg.info();
    file << endl;

    file.close();

    reviewUserInfo(userReg);
}


// Srihari Naidu
// *******************************************************************
//	Register
//
//  task:	       Comprise of all partial register functions
//  data in:	   None
//  data returned: None
//
// *******************************************************************

void Register()
{
    string usernameReg = getUsername();
    string passwordReg = getPassword();
    string typeReg = getType();
    saveUser(usernameReg, passwordReg, typeReg);
}
