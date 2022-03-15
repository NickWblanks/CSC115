#pragma once
#include <string>
#include <cmath>
#include <cctype>

using namespace std;

//global constants

const int TERMS = 10;
const double PI = atan(1.0) * 4;
const double ERRORVALUE = .00000000001;
const int ITERATIONMAX = 5000;
const double ERRORTOLERANCE = .000001;



//square rt, cube rt, and log functions

double  mySqrt( double &stNum);

double myCbrt( double &stNum);

double myLog( int base, double arg);


//Arrays

void copyArray( double copy[], double start[], int size);

void initialArray( double array[], int size, double value);

double sumArray( double array[], int size);

double averageArray( double array[], int size);

int minLocation( double array[], int size);

double minValue( double array[], int size);

int maxLocation( double array[], int size);

double maxValue( double array[], int size);
