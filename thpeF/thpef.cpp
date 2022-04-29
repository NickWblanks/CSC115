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


bool getClient( ifstream &fin, Records &user)
{
    int i;
    user.transAmt = 0.0;
    user.currBal = 0.0;
    getline( fin, user.fName, ',');
    getline( fin, user.lName, ',');
    getline( fin, user.address, ',');
    getline( fin, user.city, ',');
    getline( fin, user.state, ',');
    getline( fin, user.zip, ',');
    fin >> user.transAmt;
    fin.ignore( 1, 'c');
    fin >> user.currBal;
    if( user.fName == "" || user.lName == "" || user.address == "" || user.city == "" || user.state == "" || user.zip == "" || user.transAmt == 0.0 || user.currBal == 0.0)
    {
        return false;
    }
    return true;
    //fout.open( rec.fName + "." + rec.lName + ".txt");
}

