#ifndef _RECTANGLECLASS_H_
#define _RECTANGLECLASS_H_

#include "constants.h"
#include "RowColumnClass.h"
#include "ColorClass.h"

//This class can describe a rectangle by the location of it on an image,
//the color of it and whether it is filled or not.
class RectangleClass
{
    private:
        RowColumnClass upperLeft;
        RowColumnClass lowerRight;
        ColorClass color;
        bool filling;
    public:
        //This constructor sets the location of the corner points, 
        //the color and the filling option to default values
        RectangleClass();
        //This function sets the locations of the upper left point 
        //and the lower right point of the rectangle on the image
        void setLocation(RowColumnClass &uL, RowColumnClass &lR);
        //This function sets the color of the rectangle
        void setColor(ColorClass &inColor);
        //This function sets the filling option of the rectangle
        void setFilling(bool &inFilling);
        //This function returns the location of the upper left point 
        //of the rectangle on the image
        RowColumnClass getUpperLeft();
        //This function returns the location of the lower right point 
        //of the rectangle on the image
        RowColumnClass getLowerRight();
        //This function returns the color of the rectangle
        ColorClass getColor();
        //This function returns the filling option of the rectangle
        bool getFilling();
};

#endif // _RECTANGLECLASS_H_