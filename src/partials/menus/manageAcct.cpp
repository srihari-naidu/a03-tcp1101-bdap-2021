#include "../changePassword.cpp"
#include "../deleteAccount.cpp"


// Muhammad Aiman & Najmuddin
// *******************************************************************
//	adminAccountManager
//
//  task:	       Account Manager screen shown when the user
//                 is an admin
//
// *******************************************************************

void OPT_adminAccountManager(User &user)
{
    cout << "+-------------------------------------------------------------------+" << "\n\n"
         << " [1]  Change Password (" << user.Username() << ")"                << "\n\n"

         << " [2]  Delete a User's Account."                                        << '\n'
         << " [3]  Change a User's Password."                                       << "\n\n"

         << " (b)  Back."                                                           << "\n\n"
         << "+-------------------------------------------------------------------+" << "\n\n";

    cout << "Choice [123 b]" << '\n'
         << "> ";
}

void adminAccountManager(User &user)
{
    do
    {
        header("MANAGE ACCT.");

        OPT_adminAccountManager(user);

        char selection;
        cin >> selection;
        cin.ignore(128, '\n');

        switch (tolower(selection))
        {
            case '1': ChangePassword(user); break;
            case '2': DeleteUserAccount(user); break;
            case '3': ChangeUserPassword(); break;
            case 'b': return;

            default : ERR_InvalidSelection(); break;
        }

    } while (true);
}



// *******************************************************************
//	userAccountManager
//
//  task:	       Account Manager screen shown when the user
//                 is a buyer
//  data in:	   User object passed by reference
//  data returned: None
//
// *******************************************************************

void OPT_userAccountManager(User &user)
{
    cout << "+-------------------------------------------------------------------+" << "\n\n"
         << " [1]  Change Password. (" << user.Username() <<")"                     << "\n\n"

         << " (b)  Back."                                                           << "\n\n"
         << "+-------------------------------------------------------------------+" << "\n\n";

    cout << "Choice [1 b]" << '\n'
         << "> ";
}

void userAccountManager(User &user)
{
    do
    {
        header("MANAGE ACCT.");

        OPT_userAccountManager(user);

        char selection;
        cin >> selection;
        cin.ignore(128, '\n');

        switch (tolower(selection))
        {
            case '1': ChangePassword(user); break;
            case 'b': return;

            default : ERR_InvalidSelection(); break;
        }
    } while (true);
}



// *******************************************************************
//	AccountManager
//
//  task:	       Regulates which account manager screen should
//                 be shown based on the User type
//  data in:	   User object
//  data returned: None
//
// *******************************************************************

void AccountManager(User &user)
{
    if (user.isAdmin())
    {
        adminAccountManager(user);
    }
    else
    {
        userAccountManager(user);
    }
}