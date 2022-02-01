#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#include "input.h"

bool input(ifstream &inFile, int &val)
{
    bool success = false;

    inFile >> val;
    if (inFile.eof())
    {
        cout << "EOF before reading!" << endl;
    }
    else if (inFile.fail())
    {
        inFile.clear();
        inFile.ignore(NUM_IGNORE, CHAR_IGNORE);
        cout << "Error found in reading! An integer is expected." << endl;
    }
    else
    {
        success = true;
    }

    return success;
}

bool input(istream &inStream, int &val)
{
    bool success = false;

    inStream >> val;
    if (inStream.eof())
    {
        cout << "EOF before reading!" << endl;
    }
    else if (inStream.fail())
    {
        inStream.clear();
        inStream.ignore(NUM_IGNORE, CHAR_IGNORE);
        cout << "Error found in reading! An integer is expected." << endl;
    }
    else
    {
        success = true;
    }

    return success;
}

bool input(istream &inStream, int &firstVal, int &secondVal)
{
    bool success = false;

    inStream >> firstVal >> secondVal;
    if (inStream.eof())
    {
        cout << "EOF before reading!" << endl;
    }
    else if (inStream.fail())
    {
        inStream.clear();
        inStream.ignore(NUM_IGNORE, CHAR_IGNORE);
        cout << "Error found in reading! Two integers are expected." << endl;
    }
    else
    {
        success = true;
    }

    return success;
}