/** **********************************************************************
 * @file
 ************************************************************************/

#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <random>
#include <string>
#include <cstring>
#include <cctype>
#include <cmath>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <ctime>

using namespace std;

/** **********************************************************************
 *
 *  @struct Records
 *  
 *  @par Description
 *  Records is a structure that holds the data for a user. It uses strings for first, last, city, state, and zip.
 *  and doubles for transactions and current balance.
 *
 *  @var Records::fName
 *  Member 'fName' Contains a string for the first name of the user.
 *
 *  @var Records::lName
 *  Member 'lName' Contains a string for the last name of the user.
 *
 *  @var Records::address
 *  Member 'address' Contains a string for the address of the user.
 *
 *  @var Records::city 
 *  Member 'city' Contains a string for the city of the user.
 *
 *  @var Records::state
 *  Member 'state' Contains a string for the state of the user.
 *
 *  @var Records::zip
 *  Member 'zip' Contains the zip code of the user in a string.
 *
 *  @var Records::transAmt 
 *  Member 'transAmt' Contains the transaction amount as a double. Can be + or -.
 *
 *  @var Records::currBal
 *  Member 'currBal' Contains the current balance of the user as a double.
 *
 *
 *  
 *************************************************************************/

struct Records
{
    string fName;
    string lName;
    string address;
    string city;
    string state;
    string zip;
    double transAmt;
    double currBal;
};


string getDate();

bool getClient( ifstream &fin, struct Records &user);

void writeLetter( Records &user, string templateN, string cDate);

string trans2Str( Records &user);

string bal2Str( Records &user);

