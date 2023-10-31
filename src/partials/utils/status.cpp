#include <chrono>
#include <thread>

using namespace std;
using namespace std::this_thread;
using namespace std::chrono;

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"



// *******************************************************************
//	ERR_{func}
//
//  task:	       Show and ERROR for a few second(s)
//  data in:	   None
//  data returned: None
//
// *******************************************************************

void ERR_InvalidSelection()
{

    cout << RED   << "\nERROR! "
         << RESET << "Invalid selection.";
    cout.flush();

    sleep_for(milliseconds(1000));
}


void ERR_InvalidCredentials()
{
    cout << RED   << "\nERROR! "
         << RESET << "Username or Password is invalid.";
    cout.flush();

    sleep_for(milliseconds(1500));
}


void ERR_UserDNE()
{
    cout << RED   << "\nERROR! "
         << RESET << "User does not exist.";
    cout.flush();

    sleep_for(milliseconds(1500));
}


void ERR_UsernameEmpty()
{
    cout << RED   << "\nERROR! "
         << RESET << "Username can not be empty.";
    cout.flush();

    sleep_for(milliseconds(1500));
}


void ERR_InvalidUsername()
{
    cout << RED   << "\nERROR! "
         << RESET << "Username should not have any spaces.";
    cout.flush();

    sleep_for(milliseconds(1500));
}


void ERR_UsernameTaken()
{
    cout << RED   << "\nERROR! "
         << RESET << "Username already taken. Try a different one.";
    cout.flush();

    sleep_for(milliseconds(1500));
}


void ERR_InvalidPassword()
{
    cout   << RED << "\nERROR! "
         << RESET << "Password doesn't meet the requirements.";
    cout.flush();

    sleep_for(milliseconds(1500));
}

void ERR_InvalidFilename()
{
    cout   << RED << "\nERROR! "
         << RESET << "File name is invalid.";
    cout.flush();

    sleep_for(milliseconds(1500));
}


void ERR_DeleteYourself()
{
    cout   << RED << "\nERROR! "
         << RESET << "You can't delete yourself.";
    cout.flush();

    sleep_for(milliseconds(1500));
}


void ERR_InvalidRow()
{
    cout   << RED << "\nERROR! "
         << RESET << "Invalid row.";
    cout.flush();

    sleep_for(milliseconds(1000));
}


void ERR_InvalidColumn()
{
    cout   << RED << "\nERROR! "
         << RESET << "Invalid column.";
    cout.flush();

    sleep_for(milliseconds(1000));
}



// *******************************************************************
//	STS_{func}
//
//  task:	       Show status for few second(s)
//  data in:	   None
//  data returned: None
//
// *******************************************************************

void STS_LoggingIn()
{
    cout << GREEN << "\n\nSTATUS: "
         << RESET << "Logging in..";
    cout.flush();

    sleep_for(milliseconds(1000));
}


void STS_LoggingOut()
{
    cout << GREEN << "\n\nSTATUS: "
         << RESET << "Logging out..";
    cout.flush();

    sleep_for(milliseconds(1000));
}


void STS_UsernameSet()
{
    cout << GREEN << "\nSTATUS: "
         << RESET << "Username set!";
    cout.flush();

    sleep_for(milliseconds(1500));
}


void STS_PasswordSet()
{
    cout << GREEN << "\nSTATUS: "
         << RESET << "Password set!";
    cout.flush();

    sleep_for(milliseconds(1500));
}


void STS_UsertypeSet()
{
    cout << GREEN << "\nSTATUS: "
         << RESET << "Usertype set!";
    cout.flush();

    sleep_for(milliseconds(1500));
}


void STS_PasswordChanged()
{
    cout << GREEN << "\nSTATUS: "
         << RESET << "Password has been changed.";
    cout.flush();

    sleep_for(milliseconds(1500));
}


void STS_UserDeleted()
{
    cout << GREEN << "\nSTATUS: "
         << RESET << "User has been deleted.";
    cout.flush();

    sleep_for(milliseconds(1500));
}


void STS_FileSaved()
{
    cout << GREEN << "\nSTATUS: "
         << RESET << "File has been saved.";
    cout.flush();

    sleep_for(milliseconds(1500));
}


void STS_HTML_ReportGenerated()
{
    cout << GREEN << "\nSTATUS: "
         << RESET << "HTML Report has been generated.\n"
                  << "        Opening now... ";;
    cout.flush();

    sleep_for(milliseconds(1700));
}


void STS_TXT_ReportGenerated()
{
    cout << GREEN << "\nSTATUS: "
         << RESET << "Text Report has been generated.\n"
                  << "        Opening now... ";;
    cout.flush();

    sleep_for(milliseconds(1700));
}

void STS_Quit()
{
    clearScreen();
    cout << R"(
    ______  ________   __
   / __ ) \/ / ____/  / /
  / __  |\  / __/    / /
 / /_/ / / / /___   /_/
/_____/ /_/_____/  (_)

)";
    cout.flush();
    sleep_for(milliseconds(700));
    clearScreen();

}
