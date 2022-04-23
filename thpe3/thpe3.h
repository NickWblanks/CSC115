#pragma once
#include <random>
#include <string>
#include <cctype>
#include <cmath>
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

const int ROYALFLUSH = 9;
const int STRAIGHTFLUSH = 8;
const int FOURKIND = 7;
const int FULLHOUSE = 6;
const int SUITFLUSH = 5;
const int STRAIGHT = 4;
const int THREEKIND = 3;
const int TWOPAIR = 2; //two sets of 2
const int ONEPAIR = 1;
const int HIGH = 0;


int getCard(int seed);

void fillHand( int hands[], int size, int seed);

void suitLookup( int suits[4], int hands[], int size);

void valLookup( int values[13], int hands[], int size);

int classifyHand( int hands[], int size);

bool royalCheck( int hands[], int size);

int flushCheck( int hands[], int size);

int pairCheck( int hands[], int size);

bool three( int hands[], int size);

bool full( int hands[], int size);

bool straightCheck( int hands[], int size);

bool four( int hands[], int size);

