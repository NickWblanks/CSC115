/** **********************************************************************
 * @file
 ************************************************************************/

#include "thpe3.h"

/** **********************************************************************
 *  @author Nicholas K Wilk
 *
 *  @par Description
 *  
 *  This function will fill an array called hands with 5 values. It will ensure there are no duplicate numbers.
 *  It calls the getCard function to obtain cards via a random number generator.
 *
 *  @param[in] hands An integer array with 5 spots (0-4).
 *
 *  @param[in] size The size of the array.
 *
 *  @param[in] seed A value to be input into a random number generator. 
 *
 *
 *  
 *
 *
 *  @par Example
 *  @verbatim
    
    int seed = 10;
    fillHand( hands, size, seed)

    @endverbatim
 ************************************************************************/

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


/** **********************************************************************
 *  @author Nicholas K Wilk
 *
 *  @par Description
 *  
 *  This function obtains a single number within the range of 0-51 inclusive.
 *
 *  @param[in] seed A value to determine the seed of the generator.
 *
 *  @returns an integer value from 0-51 inclusive.
 *
 *
 *  @par Example
 *  @verbatim
    
    int seed = 15;
    int card = getCard(seed);

    @endverbatim
 ************************************************************************/


int getCard( int seed)
{   
    static default_random_engine engine( seed );
    uniform_int_distribution<int> deck(0,51);
    return deck(engine);
}


/** **********************************************************************
 *  @author Nicholas K Wilk
 *
 *  @par Description
 *  
 *  This function creates a lookup array containing the four suits of playing cards. 0 = clubs, 1 = diamonds, 2 = hearts, 3 = spades.
 *
 *  @param[in] suits An array with 4 spots, 0-4. it will be incremented depending on the card in the hands array.
 *
 *  @param[in] hands An array containing a full hand of cards with no duplicates. This function will assess what is in this array.
 * 
 *  @param[in] size The size of the hands array.
 *
 *  
 *
 *
 *  @par Example
 *  @verbatim
    
    int hands[5] = { 29, 31, 43, 0, 10}
    suitLookup( suits, hands, 4)
    2 hearts, 1 spade, and 2 clubs.

    @endverbatim
 ************************************************************************/

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


/** **********************************************************************
 *  @author Nicholas K Wilk
 *
 *  @par Description
 *  
 *  This function creates a lookup array based on the face values of the card in the hand.
 *
 *  @param[in] values The lookup array that is incremented after assessing the hands array.
 *
 *  @param[in] hands The hands array to be assessed.
 *
 *  @param[in] size The size of the array.
 *
 * 
 *
 *
 *  @par Example
 *  @verbatim
    
    int hands[5] = {0, 10, 12, 31, 19}
    valLookup( values, hands, 13)

    @endverbatim
 ************************************************************************/

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


/** **********************************************************************
 *  @author Nicholas K Wilk
 *
 *  @par Description
 *  
 *  This function returns an integer value that represents a type of hand available in poker.
 *
 *  @param[in] hands An array with 5 spots to be analized. It will be put into the suit and value lookup arrays.
 *
 *  @param[in] size The size of the array.
 *
 *  @returns An integer of the type of hand the array posseses.
 *
 *
 *  @par Example
 *  @verbatim
    
    int type;
    int hands[5] = {6, 7, 8, 9, 10};
    type = classifyHand( hands, 5);
    CHECK( type = STRAIGHTFLUSH)

    @endverbatim
 ************************************************************************/

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

/** **********************************************************************
 *  @author Nicholas K Wilk
 *
 *  @par Description
 *  
 *  This function returns a boolean value depends on whether of not the hands array contains 4 cards of the same face value.
 *
 *  @param[in] hands An array containing card to be checked.
 *
 *  @param[in] size The size of the array.
 *
 *
 *  @returns True if the hand has 4 cards of the same value. False otherwise.
 *
 *
 *  @par Example
 *  @verbatim
    
    int hands[5] {1, 15, 29, 41, 12};
    bool isFour = four( hands, size)
    CHECK( isFour == false)

    @endverbatim
 ************************************************************************/
 
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


/** **********************************************************************
 *  @author Nicholas K Wilk
 *
 *  @par Description
 *  
 *  This function returns a boolean value depends on whether of not the hands array contains a full house, or 3 and 2 cards of the same value.
 *
 *  @param[in] hands An array containing card to be checked.
 *
 *  @param[in] size The size of the array.
 *
 *
 *  @returns True if the hand is a full house. False otherwise.
 *
 *
 *  @par Example
 *  @verbatim
    
    int hands[5] {1, 15, 29, 41, 12};
    bool isFull = full( hands, size)
    CHECK( isFull == false)

    @endverbatim
 ************************************************************************/

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


/** **********************************************************************
 *  @author Nicholas K Wilk
 *
 *  @par Description
 *  
 *  This function returns a boolean value depends on whether of not the hands array contains exactly 3 cards of the same face value.
 *
 *  @param[in] hands An array containing card to be checked.
 *
 *  @param[in] size The size of the array.
 *
 *
 *  @returns True if the hand has 3 cards of the same value. False otherwise.
 *
 *
 *  @par Example
 *  @verbatim
    
    int hands[5] {1, 15, 29, 43, 44};
    bool isThree = three( hands, size)
    CHECK( isThree == false)

    @endverbatim
 ************************************************************************/

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

/** **********************************************************************
 *  @author Nicholas K Wilk
 *
 *  @par Description
 *  
 *  This function returns an integer value depending on whether there is a single pair, or a double pair.
 *
 *  @param[in] hands An array containing card to be checked.
 *
 *  @param[in] size The size of the array.
 *
 *
 *  @returns A 2 if there are two pairs, a 1 if there is one pair, or a -1 if there is neither.
 *
 *
 *  @par Example
 *  @verbatim
    
    int hands[5] {1, 15, 29, 41, 12};
    int isAnyPair = pairCheck( hands, size)
    CHECK( isAnyPair == -1)

    @endverbatim
 ************************************************************************/

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


/** **********************************************************************
 *  @author Nicholas K Wilk
 *
 *  @par Description
 *  
 *  This function returns an integer value depending on whether there is a straight flush, or a normal flush.
 *
 *  @param[in] hands An array containing card to be checked.
 *
 *  @param[in] size The size of the array.
 *
 *
 *  @returns A 2 if there is a suit flush, a 1 if there is a straight flush, or a -1 if there is neither.
 *
 *
 *  @par Example
 *  @verbatim
    
    int hands[5] {1, 15, 29, 41, 12};
    int isAnyFlush = flushCheck( hands, size)
    CHECK( isAnyFlush == -1)

    @endverbatim
 ************************************************************************/

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


/** **********************************************************************
 *  @author Nicholas K Wilk
 *
 *  @par Description
 *  
 *  This function returns a boolean value depending on whether or not the hand is a royal flush.
 *
 *  @param[in] hands An array containing card to be checked.
 *
 *  @param[in] size The size of the array.
 *
 *
 *  @returns True if all 5 cards are the same suit and are a straight of 10, jack, queen, king, ace.
 *
 *
 *  @par Example
 *  @verbatim
    
    int hands[5] {1, 15, 29, 41, 12};
    bool isRoyal = royalCheck( hands, size)
    CHECK( isRoyal == false)

    @endverbatim
 ************************************************************************/

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


/** **********************************************************************
 *  @author Nicholas K Wilk
 *
 *  @par Description
 *  
 *  This function returns a boolean value depending on whether the hand contains a straight.
 *
 *  @param[in] hands An array containing card to be checked.
 *
 *  @param[in] size The size of the array.
 *
 *
 *  @returns True if there are 5 cards in a row regardless of suit. False otherwise.
 *
 *
 *  @par Example
 *  @verbatim
    
    int hands[5] {1, 15, 29, 41, 12};
    bool isStraight = straightCheck( hands, size)
    CHECK( isStraight == true)

    @endverbatim
 ************************************************************************/

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


/** **********************************************************************
 *  @author Nicholas K Wilk
 *
 *  @par Description
 *  
 *  This function returns a boolean value depending on whether the hand contains a straight of 10, jack, queen, king, ace of different suits.
 *
 *  @param[in] hands An array containing card to be checked.
 *
 *  @param[in] size The size of the array.
 *
 *
 *  @returns True if there are 5 cards starting at 10 and going to ace in a row regardless of suit. False otherwise.
 *
 *
 *  @par Example
 *  @verbatim
    
    int hands[5] {1, 15, 29, 41, 12};
    bool isBigStraight = bigStraight( hands, size)
    CHECK( isStraight == false)

    @endverbatim
 ************************************************************************/


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


/** **********************************************************************
 *  @author Nicholas K Wilk
 *
 *  @par Description
 *  
 *  This function will count how many times a type of hand appears in a set. I.E if there are three hundred hands,
 *  this function will find how many of each type of hand was drawn.
 *
 *  @param[in] classes An array containing 10 spots, one for each type of hand (flush, full house etc.)
 *
 *  @param[in] classification An integer value that represents the type of hand within the hands array.
 *
 *
 *
 *
 *  @par Example
 *  @verbatim
    
    int classification = 9
    countClass( classes, classification)
    CHECK( classes[9] == 1)

    @endverbatim
 ************************************************************************/


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
