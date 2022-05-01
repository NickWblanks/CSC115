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

void writeLetter( Records &user, string templateN, string currDate);

void replaceName( string line, Records &user);

void replaceAdd( string line, Records &user);

void replaceCity( string line, Records &user);

void replaceState( string line, Records &user);

void replaceZIP( string line, Records &user);


