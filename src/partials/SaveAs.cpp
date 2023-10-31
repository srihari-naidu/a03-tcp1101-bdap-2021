// Najmuddin
// *******************************************************************
//	getFileName
//
//  task:	       Prompts user to enter filename
//  data in:	   None
//  data returned: Validated filename entered by user
//
// *******************************************************************

void OPT_getFileName()
{
    cout << "+------------+ FILE NAME +-------------+" <<"\n\n";
    cout << "File name should"                         << '\n'
         << "-> NOT Contain invalid characters:"       << '\n'
         << "   \\ / : * ? \" < > |"                   << "\n\n";

    cout << "File Name" << '\n'
         << "> ";
}

string getFileName()
{
    string filename;

    do
    {
        header("SAVE AS");
        OPT_getFileName();

        getline(cin, filename);

        if (!filename.empty())
        {
            filename = trim(filename);
        }
        User user("", "", "", "", filename);

        if (user.filenameIsValid())
        {
            cout << "\n+--------------------------------------+\n\n";
            cout << "Save data file as " << lower(filename) << ".dat <ENTER> ";
            cin.ignore(128, '\n');
            break;
        }
        else { ERR_InvalidFilename(); }

    } while (true);

    return filename;
}


// Najmuddin
// *******************************************************************
//	SaveAs
//
//  task:	       Save data file with user chosen file name
//  data in:	   User object
//  data returned: None
//
// *******************************************************************
void SaveAs(User &user)
{
    string filename = getFileName();
    user.saveDataFileAs(filename);

    user.Log("Saved data file as " + filename + ".dat" + '\n');

    STS_FileSaved();
}