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
        i++;
        return "Unknown";
    }
}

        

    

bool isAmexp( string card)
{
    int length;
    length = card.size();
    
    if( length == 15)
    {
        if( card.at(0) == '3')
        {
            if( card.at(1) == '4' || '7')
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }
}


bool isVisa( string card)
{
    int length;
    length = card.size();
    
    if( length == 13 || 16)
    {
        if( card.at(0) == '4')
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }
}


bool isMaster( string card)
{
    int length;
    length = card.size();
    
    if( length == 16)
    {
        if( card.at(0) == '5')
        {
            if( card.at(1) == '0' || '1' || '2' || '3' || '4' || '5')
            {
                return true;
            }
            return false;
        }
        return false;
    }
}


    
  