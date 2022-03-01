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


TEST_CASE( "getCCType - Discover, boundary of 622126")
{
    string card = "6221267850492847";
    string type;
    type = getCCType( card);
    REQUIRE( type == "Discover");
}

TEST_CASE( "getCCType - Discover, boundary of 622926")
{
    string card = "6229268574829302";
    string type;
    type = getCCType( card);
    REQUIRE( type == "Discover");
}


TEST_CASE( "isNumbers - checking digits.")
{
    string card = "123456789";
    bool type;
    type = isNumbers( card);
    REQUIRE( type == true);
}

TEST_CASE( "isNumbers - testing false card, letters")
{
    string card = "1234567A";
    bool type;
    type = isNumbers( card);
    REQUIRE( type == false);
}


TEST_CASE( "isNumbers - testing false, letter at start")
{
    string card = "a1234567";
    bool type;
    type = isNumbers( card);
    REQUIRE( type == false);
}

TEST_CASE( "islength - testing true, 13 numbers")
{
    string card = "1234567890493";
    bool type = isLength( card);
    REQUIRE( type == true);
}

    
TEST_CASE( "isLength - testing true, 15 numbers")
{
    string card = "123456789012345";
    bool type = isLength( card);
    REQUIRE( type == true);
}

TEST_CASE( "isLength - testing true, 16 numbers")
{
    string card = "1234567890123456";
    bool type = isLength( card);
    REQUIRE( type == true);
}

TEST_CASE( "isLength - testing false, 12 numbers")
{
    string card = "123456789012";
    bool type = isLength( card);
    REQUIRE( type == true);
}

