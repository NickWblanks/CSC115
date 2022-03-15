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
    initialArray( array, 5, 0);
    CHECK( array[0] == 0);
    CHECK( array[1] == 0);
    CHECK( array[2] == 0);
    CHECK( array[3] == 0);
    CHECK( array[4] == 0);
}


TEST_CASE( "initialArray - testing 78 just because")
{
    double array[5];
    initialArray( array, 5, 78);
    CHECK( array[0] == 78);
    CHECK( array[1] == 78);
    CHECK( array[2] == 78);
    CHECK( array[3] == 78);
    CHECK( array[4] == 78);
}

TEST_CASE( "initialArray - testing larger array size, value of 18")
{
    double array[25];
    initialArray( array, 25, 18);
    CHECK( array[0] == 18);
    CHECK( array[4] == 18);
    CHECK( array[24] == 18);
}


//sumArray

TEST_CASE( "sumArray - testing small array to see if it works")
{
    double array[4] = { 2, 2, 2, 2};
    double sum;
    sum = sumArray( array, 4);
    REQUIRE( sum == 8);
}

TEST_CASE( "sumArray - testing small array with mixed numbers")
{
    double array[7] = { 1, 3, 5, 6, 2, 9, 18};
    double sum;
    sum = sumArray( array, 7);
    REQUIRE( sum == 44); 
}

TEST_CASE( "sumArray - testing medium array with decimal numbers")
{
    double array[12] = { 3.72, 4.8, 9.643, 25.4, 32.79, 12.022, 13.421, 2.1, 1.9, 10.001, 89.20, 102.1};
    double sum;
    sum = sumArray( array, 12);
    REQUIRE( sum == 307.097);
}


//averageArray

TEST_CASE( "averageArray - testing small data set.")
{
    double array[4] = {2, 2, 2, 2};
    double avg;
    avg = averageArray( array, 4);
    REQUIRE( avg == 2);
}


TEST_CASE( "averageArray - testing larger data set, checking beginning and end.")
{
    double array[8] = {9, 12, 3, 4, 76, 4, 5, 23};
    double avg;
    avg = averageArray( array, 8);
    REQUIRE( avg == 17);
}


TEST_CASE( "averageArray - testing larger data set with decimals.")
{
    double array[15] = {2.5, 4.92, 9.321, 2.2, 2.5, 3.5, 4.81, 6.77, 3.29, 2.98, 11.11, 12.32, 13.43, 14.34, 2.4};
    double avg;
    avg = averageArray( array, 15);
    REQUIRE( avg == Approx( 6.426066666));
}


//minLocation

TEST_CASE( "minLocation - testing basic data set, 0 position is min.")
{
    double array[5] = {1, 2, 3, 4, 5};
    int location;
    location = minLocation( array, 5);
    REQUIRE( location == 0);
}

TEST_CASE( "minLocation - testing basic data set, 6th position is min.")
{
    double array[7] = {7, 6, 5, 4, 3, 2, 1};
    int location;
    location = minLocation( array, 7);
    REQUIRE( location == 6);
}

TEST_CASE( "minLocation - testing middle of array.")
{
    double array[4] = {2, 3, 1, 5};
    int location;
    location = minLocation( array, 4);
    REQUIRE( location == 2);
}

TEST_CASE( "minLocation - larger data set with decimals.")
{
    double array[9] = { 0.89, 1, 1.2, 2.9, 0.0003, 0.03, 0.78, 0.000001, 1};
    int location;
    location = minLocation( array, 9);
    REQUIRE( location == 7);
}

//minValue

TEST_CASE( "minValue - small data set, testing first location")
{
    double array[5] = {2, 4, 6, 8, 10};
    double value;
    value = minValue( array, 5);
    REQUIRE( value == 2);
}


TEST_CASE( "minValue - small data set, checking last location")
{
    double array[6] = {4, 5, 3, 2, 2, 1};
    double value;
    value = minValue( array, 6);
    REQUIRE( value == 1);
}


TEST_CASE( "minValue - testing larger data set, in middle")
{
    double array[12] = {4, 41, 12, 2, 1.99, 23, 2, 3, 42, 10, 11, 12};
    double value;
    value = minValue(array, 12);
    REQUIRE( value == 1.99);
}





    




    
