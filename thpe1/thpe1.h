#pragma once
#include <cmath>
#include <string>
#include <cctype>

using namespace std;



string getCCType( string card);

bool isAmexp( string card);

bool isVisa( string card);

bool isMaster( string card);

bool isDiscover( string card);


bool isNumbers( string card);

bool isLength( string card);

bool luhnsEven( string card);

bool luhnsOdd( string card);
