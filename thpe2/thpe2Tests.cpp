#define CATCH_CONFIG_MAIN
#include "..\\catch.hpp"
#include "thpe2.h"

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



    

