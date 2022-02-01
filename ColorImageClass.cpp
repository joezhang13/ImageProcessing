#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#include "ColorImageClass.h"

ColorImageClass::ColorImageClass()
{
    colorImage = NULL;
    fileName = DEFAULT_NAME;
    imageType = MAGIC_NUMBER;
    numRow = DEFAULT_ROW_COL;
    numColumn = DEFAULT_ROW_COL;
    maxColor = MAX_COLOR;
}

ColorImageClass::~ColorImageClass()
{
    if (!(colorImage == NULL))
    {
        for (int rInd = 0; rInd < numRow; rInd++)
        {
            delete [] colorImage[rInd];
        }
        delete [] colorImage;
    }
}

bool ColorImageClass::readImage(string fname)
{
    int maxColor;
    ifstream inFile;

    fileName = fname;
    inFile.open(fileName.c_str());
    if (inFile.fail())
    {
        cout << "Unable to open the input image!" << endl;
        return false;
    }

    inFile >> imageType;
    if (imageType != MAGIC_NUMBER)
    {
        cout << "Error found when trying to read magic number: " << 
                "expected P3 but found " << imageType << "!" << endl;
        return false;
    }
    
    //Combine 3 IF statements by the OR operator ||
    if (!input(inFile, numColumn) || 
        !input(inFile, numRow) || 
        !input(inFile, maxColor))
    {
        return false;
    }

    if (maxColor != MAX_COLOR)
    {
        cout << "Error found when trying to read maximum color value: " << 
                "expected 255 but found " << maxColor << "!" << endl;
        return false;
    }
    
    colorImage = new ColorClass *[numRow];
    for (int rInd = 0; rInd < numRow; rInd++)
    {
        colorImage[rInd] = new ColorClass [numColumn];
    }

    for (int rInd = 0; rInd < numRow; rInd++)
    {
        for (int cInd = 0; cInd < numColumn; cInd++)
        {
            if (!colorImage[rInd][cInd].readFromFile(inFile))
            {
                cout << "Error found when trying to read the color of " << 
                        "the pixel at Row:" << rInd << " Column:" <<
                        cInd << "!" << endl;
                return false;
            }
        }
    }
    //Added the functionality to reject the ppm files which exceed 
    //the required length
    int temp;
    inFile >> temp;
    if (!inFile.eof())
    {
        cout << "Error found: the number of pixels in the ppm file " <<
                "exceeds the specified value!" << endl;
        return false;
    }

    inFile.close();

    return true;
}

bool ColorImageClass::writeImage(string fname)
{
    ofstream outFile;

    outFile.open(fname.c_str());
    if (outFile.fail())
    {
        cout << "Unable to open the output image!" << endl;
        return false;
    }
    outFile << imageType << endl;
    outFile << numColumn << " " << numRow << endl;
    outFile << maxColor << endl;

    for (int rInd = 0; rInd < numRow; rInd++)
    {
        for (int cInd = 0; cInd < numColumn; cInd++)
        {
            colorImage[rInd][cInd].writeToFile(outFile);
            if (cInd == numColumn - 1)
            {
                outFile << endl;
            }
            else
            {
                outFile << " ";
            }
        }
    }

    outFile.close();
    return true;
}

bool ColorImageClass::addRectangle(RectangleClass &rectangle)
{
    int startRow;
    int startColumn;
    int endRow;
    int endColumn;
    ColorClass color;
    bool filling;

    startRow = (rectangle.getUpperLeft()).getRow();
    startColumn = (rectangle.getUpperLeft()).getCol();
    endRow = (rectangle.getLowerRight()).getRow();
    endColumn = (rectangle.getLowerRight()).getCol();
    color = rectangle.getColor();
    filling = rectangle.getFilling();

    if (startRow < DEFAULT_ROW_COL || startRow >= numRow ||
        endRow < DEFAULT_ROW_COL || endRow >= numRow ||
        startColumn < DEFAULT_ROW_COL || startColumn >= numColumn ||
        endColumn < DEFAULT_ROW_COL || endColumn >= numColumn)
    {
        cout << "The location of rectangle is out of the range of " << 
                "the image!" << endl;
        return false;
    }

    for (int cInd = startColumn; cInd <= endColumn; cInd++)
    {
        colorImage[startRow][cInd].setTo(color);
        colorImage[endRow][cInd].setTo(color);
    }
    for (int rInd = startRow; rInd <= endRow; rInd++)
    {
        colorImage[rInd][startColumn].setTo(color);
        colorImage[rInd][endColumn].setTo(color);
    }
    if (filling)
    {
        for (int rInd = startRow; rInd <= endRow; rInd++)
        {
            for (int cInd = startColumn; cInd <= endColumn; cInd++)
            {
                colorImage[rInd][cInd].setTo(color);
            }
        }
    }

    return true;
}

bool ColorImageClass::addPattern(PatternClass &pattern)
{
    int startRow;
    int startColumn;
    int endRow;
    int endColumn;
    ColorClass color;
    int **patternValue;
    int rIndTemp = 0;
    int cIndTemp = 0;

    startRow = (pattern.getUpperLeft()).getRow();
    startColumn = (pattern.getUpperLeft()).getCol();
    endRow = (pattern.getLowerRight()).getRow();
    endColumn = (pattern.getLowerRight()).getCol();
    color = pattern.getColor();
    patternValue = pattern.getPattern();

    if (startRow < DEFAULT_ROW_COL || startRow >= numRow ||
        endRow < DEFAULT_ROW_COL || endRow >= numRow ||
        startColumn < DEFAULT_ROW_COL || startColumn >= numColumn ||
        endColumn < DEFAULT_ROW_COL || endColumn >= numColumn)
    {
        cout << "The location of pattern is out of the range of " << 
                "the image!" << endl;
        return false;
    }

    for (int rInd = startRow; rInd <= endRow; rInd++)
    {
        for (int cInd = startColumn; cInd <= endColumn; cInd++)
        {
            rIndTemp = rInd - startRow;
            cIndTemp = cInd - startColumn;
            if (patternValue[rIndTemp][cIndTemp] == PATTERN_SOLID)
            {
                colorImage[rInd][cInd].setTo(color);
            }
        }
    }

    return true;
}

bool ColorImageClass::insertImage(ColorImageClass &rhsImage,
                                  RowColumnClass &startLoc, 
                                  ColorClass &emptyColor)
{
    int startRow;
    int startColumn;
    int endRow;
    int endColumn;
    ColorClass color;
    ColorClass **insertedColorImage;
    int rIndTemp = 0;
    int cIndTemp = 0;

    startRow = startLoc.getRow();
    startColumn = startLoc.getCol();
    endRow = startRow + rhsImage.getNumRow() - 1;
    endColumn = startColumn + rhsImage.getNumColumn() - 1;
    insertedColorImage = rhsImage.getColorImage();

    if (startRow < DEFAULT_ROW_COL || startRow >= numRow ||
        endRow < DEFAULT_ROW_COL || endRow >= numRow ||
        startColumn < DEFAULT_ROW_COL || startColumn >= numColumn ||
        endColumn < DEFAULT_ROW_COL || endColumn >= numColumn)
    {
        cout << "The location of inserted image is out of the range of " << 
                "the original image!" << endl;
        return false;
    }

    for (int rInd = startRow; rInd <= endRow; rInd++)
    {
        for (int cInd = startColumn; cInd <= endColumn; cInd++)
        {
            rIndTemp = rInd - startRow;
            cIndTemp = cInd - startColumn;
            if (!insertedColorImage[rIndTemp][cIndTemp].isEqualTo(emptyColor))
            {
                color.setTo(insertedColorImage[rIndTemp][cIndTemp]);
                colorImage[rInd][cInd].setTo(color);
            }
        }
    }

    return true;
}

ColorClass **ColorImageClass::getColorImage()
{
    return colorImage;
}

int ColorImageClass::getNumRow()
{
    return numRow;
}

int ColorImageClass::getNumColumn()
{
    return numColumn;
}