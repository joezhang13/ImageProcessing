#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#include "PatternClass.h"

PatternClass::PatternClass()
{
    upperLeft.setRowCol(DEFAULT_ROW_COL, DEFAULT_ROW_COL);
    numRow = DEFAULT_ROW_COL;
    numColumn = DEFAULT_ROW_COL;
    color.setToBlack();
    pattern = NULL;
}

PatternClass::~PatternClass()
{
    if (!(pattern == NULL))
    {
        for (int rInd = 0; rInd < numRow; rInd++)
        {
            delete [] pattern[rInd];
        }
        delete [] pattern;
    }
}

bool PatternClass::readPattern(string fname)
{
    ifstream inFile;

    inFile.open(fname.c_str());
    if (inFile.fail())
    {
        cout << "Unable to open the pattern file!" << endl;
        return false;
    }

    if (!input(inFile, numColumn))
    {
        return false;
    }

    if (!input(inFile, numRow))
    {
        return false;
    }

    pattern = new int *[numRow];
    for (int rInd = 0; rInd < numRow; rInd++)
    {
        pattern[rInd] = new int [numColumn];
    }

    for (int rInd = 0; rInd < numRow; rInd++)
    {
        for (int cInd = 0; cInd < numColumn; cInd++)
        {
            if (!input(inFile, pattern[rInd][cInd]))
            {
                cout << "Error found when trying to read the value at " <<
                        "Row:" << rInd << " Column:" << cInd << "!" << endl;
                return false;
            }
            else
            {
                if (pattern[rInd][cInd] != PATTERN_SOLID && 
                    pattern[rInd][cInd] != PATTERN_EMPTY)
                {
                    cout << "Pattern value out of range! " << 
                            "Expected only 0 or 1." << endl;
                    return false;
                }
            }
        }
    }

    inFile.close();

    return true;
}

void PatternClass::setUpperLeft(RowColumnClass &uL)
{
    upperLeft.setTo(uL);
}

void PatternClass::setColor(ColorClass &inColor)
{
    color.setTo(inColor);
}

RowColumnClass PatternClass::getUpperLeft()
{
    return upperLeft;
}

RowColumnClass PatternClass::getLowerRight()
{
    int row = upperLeft.getRow() + numRow - 1;
    int column = upperLeft.getCol() + numColumn - 1;
    RowColumnClass lowerRight(row, column);
    return lowerRight;
}

ColorClass PatternClass::getColor()
{
    return color;
}

int **PatternClass::getPattern()
{
    return pattern;
}