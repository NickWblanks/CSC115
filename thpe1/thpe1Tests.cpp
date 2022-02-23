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


    
TEST_CASE( "getCCType - American Express")
{
    string card = "379039402938475";
    string type;
    type = getCCType( card);
    REQUIRE( type == "American Express");
}


TEST_CASE( "getCCType - Visa, 16 chars")
{
    string card = "40000000000000000";
    string type;
    type = getCCType( card);
    REQUIRE( type == "Visa");
}


TEST_CASE( "getCCType - Visa 13 chars")
{
    string card = "40000000000000";
    string type;
    type = getCCType( card);
    REQUIRE( type == "Visa");
}


TEST_CASE( "getCCType - Mastercard")
{
    string card = "5020493875910293";
    string type;
    type = getCCType( card);
    REQUIRE( type == "Mastercard");
}


