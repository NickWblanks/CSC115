#define CATCH_CONFIG_RUNNER
#include "..\\catch.hpp"
#include "thpe3.h"

const bool RUNCATCH = true;

int main( int argc, char **argv)
{
    Catch::Session session;
    int result;
    if( RUNCATCH == true)
    {
        result = session.run();
        if( result != 0)
        {
            cout << "Test cases didn't pass." << endl;
            return result;
        }
        
        
    }
    return 0;
}