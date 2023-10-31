#include <iostream>
#include <chrono>
#include <ctime>

using namespace std;
using namespace std::chrono;


// *******************************************************************
//	getChrono
//
//  task:	       Get string representation of current
//                 chronology -> Day Month DD HH:MM:SS YYYY
//  data in:	   None
//  data returned: Formatted string of current time
//
// *******************************************************************

string getChrono()
{
    // get system clock timepoint
    auto time = system_clock::now();

    // time_t --> type to represent time
    time_t now;

    // convert system clock timepoint to type time_t
    now = system_clock::to_time_t(time);

    // convert time_t value to string
    string chrono = ctime(&now);

    return chrono;
}



// *******************************************************************
//	getTime
//
//  task:	       Get current time -> HH:MM:SS
//  data in:	   None
//  data returned: Formatted string of current time
//
// *******************************************************************

string getTime()
{
    return getChrono().substr(11,8);
}