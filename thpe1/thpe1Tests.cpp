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


TEST_CASE( "getCCType - Discover, 65")
{
    string card = "6534885749203049";
    string type;
    type = getCCType( card);
    REQUIRE( type == "Discover");
}

TEST_CASE( "getCCType - Discover, range in 644 - 649")
{
    string card = "6478405947827464";
    string type;
    type = getCCType( card);
    REQUIRE( type == "Discover");
}

TEST_CASE( "getCCType - Discover, 6011")
{
    string card = "6011485740958473";
    string type;
    type = getCCType( card);
    REQUIRE( type == "Discover");
}


TEST_CASE( "getCCType - Discover, range in 622126 - 622926")
{
    string card = "6223278495049376";
    string type;
    type = getCCType( card);
    REQUIRE( type == "Discover");
}




