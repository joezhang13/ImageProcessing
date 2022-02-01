#include <iostream>
#include <fstream>
using namespace std;

#include "ColorClass.h"

ColorClass::ColorClass()
{
    red = MAX_COLOR;
    green = MAX_COLOR;
    blue = MAX_COLOR;
}

ColorClass::ColorClass(int inRed, int inGreen, int inBlue)
{
    clip(inRed);
    clip(inGreen);
    clip(inBlue);

    red = inRed;
    green = inGreen;
    blue = inBlue;
}

void ColorClass::clip(int &inValue)
{
    if (inValue < MIN_COLOR)
    {
        inValue = MIN_COLOR;
    }
    else if (inValue > MAX_COLOR)
    {
        inValue = MAX_COLOR;
    }
}

bool ColorClass::clipColor(int &inRed, int &inGreen, int &inBlue)
{
    bool doClip = true;
    int initialInRed = inRed;
    int initialInGreen = inGreen;
    int initialInBlue = inBlue;

    clip(inRed);
    clip(inGreen);
    clip(inBlue);

    if (inRed == initialInRed && inGreen == initialInGreen && 
        inBlue == initialInBlue)
    {
        doClip = false;
    }
    
    return doClip;
}

void ColorClass::setToBlack()
{
    red = MIN_COLOR;
    green = MIN_COLOR;
    blue = MIN_COLOR;
}

void ColorClass::setToRed()
{
    red = MAX_COLOR;
    green = MIN_COLOR;
    blue = MIN_COLOR;
}

void ColorClass::setToGreen()
{
    red = MIN_COLOR;
    green = MAX_COLOR;
    blue = MIN_COLOR;
}

void ColorClass::setToBlue()
{
    red = MIN_COLOR;
    green = MIN_COLOR;
    blue = MAX_COLOR;
}

void ColorClass::setToWhite()
{
    red = MAX_COLOR;
    green = MAX_COLOR;
    blue = MAX_COLOR;
}

bool ColorClass::setTo(int inRed,int inGreen,int inBlue)
{
    bool doClip = clipColor(inRed, inGreen, inBlue);

    red = inRed;
    green = inGreen;
    blue = inBlue;

    return doClip;
}

bool ColorClass::setTo(ColorClass &inColor)
{
    bool doClip = false;
    int inRed = inColor.red;
    int inGreen = inColor.green;
    int inBlue = inColor.blue;

    doClip = setTo(inRed, inGreen, inBlue);

    return doClip;
}

bool ColorClass::addColor(ColorClass &rhs)
{
    bool doClip = false;
    int inRed = red + rhs.red;
    int inGreen = green + rhs.green;
    int inBlue = blue + rhs.blue;

    doClip = setTo(inRed, inGreen, inBlue);

    return doClip;
}

bool ColorClass::subtractColor(ColorClass &rhs)
{
    bool doClip = false;
    int inRed = red - rhs.red;
    int inGreen = green - rhs.green;
    int inBlue = blue - rhs.blue;

    doClip = setTo(inRed, inGreen, inBlue);

    return doClip;
}

bool ColorClass::adjustBrightness(double adjFactor)
{
    bool doClip = false;
    int inRed = int(red * adjFactor);
    int inGreen = int(green * adjFactor);
    int inBlue = int(blue * adjFactor);

    doClip = setTo(inRed, inGreen, inBlue);

    return doClip;
}

void ColorClass::printComponentValues()
{
    cout << "R: " << red << " G: " << green << " B: " << blue;
}

bool ColorClass::readFromFile(ifstream &inFile)
{
    bool doClip;
    int inRed;
    int inGreen;
    int inBlue;

    if (!input(inFile, inRed))
    {
        return false;
    }
    if (!input(inFile, inGreen))
    {
        return false;
    }
    if (!input(inFile, inBlue))
    {
        return false;
    }
    doClip = setTo(inRed, inGreen, inBlue);

    if (doClip)
    {
        cout << "RGB value out of range!" << endl;
        return false;
    }

    return true;
}

void ColorClass::writeToFile(ofstream &outFile)
{
    outFile << red << " " << green << " " << blue;
}

bool ColorClass::isEqualTo(ColorClass &inColor)
{
    bool isEqual = (red == inColor.red) && 
                   (green == inColor.green) && 
                   (blue == inColor.blue);

    return isEqual;
}