#pragma once
#define _CRT_SECURE_NO_WARNINGS
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

bool getClient( ifstream &fin, Records &user);


