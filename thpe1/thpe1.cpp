#include "thpe1.h"


string getCCType( string card )
{
    int length;
    int i = 0;
    int extract;
    length = card.size();
    
    while( i < length)
    {
        extract = card.at(i);
        if( isdigit( i))
        {
            i++;
        }
        return "Unknown";
    }
}

