// Najmuddin
// *******************************************************************
//	getUserToDelete
//
//  task:	       Gets the name of the user to delete
//                 and checks to see if the user exists
//  data in:	   None
//  data returned: User object of the user to delete
//
// *******************************************************************

User getUserToDelete(User &user)
{
    string username;

    do
    {
        header("DELETE ACCT.");
        cout << "+--------------------------+ USERNAME +---------------------------+" <<"\n\n";
        cout << "Username (User to Delete)" << '\n';
        cout << "> ";
        getline(cin, username);

        User userToDelete(username);

        if (user.Username() == userToDelete.Username()) {
            ERR_DeleteYourself();
        }
        else if (userToDelete.exists()) {
            userToDelete = userToDelete.getUser(username);
            cout << "\n" << "+-----------------------------------------------------------------+" << "\n\n";
            cout << "Delete " << userToDelete.Username() << "'s account <ENTER> ";
            cin.ignore(128, '\n');

            return userToDelete;
        }
        else { ERR_UserDNE(); }

    } while (true);
}


// Najmuddin
// *******************************************************************
//	confirmDelete
//
//  task:	       Gets confirmation from the admin to delete
//                 the user
//  data in:	   User object of the user to delete
//  data returned: True if user inputs confirming character (y)
//                 False othwerwise
//
// *******************************************************************

bool confirmDelete(User userToDelete)
{
    char confirmation;

    do
    {
        header("DELETE ACCT.");
        cout << "+---------------------------+ DELETE +----------------------------+" <<"\n\n";

        cout << "This action is irreversible!" << "\n\n"
             << "Are you sure to proceed with deleting " << userToDelete.Username() << "'s account? (y/n)" << '\n'
             << "y - yes\nn - no" << "\n\n"
             << "> ";

        cin >> confirmation;
        confirmation = tolower(confirmation);

        if (confirmation == 'y') {
            return true;
        }
        else if (confirmation == 'n') {
            break;
        }
        else { ERR_InvalidSelection(); }

    } while (true);

    return false;
}


// Najmuddin
// *******************************************************************
//	DeleteUserAccount
//
//  task:	       Updates the user status in dete database to
//      	       deleted
//  data in:	   User object of the user to delete
//  data returned: None
//
// *******************************************************************

void DeleteUserAccount(User &user)
{
    User userToDelete = getUserToDelete(user);
    if (confirmDelete(userToDelete))
    {
        userToDelete.deactivate();
        cout << "\n" << "+-----------------------------------------------------------------+" << "\n\n";
        STS_UserDeleted();
    }
}
