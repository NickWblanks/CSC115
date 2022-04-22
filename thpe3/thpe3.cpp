#include "thpe3.h"


void fillHand( int hands[], int size, int seed)
{
    int i;
    int j;
    int checkCard;
    for(i=0; i<size; i++)
    {
        hands[i] = getCard(seed);
    }
    for( i = 0; i < size; i++)
    {
        checkCard = hands[i];
        for( j = i + 1; j < size; j++)
        {
            if( checkCard == hands[j])
            {
                hands[i] = getCard(seed);
            }
        }
    }
    return;
}

int getCard( int seed)
{   
    static default_random_engine engine( seed );
    uniform_int_distribution<int> deck(0,51);
    return deck(engine);
}


void suitLookup( int suits[4], int hands[], int size)
{
    int i;
    for( i = 0; i < size; i++)
    {
        suits[i] = 0;
    }
    for( i = 0; i < size; i++)
    {
        if( (hands[i] / 13) == 0)
        {
            suits[0]++;
        }
        if( (hands[i] / 13) == 1)
        {
            suits[1]++;
        }
        if( (hands[i] / 13) == 2)
        {
            suits[2]++;
        }
        if( (hands[i] / 13) == 3)
        {
            suits[3]++;
        }
    }
}


void valLookup( int values[13], int hands[], int size)
{
    int i;
    for( i = 0; i < size; i++)
    {
        values[i] = 0;
    }
    for( i = 0; i < size; i++)
    {
        if( (hands[i] % 13) == 0)
        {
            values[0]++;
        }
        if( (hands[i] % 13) == 1)
        {
            values[1]++;
        }
        if( (hands[i] % 13) == 2)
        {
            values[2]++;
        }
        if( (hands[i] % 13) == 3)
        {
            values[3]++;
        }
        if( (hands[i] % 13) == 4)
        {
            values[4]++;
        }
        if( (hands[i] % 13) == 5)
        {
            values[5]++;
        }
        if( (hands[i] % 13) == 6)
        {
            values[6]++;
        }
        if( (hands[i] % 13) == 7)
        {
            values[7]++;
        }
        if( (hands[i] % 13) == 8)
        {
            values[8]++;
        }
        if( (hands[i] % 13) == 9)
        {
            values[9]++;
        }
        if( (hands[i] % 13) == 10)
        {
            values[10]++;
        }
        if( (hands[i] % 13) == 11)
        {
            values[11]++;
        }
        if( (hands[i] % 13) == 12)
        {
            values[12]++;
        }
    }
}

int classifyHand( int hands[], int size)
{
    bool full = true;
    bool full2 = true;
    int i;
    int j = 0;
    int values[13];
    int suits[4];
    valLookup( values, hands, size);
    suitLookup( suits, hands, size);
    for( i = 0; i < size; i++)
    {
        if( values[i] == 4)
        {
            return fourKind;
        }
        if( values[i] == 3)
        {
            for( j = i + 1; j < size; j++)
            {
                if( values[j] == 2)
                {
                    return fullHouse;
                }
            }
            return threeKind;
        }
        if( values[i] == 2)
        {
            for( j = i + 1; j < size; j++)
            {
                if( values[j] == 2)
                {
                    return twoPairs;
                }
            }
            return onePair;
        }
        if( suits[i] == 5)
        {
            while( full == true)
            {
                while( j < size)
                {
                    if( values[j] == 1)
                    {
                        if( values[j + 1] == 1)
                        {
                            if( values[j + 2] == 1)
                            {
                                if( values[j + 3] == 1)
                                {
                                    if( values[j + 4] == 1)
                                    {
                                        return straightFlush;
                                    }
                                }
                            }
                        }
                    }
                    j++;
                }
                full = false;
            }
            return suitFlush;
        }
        if( suits[i] == 5)
        {
            if( values[9] == 1)
            {
                if( values[10] == 1)
                {
                    if( values[11] == 1)
                    {
                        if( values[12] == 1)
                        {
                            if( values[0] == 1)
                            {
                                return RoyalFlush;
                            }
                        }
                    }
                }
            }
        }
        while( full2 == true)
        {
            while( j < size)
            {
                if( values[j] == 1)
                {
                    if( values[j + 1] == 1)
                    {
                        if( values[j + 2] == 1)
                        {
                            if( values[j + 3] == 1)
                            {
                                if( values[j + 4] == 1)
                                {
                                    return straight;
                                }
                            }
                        }
                    }
                }
                j++;
            }
            full2 = false;
        }
    }
    return high;
}

