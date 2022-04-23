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
    cout << "Here" << endl;
    if( argc != 4 )
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
    REQUIRE( type == FOURKIND);
}

TEST_CASE( "classifyHand - testing fullHouse. 2, 15, 28,--29, 42")
{
    int hands[5] = {2, 15, 28, 29, 42};
    int type;
    type = classifyHand( hands, 5);
    CHECK( type == FULLHOUSE);
}

TEST_CASE( "classifyHand - testing threeKind. 3, 16, 29, -- 31, 35")
{
    int hands[5] = {3, 16, 29, 31, 35};
    int type;
    type = classifyHand( hands, 5);
    CHECK( type == THREEKIND);
}

TEST_CASE( "classifyHand - testing suitFlush. 13, 15, 17, 19, 21")
{
    int hands[5] = {13, 15, 17, 19, 21};
    int type;
    type = classifyHand( hands, 5);
    REQUIRE( type == SUITFLUSH);
}

TEST_CASE( "classifyHand - testing straightFlush. 43, 44, 45, 46, 47")
{
    int hands[5] = {43, 44, 45, 46, 47};
    int type;
    type = classifyHand( hands, 5);
    REQUIRE( type == STRAIGHTFLUSH);
}


TEST_CASE( "FourKind - Testing if it works")
{
    int hands[5] = {1, 14, 27, 40, 18};
    bool type;
    type = four( hands, 5);
    REQUIRE( type == true);
}

TEST_CASE( "classifyHand - testing straight. 6, 20, 34, 35, 49")
{
    int hands[5] = {6, 20, 34, 35, 49};
    int type;
    type = classifyHand( hands, 5);
    REQUIRE( type == STRAIGHT);
}

TEST_CASE( "classifyHand - testing twopair. 10, 23, 37, 50, 1")
{
    int hands[5] = {10, 23, 37, 50, 1};
    int type;
    type = classifyHand( hands, 5);
    REQUIRE( type == TWOPAIR);
}

TEST_CASE( "classifyHand - testing onepair. 12, 24, 36, 51, 9")
{
    int hands[5] = {12, 24, 36, 51, 9};
    int type;
    type = classifyHand( hands, 5);
    REQUIRE( type == ONEPAIR);
}

TEST_CASE( "classifyHand - RoyalFlush. 48, 49, 50, 51, 39")
{
    int hands[5] = {48, 49, 50, 51, 39};
    int type;
    type = classifyHand( hands, 5);
    REQUIRE( type == ROYALFLUSH);
}

TEST_CASE( "classifyHand - High card. 0, 18, 8, 25, 32")
{
    int hands[5] = {0, 18, 8, 25, 32};
    int type;
    type = classifyHand( hands, 5);
    REQUIRE( type == HIGH);
}




    