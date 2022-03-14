#define CATCH_CONFIG_MAIN
#include "..\\catch.hpp"
#include "thpe2.h"




//mySqrt

TEST_CASE( "mySqrt - testing 0, should return 0")
{
    double stNum = 0;
    double ans;
    ans = mySqrt( stNum);
    REQUIRE( ans == 0);
}


TEST_CASE( "mySqrt - testing 4, should return 2")
{
    double stNum = 4;
    double ans;
    ans = mySqrt( stNum);
    REQUIRE( ans == Approx(2));
}


TEST_CASE( "mySqrt - testing 9, should return 3")
{
    double stNum = 9;
    double ans;
    ans = mySqrt( stNum);
    REQUIRE( ans == Approx(3));
}

TEST_CASE( "mySqrt - testing 16, should return 4")
{
    double stNum = 16;
    double ans;
    ans = mySqrt( stNum);
    REQUIRE( ans == Approx(4));
}

TEST_CASE( "mySqrt - testing 435, should return 20.856654")
{
    double stNum = 435;
    double ans;
    ans = mySqrt( stNum);
    REQUIRE( ans == Approx(20.8566536146));
}

TEST_CASE( "mySqrt - testing 22.8, should return 4.77493455453")
{
    double stNum = 22.8;
    double ans;
    ans = mySqrt( stNum);
    REQUIRE( ans == Approx( 4.77493455453));
}



//myCbrt

TEST_CASE( "myCbrt - testing 0, should return 0")
{
    double stNum = 0;
    double ans;
    ans = myCbrt( stNum);
    REQUIRE( ans == 0 );
}

TEST_CASE( "myCbrt - testing 8, should return 2")
{
    double stNum = 8;
    double ans;
    ans = myCbrt( stNum);
    REQUIRE( ans == Approx(2));
}

TEST_CASE( "myCbrt - testing 125, should return 5")
{
    double stNum = 125;
    double ans;
    ans = myCbrt( stNum);
    REQUIRE( ans  == Approx(5));
}

TEST_CASE( "myCbrt - testing 34, should return 3.2396118013")
{
    double stNum = 34;
    double ans;
    ans = myCbrt( stNum);
    REQUIRE( ans == Approx( 3.2396118013));
}

TEST_CASE( "myCbrt - testing 187, should return 5.71848") //didnt go as far because the calculator would go past 5 decimals.
{
    double stNum = 187;
    double ans;
    ans = myCbrt( stNum);
    REQUIRE( ans == Approx( 5.71848));
}


//myLog

TEST_CASE( "myLog - testing log2(0), is undefined, should return 0")
{
    double arg = 0;
    int base = 2;
    double ans;
    ans = myLog( base, arg);
    REQUIRE( ans == 0);
}


TEST_CASE( "myLog - testing log10(10), should return 1")
{
    double arg = 10;
    int base = 10;
    double ans;
    ans = myLog(base, arg);
    REQUIRE( ans == Approx( 1));
}

TEST_CASE( "myLog - testing log4(83), should return 3.1875197156735")
{
    double arg = 83;
    int base = 4;
    double ans;
    ans = myLog( base, arg);
    REQUIRE( ans == Approx( 3.1875197156735));
}

TEST_CASE( "myLog - testing log5(784), should return 4.1408301425379")
{
    double arg = 784;
    int base = 5;
    double ans;
    ans = myLog( base, arg);
    REQUIRE( ans == Approx( 4.1408301425379));
}


//copy array

TEST_CASE( "copyArray - testing to see if it works. checking end values")
{
    double start[5] = {1, 2, 3, 1, 5};
    double copy[5];
    copyArray( copy, start, 5);
    CHECK( copy[0] == 1);
    CHECK( copy[1] == 2);
    CHECK( copy[2] == 3);
    CHECK( copy[3] == 1);
    CHECK( copy[4] == 5);
}


TEST_CASE( "copyArray - testing larger size.")
{
    double start[15] = {25, 2, 36, 12, 54, 48, 29, 0, 19, 109, 88, 14, 74, 14, 9};
    double copy[15];
    copyArray( copy, start, 15);
    CHECK( copy[0] == 25);
    CHECK( copy[1] == 2);
    CHECK( copy[2] == 36);
    CHECK( copy[3] == 12);
    CHECK( copy[4] == 54);
    CHECK( copy[14] == 9);
}


// initialArray

TEST_CASE( "initialArray - testing all 0's")
{
    double array[5];
    double value = 0;
    initialArray( array, 5, 0);
    CHECK( array[0] == 0);
    CHECK( array[1] == 0);
    CHECK( array[2] == 0);
    CHECK( array[3] == 0);
    CHECK( array[4] == 0);
}

    




    
