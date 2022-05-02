/** **********************************************************************
 * @file
 ************************************************************************/

#include "thpef.h"
#include "ourDate.h"

/** **********************************************************************
 *  @author Nicholas K Wilk
 *
 *  @par Description
 *  
 *  This function will obtain the date as a string in the format of DAY MONTH,YEAR.
 *
 *  @returns a string with the date in the format of DAY MONTH,YEAR
 *
 *  @par Example
 *  @verbatim
    
    string date = getDate();
    return date;

    @endverbatim
 ************************************************************************/

string getDate()
{
    if( currDate == "")
    {
        time_t myTimeT = time(nullptr);
        string currentTime = ctime( &myTimeT );
        string day = currentTime.substr( 8, 2);
        string month = currentTime.substr( 4, 3);
        string year = currentTime.substr( 20, 4);
        string shortTime = day + " " + month + ", " + year;
        return shortTime;
    }
    else
    {
        return currDate;
    }
}


/** **********************************************************************
 *  @author Nicholas K Wilk
 *
 *  @par Description
 *  
 *  This function will fill a structure with data coming in from a file. It 
 *  will return true if it does so successfully, false if not.
 *
 *  @param[in] fin the file being passed in.
 *
 *  @param[in] user The structure containing the data variables necessary to store the data.
 *
 *  @returns a boolena value representing whether the data was read successfully.
 *
 *  @par Example
 *  @verbatim
    
    bool success = getClient( fin, user)
    if( success)
    {
        return user.fName; // will return the first name of user.
    }

    @endverbatim
 ************************************************************************/

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

/** **********************************************************************
 *  @author Nicholas K Wilk
 *
 *  @par Description
 *  
 *  This is a void function that will take data from a structure, use it to populate a template file 
 *  provided from command line arguments. And then copy that file into a new outfile designated as the first.last.txt. 
 *
 *  @param[in] user The structure full of data.
 *
 *  @param[in] templateN the command line argument that desginates which template to use.
 *
 *  @param[in] cDate The date. 
 *
 *
 *
 *  @par Example
 *  @verbatim
    
    templateN = argv[3]; //payment template.
    getClient( fin, user) //obtains user data from inout datafile.
    writeLetter( user, templateN, cDate); //takes data from struct, and outputs it into a nice file.

    @endverbatim
 ************************************************************************/

void writeLetter( Records &user, string templateN, string cDate)
{
    ifstream fin;
    ofstream fout;
    string line;
    string date = getDate();
    string trans;
    string bal;
    int pos;
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

/** **********************************************************************
 *  @author Nicholas K Wilk
 *
 *  @par Description
 *  
 *  This function will take the data from the records.transAmt location and convert it to a string.
 *
 *  @param[in] user The structure to pull data from.
 *
 *  @returns a string that represents the double value within .transAmt.
 *
 *  @par Example
 *  @verbatim
    
    string trans = trans2Str( user); 
    return trans;

    @endverbatim
 ************************************************************************/

string trans2Str( Records &user)
{
    double val = user.transAmt;
    if( val < 0)
    {
        val = val * -1;
    }
    string Trans;
    ostringstream myStream;
    myStream << fixed << setprecision(2);
    myStream << val;
    Trans = myStream.str();
    return Trans;
}

/** **********************************************************************
 *  @author Nicholas K Wilk
 *
 *  @par Description
 *  
 *  This function will take the data from the records.currBal location and convert it to a string.
 *  It will also convert any negative number to positive and change the balance depending on the user.transAmt.
 *
 *  @param[in] user The structure to pull data from.
 *
 *  @returns a string that matches the double value withing the .currBal.
 *
 *  @par Example
 *  @verbatim
    
    string bal = bal2Str( user); 
    return trans;

    @endverbatim
 ************************************************************************/

string bal2Str( Records &user)
{
    double val = user.currBal;
    double transamt = user.transAmt;
    if( transamt > 0)
    {
        val = val + transamt;
    }
    if( transamt < 0)
    {
        transamt = transamt * -1;
        val = val - transamt;
    }
    string bal;
    ostringstream myStream;
    myStream << fixed << setprecision(2);
    myStream << val;
    bal = myStream.str();
    return bal;
}
