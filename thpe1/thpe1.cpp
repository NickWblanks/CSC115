#include "thpe1.h"


string getCCType( string card )
{
    int i = 0;
    while( i != 1)
    {
        bool cType;
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

        

    

bool isAmexp( string card)
{
    string cardnum;
    int length;
    length = card.size();
    
    if( length == 15)
    {
        cardnum = card.substr(0,2);
        if( cardnum == "34" || "37")
        {
            return true;
        }
        return false;
    }
    return false;
}



bool isVisa( string card)
{
    string cardnum;
    int length;
    length = card.size();
    
    if( length == 13 || 16)
    {
        cardnum = card.substr(0,1);
        if( cardnum == "4")
        {
            return true;
        }
        return false;
    }
    return false;
}

        


bool isMaster( string card)
{
    string cardnum;
    int length;
    length = card.size();
    
    if( length == 16)
    {
        cardnum = card.substr(0,2);
        if( cardnum >= "50" && cardnum <= "55")
        {
            return true;
        }
        return false;
    }
    return false;
}
        


bool isDiscover( string card)
{
    string cardnum;
    int length;
    length = card.size();
    
    if( length == 16)
    {
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


bool isLength( string card)
{
    int length;
    length = card.size();
    if( length == 13 || 15 || 16)
    {
        return true;
    }
    return false;
}


        
                