/** **********************************************************************
 * @file
 ************************************************************************/

#include "thpe1.h"

/** **********************************************************************
 *  @author Nicholas K Wilk
 *
 *  @par Description
 *  
 *  This function will return a string name of a credit card company based on the string input.
 *  It will return unknown if the parameters do not match any of the known cards.
 *
 *  @param[in] card a string number to be checked.
 *
 *  @returns A string result of the credit card company that matches the number.  
 *
 *
 *  @par Example
 *  @verbatim
    
    string type;
    type = getCCType( "1234509c39484") // return = "Unknown"
    type = getCCType( "4492039485039484") // return = "Visa"
    type = getCCType( "379039402938475") // return = "American Express"

    @endverbatim
 ************************************************************************/

string getCCType( string card )
{
    bool cType;
    int i = 0;
    while( i != 1)
    {
        cType = isAmexp( card);
        if( cType == true)
        {
            i++;
            return "American Express";
        }
        cType = isVisa( card);
        if( cType == true)
        {
            i++;
            return "Visa";
        }
        cType = isMaster( card);
        if( cType == true)
        {
            i++;
            return "Mastercard";
        }
        cType = isDiscover( card);
        if( cType == true)
        {
            i++;
            return "Discover";
        }
        i++;
        return "Unknown";
    }
    return "Unknown";
}


/** **********************************************************************
 *  @author Nicholas K Wilk
 *
 *  @par Description
 *  Returns a boolean value based on the card whether or not the string matches the parameters of American Express cards.
 *
 *  @param[in] card A string number to be checked.
 *
 *  @returns A boolean result. True if the number matches the paramters of American Express cards.
 *
 *  @par Example
 *  @verbatim
    bool result;
    
    result = isAmexp( "379039402938475") // will return true
    result = isAmexp( "294038475729203") // will return false, doest start between 34-37

    @endverbatim
 ************************************************************************/
        

bool isAmexp( string card)
{
    string cardnum;
    int length;
    length = card.size();
    bool num;
    
    if( length == 15)
    {
        num = isNumbers( card);
        if( num == false)
        {
            return false;
        }
        cardnum = card.substr(0,2);
        if( cardnum == "34" || cardnum == "37")
        {
            return true;
        }
        return false;
    }
    return false;
}


/** **********************************************************************
 *  @author Nicholas K Wilk
 *
 *  @par Description
 *  Returns a boolean value based on the card whether or not the string matches the parameters of Visa cards.
 *
 *  @param[in] card A string number to be checked.
 *
 *  @returns A boolean result. True if the number matches the paramters of Visa cards.
 *
 *  @par Example
 *  @verbatim
    bool result;
    
    result = isVisa( "379039402938475") // will return false,doesnt have 13 or 16 numbers
    result = isVisa( "4940384757292034") // will return true, starts with 4 and has 16 numbers

    @endverbatim
 ************************************************************************/
        



bool isVisa( string card)
{
    string cardnum;
    int length;
    length = card.size();
    bool num;
    
    if( length == 13 || length == 16)
    {
        num = isNumbers( card);
        if( num == false)
        {
            return false;
        }
        cardnum = card.substr(0,1);
        if( cardnum == "4")
        {
            return true;
        }
        return false;
    }
    return false;
}


/** **********************************************************************
 *  @author Nicholas K Wilk
 *
 *  @par Description
 *  Returns a boolean value based on the card whether or not the string matches the parameters of Mastercard cards.
 *
 *  @param[in] card A string number to be checked.
 *
 *  @returns A boolean result. True if the number matches the paramters of Mastercard cards.
 *
 *  @par Example
 *  @verbatim
    bool result;
    
    result = isMaster( "379039402938475") // will return false,doesnt have 16 numbers
    result = isMaster( "5440384757292034") // will return true, starts inbetween 50-55 and has 16 numbers

    @endverbatim
 ************************************************************************/


bool isMaster( string card)
{
    string cardnum;
    int length;
    length = card.size();
    bool num;
    
    if( length == 16)
    {
        num = isNumbers( card);
        if( num == false)
        {
            return false;
        }
        cardnum = card.substr(0,2);
        if( cardnum >= "50" && cardnum <= "55")
        {
            return true;
        }
        return false;
    }
    return false;
}

/** **********************************************************************
 *  @author Nicholas K Wilk
 *
 *  @par Description
 *  Returns a boolean value based on the card whether or not the string matches the parameters of Discover cards.
 *
 *  @param[in] card a string number to be checked.
 *
 *  @returns A boolean result. True if the number matches the paramters of Discover cards.
 *
 *  @par Example
 *  @verbatim
    bool result;
    
    result = isVisa( "379039402938475") // will return false,doesnt have 16 numbers
    result = isVisa( "6450384757292034") // will return true, starts within range and has 16 numbers

    @endverbatim
 ************************************************************************/

bool isDiscover( string card)
{
    string cardnum;
    int length;
    length = card.size();
    bool num;
    
    if( length == 16)
    {
        num = isNumbers( card);
        if( num == false)
        {
            return false;
        }
        cardnum = card.substr(0,2);
        if( cardnum == "65")
        {
            return true;
        }
        cardnum = card.substr(0,3);
        if( cardnum >= "644" && cardnum <= "649")
        {
            return true;
        }
        cardnum = card.substr(0,4);
        if( cardnum == "6011")
        {
            return true;
        }
        cardnum = card.substr(0,6);
        if( cardnum >= "622126" && cardnum <= "622926")
        {
            return true;
        }
        return false;
    }
    return false;
}


/** **********************************************************************
 *  @author Nicholas K Wilk
 *
 *  @par Description
 *  Returns a boolean value based on the card whether or not the string contains numbers.
 *
 *  @param[in] card a string number to be checked.
 *
 *  @returns A boolean result. True if the card has numbers.
 *
 *  @par Example
 *  @verbatim
    bool result;
    
    result = isNumbers( "1234567891029") // returns true
    result = isNumbers( "123456789o1@8") // returns false

    @endverbatim 
 ************************************************************************/


bool isNumbers( string card)
{
    int length = card.size();
    int i = 0;
    int valid;
    while( i <= length - 1)
    {
        valid = isdigit( card.at(i));
        if( valid == false)
        {
            i++;
            return false;
        }
        i++;    
    }
    return true;
}


/** **********************************************************************
 *  @author Nicholas K Wilk
 *
 *  @par Description
 *  Returns a boolean value based on the card whether or not the string contains the correct lengths of 13, 15 or 16.
 *
 *  @param[in] card a string number to be checked.
 *
 *  @returns A boolean result. True if the card has the correct length.
 *
 *  @par Example
 *  @verbatim
    bool result;
    
    result = isLength( "1234567891029") // returns true , 13 numbers
    result = isLength( "123456789o1@8") // returns false, 14 characters

    @endverbatim
 ************************************************************************/


bool isLength( string card)
{
    int length;
    length = card.size();
    if( length == 13 || length == 15 || length == 16)
    {
        return true;
    }
    return false;
}

/** **********************************************************************
 *  @author Nicholas K Wilk
 *
 *  @par Description
 *  Returns a boolean value based on cards of even length (16) and returns true if it passes Luhns algorithm.
 *  Luhns is the sum of even position digits plus the sum of Odd digits (*2). If the odd is over 10, the individual digits are added,
 *  I/E 6*2 = 12, 1+2 = 3, 3 will be added to sum. If final sum is divisible by 10 with no remainder, it passes Luhns.
 *
 *  @param[in] card a string number to be checked.
 *
 *  @returns A boolean result. True if the card passes luhns algorithm
 *
 *  @par Example
 *  @verbatim
    bool result;
    
    result = luhnsEven( "4716150722142577") //returns true
    result = LuhnsEven( "6585288877768476") //returns false

    @endverbatim
 ************************************************************************/

bool luhnsEven( string card)
{
    int newval = 0;
    int cardnum = 0;
    int i = 0;
    int j = 1;
    int length = card.size();
    int sum = 0;
    int sum2 = 0;
    int lastsum = 0;
    while( i <= length - 1)
    {
        cardnum = card.at(i);
        newval = cardnum - '0';
        newval = newval * 2;
        if( newval < 9)
        {
         sum = sum + newval;   
        }
        if( newval > 9)
        {
            newval = 1 + ( newval % 10);
            sum = sum + newval;
        }
        i = i + 2;
    }
    while( j <= length - 1)
    {
        cardnum = card.at(j);
        cardnum = cardnum - '0';
        sum2 = sum2 + cardnum;
        j = j + 2;
    }
    lastsum = sum + sum2;
    if( lastsum % 10 == 0)
    {
        return true;
    }
    return false;
}


/** **********************************************************************
 *  @author Nicholas K Wilk
 *
 *  @par Description
 *  Returns a boolean value based on cards of odd length (13 or 15) and returns true if it passes Luhns algorithm.
 *  Luhns is the sum of odd position digits plus the sum of even digits times 2. If the even sum is over 10, the individual digits are added,
 *  I/E 6*2 = 12, 1+2 = 3, 3 will be added to sum. If final sum is divisible by 10 with no remainder, it passes Luhns.
 *
 *  @param[in] card  a string number to be checked.
 *
 *  @returns A boolean result. True if the card passes luhns algorithm
 *
 *  @par Example
 *  @verbatim
    bool result;
    
    result = luhnsOdd( "7425473237792") //returns true
    result = LuhnsOdd( "345649595068090") //returns false

    @endverbatim
 ************************************************************************/

bool luhnsOdd( string card)
{
    int newval = 0;
    int cardnum = 0;
    int i = 1;
    int j = 0;
    int length = card.size();
    int sum = 0;
    int sum2 = 0;
    int lastsum = 0;
    while( i <= length - 1)
    {
        cardnum = card.at(i);
        newval = cardnum - '0';
        newval = newval * 2;
        if( newval < 9)
        {
         sum = sum + newval;   
        }
        if( newval > 9)
        {
            newval = 1 + ( newval % 10);
            sum = sum + newval;
        }
        i = i + 2;
    }
    while( j <= length - 1)
    {
        cardnum = card.at(j);
        cardnum = cardnum - '0';
        sum2 = sum2 + cardnum;
        j = j + 2;
    }
    lastsum = sum + sum2;
    if( lastsum % 10 == 0)
    {
        return true;
    }
    return false;
}



/** **********************************************************************
 *  @author Nicholas K Wilk
 *
 *  @par Description
 *  Returns a boolean value that is determined by the cards length, 
 *  and whether of not the card passes Luhns algorithm.
 *  If the card is 16 digits long, it will be passed into luhnsEven.
 *  If the card is 15 or 13 digits long, it will be passed into luhnsOdd.
 *
 *  @param[in] card a string number to be checked.
 *
 *  @returns A boolean result. True if the card passes luhns algorithm
 *
 *  @par Example
 *  @verbatim
    bool result;
    
    result = isLuhns( "6440747636070782") //returns true, 16 digits, no letters, and passes luhnsEven
    result = isLuhns( "4425473125791") //returns false, 13 digits, no letters, but does not pass luhns

    @endverbatim
 ************************************************************************/


bool isLuhns( string card)
{
    int length = card.size();
    bool luhns;
    if( length == 16)
    {
        luhns = luhnsEven( card);
        return luhns;
    }
    if( length == 13 || 15)
    {
        luhns = luhnsOdd( card);
        return luhns;
    }
    return false;
}


/** **********************************************************************
 *  @author Nicholas K Wilk
 *
 *  @par Description
 *  Returns a boolean value that determines whether a string of numbers 
 *  input is a valid credit card number. It will return true only if its
 *  length is 13,15,or 16, if it has no letters, and if it passes Luhns algorithm
 *
 *  @param[in] card A string number to be checked.
 *
 *  @returns A boolean result. True if the number is a valid credit card number
 *
 *  @par Example
 *  @verbatim
    bool result;
    
    result = isValidCC( "7425473237792" ) // returns true, 13 digits, no letters, and passes luhns
    result = isValidCC( "6585288877768476" ) // returns false, 16 digits, no letters, but doesnt pass Luhns
    

    @endverbatim
 ************************************************************************/


bool isValidCC( string card)
{
    bool numbers = isNumbers( card);
    bool len = isLength( card);
    bool passLuhn = isLuhns( card);
    if( numbers == false)
    {
        return false;
    }
    if( len == false)
    {
        return false;
    }
    if( passLuhn == false)
    {
        return false;
    }
    return true;
}



    

        

    





