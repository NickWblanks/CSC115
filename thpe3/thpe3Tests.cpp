#define CATCH_CONFIG_RUNNER
#include "..\\catch.hpp"
#include "thpe3.h"

const bool RUNCATCH = true;

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
    int i;
    int seed;
    int nHands;
    int hands[5];
    if( argc < 4 )
    {
        cout << endl;
        cout << "Usage: thpe3.exe -s seedValue quantity" << endl;
        cout << setw(7) << "seedValue - # is integer for random numbers" << endl;
        cout << setw(7) << "quantity - # of hands to deal" << endl;
        cout << endl;
        cout << setw(7) << "thpe3.exe -f inputfilename outputfilename" << endl;
        cout << setw(7) << "inputfilename - filename containing the poker hands to classify" << endl;
        cout << setw(7) << "outputfilename - filename to output the statistics in" << endl;
        return 0;
    }
    if( strcmp(argv[1], "-s") == 0)
    {
        seed = stoi( argv[2]);
        nHands = stoi( argv[3]);
        for( i = 0; i < nHands; i++)
        {
            
            fillHand( hands, 5, seed);
        }
    }
    
    return 0;
}

TEST_CASE( "classifyHand - testing 4 of a kind. 1, 14, 27, 40, -- 18")
{
    int hands[5] = {1, 14, 27, 40, 18};
    int type;
    type = classifyHand( hands, 5);
    CHECK( type == fourKind);
}


    