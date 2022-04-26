/** **********************************************************************
 * @file
 ************************************************************************/
 
#pragma once
#include <random>
#include <string>
#include <cctype>
#include <cmath>
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

/** **********************************************************************
 *
 *  @brief
 *  ROYALFLUSH is a globally defined integer that defines the royalflush hand.
 *  
 *************************************************************************/

const int ROYALFLUSH = 9;

/** **********************************************************************
 *
 *  @brief
 *  STRAIGHTFLUSH is a globally defined integer that defines the straight flush hand.
 *  
 *************************************************************************/

const int STRAIGHTFLUSH = 8;

/** **********************************************************************
 *
 *  @brief
 *  FOURKIND is a globally defined integer that defines the Four of a Kind hand.
 *  
 *************************************************************************/

const int FOURKIND = 7;

/** **********************************************************************
 *
 *  @brief
 *  FULLHOUSE is a globally defined integer that defines the Full House hand.
 *  
 *************************************************************************/

const int FULLHOUSE = 6;

/** **********************************************************************
 *
 *  @brief
 *  SUITFLUSH is a globally defined integer that defines a normal flush, or 5 cards of the same suit.
 *  
 *************************************************************************/

const int SUITFLUSH = 5;

/** **********************************************************************
 *
 *  @brief
 *  STRAIGHT is a globally defined integer that defines the normal straight, or any 5 cards that are in a row.
 *  
 *************************************************************************/

const int STRAIGHT = 4;

/** **********************************************************************
 *
 *  @brief
 *  THREEKIND is a globally defined integer that defines the three of a kind hand.
 *  
 *************************************************************************/

const int THREEKIND = 3;

/** **********************************************************************
 *
 *  @brief
 *  TWOPAIR is a globally defined integer that defines the two pair hand, a hand that contains two sets of two.
 *  
 *************************************************************************/

const int TWOPAIR = 2; //two sets of 2

/** **********************************************************************
 *
 *  @brief
 *  ONEPAIR is a globally defined integer that defines a hand that contains only a single pair of cards within a hand of 5.
 *  
 *************************************************************************/

const int ONEPAIR = 1;

/** **********************************************************************
 *
 *  @brief
 *  HIGH is a globally defined integer that defines a hand with only a high card and no other features.
 *  
 *************************************************************************/

const int HIGH = 0;


int getCard(int seed);

void fillHand( int hands[], int size, int seed);

void suitLookup( int suits[], int hands[], int size);

void valLookup( int values[], int hands[], int size);

int classifyHand( int hands[], int size);

bool royalCheck( int hands[], int size);

int flushCheck( int hands[], int size);

int pairCheck( int hands[], int size);

void countClass( int classes[], int classification);

bool three( int hands[], int size);

bool full( int hands[], int size);

bool straightCheck( int hands[], int size);

bool four( int hands[], int size);

bool bigStraight( int hands[], int size);

