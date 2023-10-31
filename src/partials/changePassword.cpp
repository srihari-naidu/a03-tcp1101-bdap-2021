// Muhammad Aiman
// *******************************************************************
//	getUserToCP
//
//  task:	       Gets the name of the user to change password
//                 and checks to see if the user exists
//  data in:	   None
//  data returned: User object of the user to change password
//
// *******************************************************************

User getUserToCP()
{
    string username;

    do
    {
        header("CHANGE PASS.");
        cout << "+-------------------------+ USERNAME +--------------------------+" <<"\n\n";
        cout << "Username (User to Change Password)" << endl;
        cout << "> ";
        getline(cin, username);

        User userToCP(username);

        if (userToCP.exists())
        {
            userToCP = userToCP.getUser(username);
            cout << '\n';
            cout << "+---------------------------------------------------------------+" << "\n\n";
            cout << "Set New Password for " << userToCP.Username() << " <ENTER> ";
            cin.ignore(128, '\n');
            return userToCP;
        }
        else { ERR_UserDNE(); }

    } while (true);
}


// Muhammad Aiman
// *******************************************************************
//	getNewPassword
//
//  task:	       Prompts user to enter a new password
//  data in:	   User object of the user to change password
//  data returned: Validated new password entered by user
//
// *******************************************************************

void OPT_getNewPassword()
{
    cout << "+-----------------------+ NEW PASSWORD +------------------------+" <<"\n\n";
    cout << "Password should"                                                   << "\n"
         << "-> Start with a letter"                                            << "\n"
         << "-> Contain a digit"                                                << "\n"
         << "-> Contain a capital letter"                                       << "\n"
         << "-> Not contain spaces"                                             << "\n\n";

    cout << "New Password" << '\n'
         << "> ";
}

string getNewPassword(User userToCP)
{
    string newPassword;

    do
    {
        header("CHANGE PASS.");
        OPT_getNewPassword();

        getline(cin, newPassword);
        User user("", newPassword);

        if (user.passwordIsValid()) {
            cout << '\n';
            cout << "+---------------------------------------------------------------+" << "\n\n";
            cout << "Change password for the user, " << userToCP.Username() << " <ENTER> ";
            cin.ignore(128, '\n');
            break;
        }
        else { ERR_InvalidPassword(); }

    } while (true);

    return newPassword;
}


// Muhammad Aiman
// *******************************************************************
//	ChangePassword
//
//  task:	       Change password for the user themself
//  data in:	   User object
//  data returned: None
//
// *******************************************************************

void ChangePassword(User &user)
{
    string newPass = getNewPassword(user);
    user.changePassword(newPass);

    STS_PasswordChanged();

    user.Log("Changed password\n");
}



// Muhammad Aiman
// *******************************************************************
//	ChangeUserPassword
//
//  task:	       Change password for another user (by admin)
//  data in:	   None
//  data returned: None
//
// *******************************************************************

void ChangeUserPassword()
{
    User userToCP = getUserToCP();
    string newPass = getNewPassword(userToCP);

    userToCP.changePassword(newPass);
    STS_PasswordChanged();
}
