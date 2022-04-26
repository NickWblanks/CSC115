#include "thpe3.h"


void fillHand( int hands[], int size, int seed)
{
    int i;
    int j;
    int temp;
    for(i=0; i<size; i++)
    {
        hands[i] = -1;
    }
    for( i = 0; i< size; i++)
    {
        temp = getCard(seed);
        for( j = 0; j < 5; j++)
        {
            if( temp == hands[j])
            {
                temp = getCard(seed);
                j = -1;
            }
        }
        hands[i] = temp;
    }
}



int getCard( int seed)
{   
    static default_random_engine engine( seed );
    uniform_int_distribution<int> deck(0,51);
    return deck(engine);
}


void suitLookup( int suits[], int hands[], int size)
{
    int i;
    for( i = 0; i < 4; i++)
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


void valLookup( int values[], int hands[], int size)
{
    int i;
    for( i = 0; i < 13; i++)
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
    int values[13];
    int suits[4];
    valLookup( values, hands, size);
    suitLookup( suits, hands, size);
    bool isFour = four( hands, size);
    bool isHouse = full( hands, size);
    bool isThree = three( hands, size);
    bool isStraight = straightCheck( hands, size);
    bool hiStraight = bigStraight( hands, size);
    bool isRoyal = royalCheck( hands, size);
    int isAnyPair = pairCheck( hands, size);
    int isAnyFlush = flushCheck( hands, size);
    if( isRoyal == true)
    {
        return ROYALFLUSH;
    }
    if( isFour == true)
    {
        return FOURKIND;
    }
    if( isHouse == true)
    {
        return FULLHOUSE;
    }
    if( isThree == true)
    {
        return THREEKIND;
    }
    if( isAnyPair > 0)
    {
        if( isAnyPair > 1)
        {
            return TWOPAIR;
        }
        return ONEPAIR;
    }
    if( isAnyFlush > 0)
    {
        if( isAnyFlush > 1)
        {
            return SUITFLUSH;
        }
        return STRAIGHTFLUSH;
    }
    if( isStraight == true || hiStraight == true)
    {
        return STRAIGHT;
    }
    return HIGH;
}


bool four( int hands[], int size)
{
    int values[13];
    valLookup( values, hands, size);
    int i;
    for( i = 0; i < 13; i++)
    {
        if( values[i] == 4)
        {
            return true;
        }
    }
    return false;
}

bool full( int hands[], int size)
{
    int values[13];
    valLookup( values, hands, size);
    int i;
    int j;
    for( i = 0; i < 13; i++)
    {
        if( values[i] == 3)
        {
            for( j = 0; j < 13; j++)
            {
                if( values[j] == 2)
                {
                    return true;
                }
            }
        }
    }
    return false;
}

bool three( int hands[], int size)
{
    int values[13];
    valLookup( values, hands, size);
    int i;
    for( i = 0; i < 13; i++)
    {
        if( values[i] == 3)
        {
            return true;
        }
    }
    return false;
}

int pairCheck( int hands[], int size)
{
    int j;
    int values[13];
    valLookup( values, hands, size);
    int i;
    for( i = 0; i < 13; i++)
    {
        if( values[i] == 2)
        {
            for( j = i + 1; j < 13; j++)
            {
                if( values[j] == 2)
                {
                    return 2; //two pair
                }
            }
            return 1; //one pair
        }
    }
    return -1;
}

int flushCheck( int hands[], int size)
{
    int values[13];
    int suits[4];
    valLookup( values, hands, size);
    suitLookup( suits, hands, size);
    int i;
    int j;
    for( i = 0; i < 4; i++)
    {
        if( suits[i] == 5)
        {
            for( j = 0; j < 13; j++)
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
                                    return 1;  //straight flush
                                }
                            }
                        }
                    }
                }
            }
            return 2; //flush
        }
    }
    return -1;
}


bool royalCheck( int hands[], int size)
{
    int values[13];
    int suits[4];
    valLookup( values, hands, size);
    suitLookup( suits, hands, size);
    int i;
    for( i = 0; i < 4; i++)
    {
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
                                return true;
                            }
                        }
                    }
                }
            }
        }
    }
    return false;
}

bool straightCheck( int hands[], int size)
{
    int values[13];
    valLookup( values, hands, size);
    int i;
    for( i = 0; i < 9; i++)
    {
        if( values[i] == 1)
        {
            if( values[i + 1] == 1)
            {
                if( values[i + 2] == 1)
                {
                    if( values[i + 3] == 1)
                    {
                        if( values[i + 4] == 1)
                        {
                            return true;
                        }
                    }
                }
            }
        }
    }
    return false;
}

bool bigStraight( int hands[], int size)
{
    int values[13];
    valLookup( values, hands, size);
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
                        return true;
                    }
                }
            }
        }
    }
    return false;
}

void countClass( int classes[], int classification)
{
    if( classification == 0)
    {
        classes[0]++;
    }
    if( classification == 1)
    {
        classes[1]++;
    }
    if( classification == 2)
    {
        classes[2]++;
    }
    if( classification == 3)
    {
        classes[3]++;
    }
    if( classification == 4)
    {
        classes[4]++;
    }
    if( classification == 5)
    {
        classes[5]++;
    }
    if( classification == 6)
    {
        classes[6]++;
    }
    if( classification == 7)
    {
        classes[7]++;
    }
    if( classification == 8)
    {
        classes[8]++;
    }
    if( classification == 9)
    {
        classes[9]++;
    }
}



    