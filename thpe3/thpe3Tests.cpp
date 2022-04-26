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
    int i = 0;
    int seed;
    int nHands;
    int hands[5];
    int classification;
    int classes[10];
    int count = 0;
    if( argc != 4 )
    {
        cout << endl;
        cout << "Usage: thpe3.exe -s seedValue quantity" << endl;
        cout << "       " << "seedValue - # is integer for random numbers" << endl;
        cout << "       " << "quantity - # of hands to deal" << endl;
        cout << endl;
        cout << "       " << "thpe3.exe -f inputfilename outputfilename" << endl;
        cout << "       " << "inputfilename - filename containing the poker hands to classify" << endl;
        cout << "       " << "outputfilename - filename to output the statistics in" << endl;
        return 0;
    }
    if( (strcmp( argv[1], "-s") != 0) && (strcmp( argv[1], "-f") != 0))
    {
        cout << "Invalid Option" << endl;
    }
    if( strcmp(argv[1], "-s") == 0)
    {
        for( i = 0; i < 10; i++)
        {
            classes[i] = 0;
        }
        seed = stoi( argv[2]);
        nHands = stoi( argv[3]);
        for( i = 0; i < nHands; i++)
        {
            fillHand( hands, 5, seed);
            /*for(j = 0; j < 5; j++)
            {
                cout << hands[j] << "   ";
                if( j == 4)
                {
                    cout << endl;
                }
            }*/
            classification = classifyHand( hands, 5);
            //cout << classification << endl;
            countClass( classes, classification);
        }
        cout << fixed << showpoint << setprecision(6);
        cout << left << setw(20) << "Hand Name" << right << setw(10) << "Dealt" << setw(15) << "Chance" << endl;
        cout << left << setw(20) << "Royal Flush" << right << setw(10) << classes[9] << setw(15) << double( classes[9]) / double( nHands) * 100 << "%" << endl;
        cout << left << setw(20) << "Straight Flush" << right << setw(10) << classes[8] << setw(15) << double( classes[8])/ double( nHands) * 100 << "%" << endl;
        cout << left << setw(20) << "Four Of A Kind" << right << setw(10) << classes[7] << setw(15) << double( classes[7])/ double( nHands ) * 100 << "%" << endl;
        cout << left << setw(20) << "Full House" << right << setw(10) << classes[6] << setw(15) << double( classes[6])/ double( nHands) * 100 << "%" << endl;
        cout << left << setw(20) << "Flush" << right << setw(10) << classes[5] << setw(15) << double(classes[5])/ double(nHands) * 100 << "%" << endl;
        cout << left << setw(20) << "Straights" << right << setw(10) << classes[4] << setw(15) << double(classes[4])/ double(nHands) * 100 << "%" << endl;
        cout << left << setw(20) << "Three of a Kind" << right << setw(10) << classes[3] << setw(15) << double( classes[3])/ double( nHands) * 100 << "%" << endl;
        cout << left << setw(20) << "Two Pair" << right << setw(10) << classes[2] << setw(15) << double( classes[2])/ double(nHands) *100 << "%" << endl;
        cout << left << setw(20) << "Two of a Kind" << right << setw(10) << classes[1] << setw(15) << double( classes[1])/ double(nHands) * 100 << "%" << endl;
        cout << left << setw(20) << "High Card" << right << setw(10) << classes[0] << setw(15) << double( classes[0])/ double( nHands) * 100 << "%" << endl;
        cout << endl;
        cout << left << setw(20) << "Total Hands Dealt" << right << setw(10) << nHands << endl;
    }
    if( strcmp( argv[1], "-f") == 0)
    {
        int card;
        ifstream fin;
        ofstream fout;
        fout.open( argv[3]);
        fin.open( argv[2]);
        hands[5] = {0};
        classes[10] = {0};
        if( !fin.is_open() )
        {
            cout << "Unable to open the file: " << argv[2] << endl;
        }
        if( !fout.is_open() )
        {
            cout << "Unable to open the file: " << argv[3] << endl;
        }
        while( fin >> card)
        {
            hands[i] = card;
            i++;
            if( i == 5)
            {
                count++;
                classification = classifyHand( hands, 5);
                cout << classification << endl;
                countClass( classes, classification);
                i = 0;
            }
        }
        fout << fixed << showpoint << setprecision(6);
        fout << left << setw(20) << "Hand Name" << right << setw(10) << "Dealt" << setw(20) << "Chance" << endl;
        fout << left << setw(20) << "Royal Flush" << right << setw(10) << classes[9] << setw(20) << double( classes[9]) / double( count) * 100 << "%" << endl;
        fout << left << setw(20) << "Straight Flush" << right << setw(10) << classes[8] << setw(20) << double( classes[8])/ double( count) * 100 << "%" << endl;
        fout << left << setw(20) << "Four Of A Kind" << right << setw(10) << classes[7] << setw(20) << double( classes[7])/ double( count ) * 100 << "%" << endl;
        fout << left << setw(20) << "Full House" << right << setw(10) << classes[6] << setw(20) << double( classes[6])/ double( count) * 100 << "%" << endl;
        fout << left << setw(20) << "Flush" << right << setw(10) << classes[5] << setw(20) << double(classes[5])/ double(count) * 100 << "%" << endl;
        fout << left << setw(20) << "Straights" << right << setw(10) << classes[4] << setw(20) << double(classes[4])/ double( count) * 100 << "%" << endl;
        fout << left << setw(20) << "Three of a Kind" << right << setw(10) << classes[3] << setw(20) << double( classes[3])/ double( count) * 100 << "%" << endl;
        fout << left << setw(20) << "Two Pair" << right << setw(10) << classes[2] << setw(20) << double( classes[2])/ double(count) *100 << "%" << endl;
        fout << left << setw(20) << "Two of a Kind" << right << setw(10) << classes[1] << setw(20) << double( classes[1])/ double(count) * 100 << "%" << endl;
        fout << left << setw(20) << "High Card" << right << setw(10) << classes[0] << setw(20) << double( classes[0])/ double( count) * 100 << "%" << endl;
        fout << endl;
        fout << left << setw(20) << "Total Hands Dealt" << right << setw(10) << count << endl;
        fin.close();
        fout.close();
    }
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

 