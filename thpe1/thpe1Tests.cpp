#define CATCH_CONFIG_MAIN
#include "..\\catch.hpp"
#include "thpe1.h"


TEST_CASE( "getCCType - Unknown")
{
    string card = "ABC1120003";
    string type;
    type = getCCType( card);
    REQUIRE( type == "Unknown");
}


    
