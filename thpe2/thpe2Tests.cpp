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
