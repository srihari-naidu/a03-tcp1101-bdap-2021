#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;



// *******************************************************************
//	ltrim
//
//  task:	       This trims trailing whitespaces from a string
//  data in:	   String to be left-trimmed, passed by reference
//  data returned: Left-trimmed string
//
// *******************************************************************

string ltrim(string &s)
{
    int from = 0, till = 0, length = 0;

    // till: first occurence of a non-space character
    for (int i = 0; i < s.length(); i++)
    {
        if (!isspace(s[i]))
        {
            till = i;
            break;
        }
    }

    // from: first occurence of a space before a non-space character
    for (int i = 0; i < till; i++)
    {
        if (isspace(s[i]))
        {
            from = i;
            break;
        }
    }

    length = till - from;

    // remove substring from space to non-space character
    s.erase(from, length);

    return s;
}



// *******************************************************************
//	rtrim
//
//  task:	       This trims leading whitespaces from a string
//  data in:	   String to be right-trimmed, passed by reference
//  data returned: Right-trimmed string
//
// *******************************************************************

string rtrim(string &s)
{
    int from = 0, till = 0, length = 0;

    // from: first occurence of a non-space character from the end
    for (int i = s.length() - 1; i >= 0; i--)
    {
        if (!isspace(s[i]))
        {
            from = i;
            break;
        }
    }

    // till: first occurence of a space after a non-space character
    for (int i = s.length() - 1; i > from; i--)
    {
        if (isspace(s[i]))
        {
            till = i;
            break;
        }
    }

    length = till - from;
    // remove substring from non-space character to space
    s.erase(from+1, length);

    return s;
}



// *******************************************************************
//	trim
//
//  task:	       Comprise of ltrim and trim functions
//  data in:	   String to be rtrimed and ltrimmed
//  data returned: Trimmed string
//
// *******************************************************************

string trim(string &s)
{
    rtrim(s);
    ltrim(s);
    return s;
}



// *******************************************************************
//	lower
//
//  task:	       Converts string to lowercase
//  data in:	   String
//  data returned: Lowecase string
//
// *******************************************************************

string lower(string s)
{
    int size = s.length();
    for (int i = 0; i < size; i++)
    {
        if (isalpha(s[i]))
        {
            if (s[i] >= 'A' && s[i] <= 'Z')
                s[i] = s[i] + 32;
        }
    }
    return s;
}
