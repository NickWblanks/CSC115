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
    if( getline( fin, line, ' '))
    {
        getline( fin, line, ' ');
        string::size_type pos;
        pos = line.find( "#");
        if( pos != string::npos)
        {
            line.replace( pos, 9, user.fName + " " + user.lName);
            fout << line << endl;
        }
        getline( fin, line, ' ');
        pos = line.find( "#");
        if( pos != string::npos)
        {
            line.replace( pos, 8, user.address);
            fout << line << endl;
        }
        getline( fin, line, ',');
        pos = line.find( "#");
        if( pos != string::npos)
        {
            line.replace( pos, 5, user.city);
            fout << line << endl;
        }
        getline( fin, line, ' ');
        pos = line.find( "#");
        if( pos != string::npos)
        {
            line.replace( pos, 6, user.state);
            fout << line << endl;
        }
        getline( fin, line, ' ');
        pos = line.find( "#");
        if( pos != string::npos)
        {
            line.replace( pos, 4, user.zip);
            fout << line << endl;
        }
    }
}




void replaceName( string line, Records &user)
{
    line.replace( 0, 9, user.fName + "." + user.lName + ".txt");
}

void replaceAdd( string line, Records &user)
{
    line.replace( 0, 8, user.address);
}

void replaceCity( string line, Records &user)
{
    line.replace( 0, 5, user.city);
}

void replaceState( string line, Records &user)
{
    string::size_type pos;
    pos = line.find( "#STATE");
    line.replace( pos, 6, user.state);
}

void replaceZIP( string line, Records &user)
{
    string::size_type pos;
    pos = line.find( "#ZIP");
    line.replace( pos, 4, user.zip);
}