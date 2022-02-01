#include <iostream>
#include <string>
using namespace std;

#include "RectangleClass.h"

RectangleClass::RectangleClass()
{
    upperLeft.setRowCol(DEFAULT_ROW_COL, DEFAULT_ROW_COL);
    lowerRight.setRowCol(DEFAULT_ROW_COL, DEFAULT_ROW_COL);
    color.setToBlack();
    filling = false;
}

void RectangleClass::setLocation(RowColumnClass &uL, RowColumnClass &lR)
{
    upperLeft.setTo(uL);
    lowerRight.setTo(lR);
}

void RectangleClass::setColor(ColorClass &inColor)
{
    color.setTo(inColor);
}

void RectangleClass::setFilling(bool &inFilling)
{
    filling = inFilling;
}

RowColumnClass RectangleClass::getUpperLeft()
{
    return upperLeft;
}

RowColumnClass RectangleClass::getLowerRight()
{
    return lowerRight;
}

ColorClass RectangleClass::getColor()
{
    return color;
}

bool RectangleClass::getFilling()
{
    return filling;
}