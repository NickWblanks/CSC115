#pragma once
#include <string>
#include <cmath>
#include <cctype>
#include <iostream>
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

int countIf( double array[], int size, double findVal);

void mySort( double array[], int size, string order);

int linearSearch( double array[], int size, double findVal);

int binarySearch( double array[], int size, double findVal);

//extra functions

double factorial( int number);

//Trig Functions


//Sin functions

double mySin( double rads);

double mySinD( double degrees);

//Cos functions

double myCos( double rads);

double myCosD( double degrees);



