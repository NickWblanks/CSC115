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
    if( argc != 5)
    {
        cout << "Usage: thpef.exe datafile template1 template2 template3" << endl;
        cout << "       " << "datafile --name of input datafile" << endl;
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
    
    bool success = getClient( fin, user);
    cout << success << endl;
    cout << user.fName << endl;
    cout << user.lName << endl;
    cout << user.address << endl;
    cout << user.city << endl;
    cout << user.state << endl;
    cout << user.zip << endl;
    cout << user.transAmt << endl;
    cout << user.currBal << endl;
}



TEST_CASE( "getDate - testing compiler and running checks.")
{
    string date = getDate();
    CHECK( date == "26 Apr, 2022");
}

    


