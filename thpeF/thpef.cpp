#include "thpef.h"

string getDate()
{
    time_t myTimeT = time(nullptr);
    string currentTime = ctime( &myTimeT );
    string day = currentTime.substr( 8, 2);
    string month = currentTime.substr( 4, 3);
    string year = currentTime.substr( 20, 4);
    string shortTime = day + " " + month + ", " + year;
    return shortTime;
}



