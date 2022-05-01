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


bool getClient( ifstream &fin, struct Records &user)
{
    user.transAmt = 0.0;
    user.currBal = 0.0;
    if( getline( fin, user.fName, ',') )
    {
        getline( fin, user.lName, ',');
        getline( fin, user.address, ',');
        getline( fin, user.city, ',');
        getline( fin, user.state, ',');
        getline( fin, user.zip, ',');
        fin >> user.transAmt;
        fin.ignore(1, ',');
        fin >> user.currBal;
        fin.ignore();
        return true;
    }
    else
    {
        return false;
    }
    
}


void writeLetter( Records &user, string templateN, string currDate)
{
    ifstream fin;
    ofstream fout;
    string line;
    string date = getDate();
    string trans;
    string bal;
    fin.open( templateN );
    if( !fin.is_open())
    {
         cout << "Unable to open the template file: " << templateN << endl;
         return;
    }
    fout.open( user.fName + "." + user.lName + ".txt");
    if( !fout.is_open())
    {
        cout << "Unable to open the output file: " << user.fName + "." + user.lName + ".txt" << endl;
        return;
    }
    while( getline( fin, line))
    {
        int pos;
        pos = line.find( "#FULLNAME");
        if( pos != string::npos)
        {
            line.replace( pos, 9, user.fName + " " + user.lName);
            //fout << line << endl;
        }
        pos = line.find( "#FIRST");
        if( pos != string::npos)
        {
            line.replace( pos, 6, user.fName);
        }
        pos = line.find( "#LAST");
        if( pos != string::npos)
        {
            line.replace( pos, 5, user.lName);
        }
        pos = line.find( "#ADDRESS");
        if( pos != string::npos)
        {
            line.replace( pos, 8, user.address);
            //fout << line << endl;
        }
        pos = line.find( "#CITY");
        if( pos != string::npos)
        {
            line.replace( pos, 5, user.city);
        }
        pos = line.find( "#STATE");
        if( pos != string::npos)
        {
            line.replace( pos, 6, user.state);
        }
        pos = line.find( "#ZIP");
        if( pos != string::npos)
        {
            line.replace( pos, 4, user.zip);
        }
        pos = line.find( "#DATE");
        if( pos != string::npos)
        {
            line.replace( pos, 5, date);
        }
        pos = line.find( "#TRANSACTION");
        if( pos != string::npos)
        {
            trans = trans2Str( user);
            line.replace( pos, 12, trans);
        }
        pos = line.find( "#BALANCE");
        if( pos != string::npos)
        {
            bal = bal2Str( user);
            line.replace( pos, 8, bal);
        }
        fout << line << endl;
    }
    fin.close();
    fout.close();   
}

string trans2Str( Records &user)
{
    double val = user.transAmt;
    string Trans;
    ostringstream myStream;
    myStream << fixed << setprecision(2);
    myStream << val;
    Trans = myStream.str();
    return Trans;
}

string bal2Str( Records &user)
{
    double val = user.currBal;
    string bal;
    ostringstream myStream;
    myStream << fixed << setprecision(2);
    myStream << val;
    bal = myStream.str();
    return bal;
}
