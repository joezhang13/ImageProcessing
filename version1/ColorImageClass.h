#ifndef _COLORIMAGECLASS_H_
#define _COLORIMAGECLASS_H_

#include "Constants.h"
#include "RectangleClass.h"
#include "PatternClass.h"
#include "RowColumnClass.h"
#include "ColorClass.h"
#include "input.h"

//This class contains a collection of color objects arranged in a 
//dynamically allocated 2D array to represent a rectangular image.
//Users are allowed to do several operations on the image, such as
//reading from and writing to a file, annotating with rectangles 
//or specific patterns, inserting another image, etc. 
class ColorImageClass
{
    private:
        ColorClass **colorImage;
        string fileName;
        string imageType;
        int numRow;
        int numColumn;
        int maxColor;
    public:
        //This default constructor makes the colorImage a null pointer
        ColorImageClass();
        //This destructor releases the dynamically allocated memory
        ~ColorImageClass();
        //This function reads the PPM image file and stores the image 
        //in the object
        bool readImage(string fname);
        //This function writes the image to a PPM file
        bool writeImage(string fname);
        //This function reads a rectangle object and annotate the image
        //with this rectangle
        bool addRectangle(RectangleClass &rectangle);
        //This function reads a pattern object and annotate the image 
        //with this pattern
        bool addPattern(PatternClass &pattern);
        //This function reads an image, a specified location and a transparecy
        //color, then inserts it to the original image
        bool insertImage(ColorImageClass &rhsImage,
                         RowColumnClass &startLoc, 
                         ColorClass &emptyColor);
        //This function returns the pointer of the 2D array containing the 
        //colors of all the pixels in the image
        ColorClass **getColorImage();
        //This function returns the number of rows
        int getNumRow();
        //This function returns the number of columns
        int getNumColumn();
};

#endif // _COLORIMAGECLASS_H_