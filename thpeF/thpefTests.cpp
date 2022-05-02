#define CATCH_CONFIG_RUNNER
#include "..\\catch.hpp"
#include "thpef.h"

const bool RUNCATCH = false;

int main( int argc, char **argv)
{
    Catch::Session session;
    int result;
    if( RUNCATCH )
    {
        result = session.run();
        if( result != 0)
        {
            cout << "Test cases didn't pass." << endl;
            return result;
        }
    }
    ifstream fin;
    ofstream fout;
    Records user;
    string tempName;
    if( argc != 5)
    {
        cout << "Usage: thpef.exe datafile template1 template2 template3" << endl;
        cout << "       " << "datafile --name of input data file" << endl;
        cout << "       " << "template1 --name of purchase template file" << endl;
        cout << "       " << "template2 --name of payment template file" << endl;
        cout << "       " << "template3 --name of overdue template file" << endl;
        return 0;
    }
    fin.open( argv[1]);
    if( !fin.is_open() )
    {
        cout << "Unable to open the input file: " << argv[1] << endl;
        return 0;
    }
    while( getClient( fin, user))
    {
        int count = 0;
        count++;
        cout << count << endl;
        string templateN;
        string currDate;
        double trans = user.transAmt;
        double bal3 = user.currBal;
        if( trans < 0)
        {
            templateN = argv[3];
            writeLetter( user, templateN, currDate);                
            //payment template
        }
        if( trans == 0 && bal3 > 0)
        {
            templateN = argv[4];
            writeLetter( user, templateN, currDate);
                //overdue template
        }
        if( trans > 0 )
        {
            templateN = argv[2];
            writeLetter( user, templateN, currDate);
            //purchase template
        }
    }
    return 0;
}



TEST_CASE( "getDate - testing compiler and running checks.")
{
    string date = getDate();
    CHECK( date == "26 Apr, 2022");
}


TEST_CASE( "getClient")
{
    bool found;
    int i;
    ifstream fin;
    fin.open( "datafile1.txt");
    Records user;
    for( i = 0; i < 6; i++)
    {
        found = getClient( fin, user);
        REQUIRE( found == true);
    }
    CHECK( user.fName == "Ellen");
    CHECK( user.currBal == 54.60);
}

