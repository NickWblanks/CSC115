#pragma once
#include <random>
#include <string>
#include <cctype>
#include <cmath>
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

const int RoyalFlush = 9;
const int straightFlush = 8;
const int fourKind = 7;
const int fullHouse = 6;
const int suitFlush = 5;
const int straight = 4;
const int threeKind = 3;
const int twoPairs = 2; //two sets of 2
const int onePair = 1;
const int high = 0;


int getCard(int seed);

void fillHand( int hands[], int size, int seed);

void suitLookup( int suits[4], int hands[], int size);

void valLookup( int values[13], int hands[], int size);

int classifyHand( int hands[], int size);