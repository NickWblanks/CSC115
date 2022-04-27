#pragma once
#include <random>
#include <string>
#include <cctype>
#include <cmath>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <ctime>

using namespace std;

struct userRecords
{
    string firstName;
    string lastName;
    string address;
    string city;
    string state;
    string zip;
    double TransAmt;
    double currBal;
};


string getDate();
