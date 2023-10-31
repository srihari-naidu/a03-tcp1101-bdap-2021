#include <iostream>
#include <cstdio>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

#include "../utils/modstring.cpp"
#include "../utils/time.cpp"


const string userDAT = ".dat/user.dat";

using namespace std;


// Srihari Naidu
// *******************************************************************
//	User
//
//  task:	       User class acts as a user datatype which contains
//                 user information and all such functions that
//                 aids in the flow of the program
//
// *******************************************************************

class User
{
private:
    string username;
    string password;
    string type;
    string status;
    string datafile;

public:
    // Srihari Naidu
    // *******************************************************************
    //	User
    //
    //  task:	       User class constructors
    //  data in:	   Username
    //                 Username + Password
    //                 Username + Password + Type + Status
    //  data returned: User object
    //
    // *******************************************************************

    User(string u)
    {
        username = u;
    }

    User(string u, string p)
    {
        username = u;
        password = p;
    }

    User(string u, string p, string t, string s)
    {
        username = u;
        password = p;
            type = t;
          status = s;
    }

    User(string u, string p, string t, string s, string d)
    {
        username = u;
        password = p;
            type = t;
          status = s;
        datafile = d;
    }


    // Srihari Naidu
    // *******************************************************************
    //	Getters
    //
    //  task:	       Get's the specified data of the User
    //  data in:	   User object
    //  data returned: Specified data of the User
    //
    // *******************************************************************

    string Username() const { return username; }
    string Password() const { return password; }
    string Type() const { return type; }
    string Datafile() const { return datafile; }


    string info() {
        return username + " " + password + " " + type + " " + status + " " + datafile;
    }


    // Srihari Naidu
    // *******************************************************************
    //	isAdmin
    //
    //  task:	       Checks if User type is admin
    //  data in:	   User object
    //  data returned: True if user is admin | False otherwise
    //
    // *******************************************************************

    bool isAdmin() {
        return type == "admin";
    }


    // Srihari Naidu
    // *******************************************************************
    //	isAdmin
    //
    //  task:	       Checks if User staus is active
    //  data in:	   User object
    //  data returned: True is user is active | False otherwise
    //
    // *******************************************************************

    bool isActive() {
        return (status == "active");
    }



    // *******************************************************************
    //	exists
    //
    //  task:	       Checks if user exists and is active in the database
    //  data in:	   User object
    //  data returned: True if user exisits | False otherwise
    //
    // *******************************************************************

    bool exists()
    {
        string fusername, fpassword, ftype, fstatus, fdatafile;
        string fuserData;
        stringstream ss;

        fstream file;

        file.open(userDAT, ios::in);
        while(!file.eof())
        {
            getline(file, fuserData);
            stringstream(fuserData) >> fusername >> fpassword >> ftype >> fstatus >> fdatafile;

            if (lower(username) == lower(fusername) && fstatus == "active")
            {
                return true;
            }
        }
        file.close();

        return false;
    }



    // *******************************************************************
    //	getUser
    //
    //  task:	       Finds and returns User object of a user based
    //                 on the username passed in
    //  data in:	   Username
    //  data returned: User object
    //
    // *******************************************************************

    User getUser(string username)
    {
        User user("");
        string fusername, fpassword, ftype, fstatus, fdatafile;

        fstream file;

        file.open(userDAT, ios::in);
        while (file >> fusername >> fpassword >> ftype >> fstatus >> fdatafile)
        {
            User fUser(fusername, fpassword, ftype, fstatus, fdatafile);
            if (lower(username) == lower(fusername) && fstatus == "active")
            {
                user = fUser;
                file.close();
            }
        }
        file.close();

        return user;
    }



    // *******************************************************************
    //	usernameTaken
    //
    //  task:	       Finds the passed-in username in the database
    //                 and returns true or false based on whether
    //                 that username exists
    //  data in:	   User object
    //  data returned: True if username exists in the database
    //                 False otherwise
    //
    // *******************************************************************

    bool usernameTaken()
    {
        string fusername;
        string fuserData;
        stringstream ss;

        fstream file;

        file.open(userDAT, ios::in);
        while(!file.eof())
        {
            getline(file, fuserData);
            stringstream(fuserData) >> fusername;

            if (lower(username) == lower(fusername))
            {
                return true;
            }
        }
        file.close();

        return false;
    }



    // *******************************************************************
    //	usernameIsValid
    //
    //  task:	       Validates to see if username conforms to the
    //                 conditions of a proper username
    //  data in:	   User object
    //  data returned: True if username is not empty and has no spaces
    //                 False otherwise
    //
    // *******************************************************************

    bool usernameIsValid()
    {
        if (username.empty())
            return false;

        for (auto ch : username)
            if (isspace(ch))
                return false;

        return true;
    }


    // Srihari Naidu
    // *******************************************************************
    //	passwordIsValid
    //
    //  task:	       Validates to see if password conforms to the
    //                 requirements of a password
    //  data in:	   User object
    //  data returned: True if password is not empty, has no spaces,
    //                 starts with an alphabet, has a digit and uppercase
    //                 False otherwise
    //
    // *******************************************************************

    bool passwordIsValid()
    {
        if (password.empty())
            return false;

        bool fstAlpha = false;
        bool hasDigit = false;
        bool hasUpper = false;
        bool noSpace = true;

        fstAlpha = isalpha(password[0]);

        for (auto ch : password)
            if (isdigit(ch))
                hasDigit = true;

        for (auto ch : password)
            if (isupper(ch))
                hasUpper = true;

        for (auto ch : password)
            if (isspace(ch))
                noSpace = false;

        return fstAlpha && hasDigit && hasUpper && noSpace;
    }



    // *******************************************************************
    //	filenameIsValid
    //
    //  task:	       Validates to see if filename conforms to the
    //                 requirements of a filename
    //  data in:	   User object
    //  data returned: True if filename is not empty,
    //                 has none of these characters :
    //                 \ / : * ? \" < > |
    //
    // *******************************************************************

    bool filenameIsValid()
    {
        string filename = lower(datafile);

        bool onlySpace = true;
        bool isValid = true;

        if (filename.empty())
            return false;
        if (filename == "user")
            return false;
        if (filename == "logs")
            return false;

        for (auto ch : filename)
        {
            if (!isspace(ch))
                onlySpace = false;
        }

        for (auto ch : filename)
            if (ch == '\\'|| ch == '/' ||
                ch == ':' || ch == '*' ||
                ch == '?' || ch == '"' ||
                ch == '<' || ch == '>' || ch == '|')

                isValid = false;

        return isValid && !onlySpace;
    }


    // Muhammed Aiman
    // *******************************************************************
    //	changePassword
    //
    //  task:	       Changes and modifies the user's password
    //                 in the database
    //  data in:	   New password
    //  data returned: None
    //
    // *******************************************************************

    void changePassword(string p)
    {
        password = p;

        vector<string> users;
        string fusername, fpassword, ftype, fstatus, fdatafile;

        fstream file;

        file.open(userDAT, ios::in);
        while (file >> fusername >> fpassword >> ftype >> fstatus >> fdatafile)
        {
            User user(fusername, fpassword, ftype, fstatus, fdatafile);
            if (lower(username) == lower(fusername))
            {
                user.password = p;
            }
            users.push_back(user.info());
        }
        file.close();

        file.open(userDAT, ios::out);
        for (int i=0; i < users.size(); i++)
        {
            file << users[i] << endl;
        }
        file.close();
    }


    // Najmuddin
    // *******************************************************************
    //	deactivate
    //
    //  task:	       Deactivates and modifies the user's active status
    //                 in the database
    //  data in:	   New password
    //  data returned: None
    //
    // *******************************************************************

    void deactivate()
    {
        status = "deleted";

        vector<string> users;
        string fusername, fpassword, ftype, fstatus, fdatafile;

        fstream file;

        file.open(userDAT, ios::in);
        while (file >> fusername >> fpassword >> ftype >> fstatus >> fdatafile)
        {
            User user(fusername, fpassword, ftype, fstatus, fdatafile);
            if (lower(username) == lower(fusername))
            {
                user.status = "deleted";
            }
            users.push_back(user.info());
        }
        file.close();

        file.open(userDAT, ios::out);
        for (int i=0; i < users.size(); i++)
        {
            file << users[i] << endl;
        }
        file.close();
    }


    // Srihari Naidu
    // *******************************************************************
    //	deleteFile
    //
    //  task:	       Checks to see if the file is ok to be deleted.
    //                 If so, it deletes the file.
    //  data in:	   Filename
    //  data returned: None
    //
    // *******************************************************************

    void deleteFile(string fileToDelete)
    {
        bool isDefault = false;
        bool isShared = false;

        isDefault = (fileToDelete == "datafiles/data.dat");

        string fusername, fpassword, ftype, fstatus, fdatafile;
        fstream file(userDAT);
        while (file >> fusername >> fpassword >> ftype >> fstatus >> fdatafile)
        {
            if (lower(username) != lower(fusername) && datafile == fdatafile)
            {
                isShared = true;
            }
        }
        file.close();

        // Delete previous datafile only if it's not default (data.dat) or
        // is shared (used by other users)
        if (!isDefault && !isShared)
        {
            remove(fileToDelete.c_str());
        }
    }


    // Srihari Naidu
    // *******************************************************************
    //	saveDataFileAs
    //
    //  task:	       Changes and modifies the user's datafile
    //                 in the database
    //  data in:	   Filename
    //  data returned: None
    //
    // *******************************************************************

    void saveDataFileAs(string filename)
    {
        filename = lower(filename) + ".dat";

        if (filename != datafile) // CASE 1: If it's a new filename
        {
            if (filename != "data.dat") // CASE 2: If new filename is not default
            {
                string oldDataFile = "datafiles/" + datafile;
                string newDataFile = "datafiles/" + filename;

                fstream inFile(oldDataFile, ios::in);
                fstream outFile(newDataFile, ios::out);

                string line;
                while (getline(inFile, line))
                    outFile << line << '\n';
                inFile.close(); outFile.close();

                deleteFile(oldDataFile);
                updateDataFile(filename);
            }
            else if (filename == "data.dat" && datafile != "data.dat") // CASE 3: If it's the default filename
            {                                                          // But the old file is different
                string oldDataFile = "datafiles/" + datafile;
                deleteFile(oldDataFile);
                updateDataFile(filename);
            }
        }
    }


    // Najmuddin
    // *******************************************************************
    //	updateDataFile
    //
    //  task:	       Updates the user's datafile in the user database
    //  data in:	   Filename
    //  data returned: None
    //
    // *******************************************************************

    void updateDataFile(string filename)
    {
        datafile = filename;
        vector<string> users;
        string fusername, fpassword, ftype, fstatus, fdatafile;

        fstream file;

        file.open(userDAT, ios::in);
        while (file >> fusername >> fpassword >> ftype >> fstatus >> fdatafile)
        {
            User user(fusername, fpassword, ftype, fstatus, fdatafile);
            if (lower(username) == lower(fusername))
            {
                user.datafile = filename;
            }
            users.push_back(user.info());
        }
        file.close();

        file.open(userDAT, ios::out);
        for (int i=0; i < users.size(); i++)
        {
            file << users[i] << endl;
        }
        file.close();
    }


    // Mohammed Emad
    // *******************************************************************
    //	Log
    //
    //  task:	       Logs the user activity (passed into the string)
    //                 in the database
    //  data in:	   log
    //  data returned: None
    //
    // *******************************************************************

    void Log(string log, int format = 1)
    {

        if (type == "buyer")
        {
            string logFile = ".dat/logs.dat";

            fstream file(logFile, ios::app);

            if (format == 0) // getTime() is not needed --> getChorono() has it already
                file << "\n\n" << log;
            else
                file << getTime() + " | " + username + " -> " + log;

            file.close();
        }
    }
};
