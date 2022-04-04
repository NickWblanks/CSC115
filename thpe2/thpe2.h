/** **********************************************************************
 * @file
 ************************************************************************/

#pragma once
#include <string>
#include <cmath>
#include <cctype>
#include <iostream>
#include <iomanip>
using namespace std;

//global constants

/** **********************************************************************
 *
 *  @brief
 *  TERMS is a globally defined integer that is used for calculating sine and cosine. It represents how many iterations of the taylors series it will calc.
 *  
 *************************************************************************/
const int TERMS = 10;

/** **********************************************************************
 *
 *  @brief
 *  PI is a globally defined double that is used for calculating sine and cosine. it represents the value of PI (3.141596).
 *  
 *************************************************************************/

const double PI = atan(1.0) * 4;

/** **********************************************************************
 *
 *  @brief
 *  ERRORVALUE is a globally defined double that is used as a benchmark for acceptable answers. If a result is less than this variable then it is an acceptable answer.
 *  This value is used primarily for the sqRt, cbRt, and logarithm functions.
 *
 *************************************************************************/

const double ERRORVALUE = .00000000001;

/** **********************************************************************
 *
 *  @brief
 *  ITERATIONMAX is a globally defined double that is used to calculate how many iterations of Newtons method the function will calculate. It is used in the log, sqRt, and cbRt.
 *  
 *************************************************************************/


const int ITERATIONMAX = 5000;


/** **********************************************************************
 *
 *  @brief
 *  ERRORTOLERANCE is a globally defined double that is used as a benchmark for acceptable answers. If a result is less than this variable then it is an acceptable answer.
 *  This value is used primarily for the trigonometric functions.
 *  
 *************************************************************************/

const double ERRORTOLERANCE = .000001;



//square rt, cube rt, and log functions

double mySqrt( double stNum);

double myCbrt( double stNum);

double myLog( double arg, double base);


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

//Tangent functions

double myTan( double rads);

double myTanD( double rads);

