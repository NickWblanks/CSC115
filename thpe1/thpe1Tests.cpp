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

TEST_CASE( "luhnsEven - testing true, 4716150722142577")
{
    string card = "4716150722142577";
    bool type = luhnsEven( card);
    REQUIRE( type == true);
}


TEST_CASE( "luhnsEven - testing true, 6440747636070782")
{
    string card = "6440747636070782";
    bool type = luhnsEven( card);
    REQUIRE( type == true);
}

TEST_CASE( "luhnsEven - testing false, 6585288877768476")
{
    string card = "6585288877768476";
    bool type = luhnsEven( card);
    REQUIRE( type == false);
}


TEST_CASE( "luhnsOdd - testing true, 7425473237792")
{
    string card = "7425473237792";
    bool type = luhnsOdd( card);
    REQUIRE( type == true);
}


TEST_CASE( "luhnsOdd - testing true, 343669144240775")
{
    string card = "343669144240775";
    bool type = luhnsOdd( card);
    REQUIRE( type == true);
}

TEST_CASE( "luhnsOdd - testing false, 345649595068090")
{
    string card = "345649595068090";
    bool type = luhnsOdd( card);
    REQUIRE( type == false);
}


TEST_CASE( "isLuhns - testing true, 16 digit card, 6440747636070782")
{
    string card = "6440747636070782";
    bool type = isLuhns( card);
    REQUIRE( type == true);
}


TEST_CASE( "isLuhns - testing true, 15 digits, 343669144240775")
{
    string card = "343669144240775";
    bool type = isLuhns( card);
    REQUIRE( type == true);
}

TEST_CASE( "isLuhns - testing true, 13 digits, 7425473237792")
{
    string card = "7425473237792";
    bool type = isLuhns( card);
    REQUIRE( type == true);
}


TEST_CASE( "isLuhns - testing false, 16 digits, 6585288877768476")
{
    string card = "6585288877768476";
    bool type = isLuhns( card);
    REQUIRE( type == false);
}

TEST_CASE( "isLuhns - testing false, 15 digits, 345649595068090")
{
    string card = "345649595068090";
    bool type = isLuhns( card);
    REQUIRE( type == false);
}

TEST_CASE( "isLuhns - testing false, 13 digits, 4425473125791")
{
    string card = "4425473125791";
    bool type = isLuhns( card);
    REQUIRE( type == false);
}

TEST_CASE( "isLuhns - testing false, not right amount of digits, 19284059384958")
{
    string card = "19284059384958";
    bool type = isLuhns( card);
    REQUIRE( type == false);
}


TEST_CASE( "isLuhns - testing false, letters in string")
{
    string card = "123456789012r";
    bool type = isLuhns( card);
    REQUIRE( type == false);
}

TEST_CASE( "isValidCC - testing false, letters in string")
{
    string card = "12345t";
    bool type = isValidCC( card);
    REQUIRE( type == false);
}

TEST_CASE( "isValidCC - testing false, not 13,15 or 16")
{
    string card = "123456789";
    bool type = isValidCC( card);
    REQUIRE( type == false);
}


TEST_CASE( "isValidCC - testing false, doesnt pass luhns")
{
    string card = "6585288877768476";
    bool type = isValidCC( card);
    REQUIRE( type == false);
}


TEST_CASE( "isValidCC - testing true, has all 3.")
{
    string card = "7425473237792";
    bool type = isValidCC( card);
    REQUIRE( type == true);
}







