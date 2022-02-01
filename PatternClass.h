#ifndef _PATTERNCLASS_H_
#define _PATTERNCLASS_H_

#include "constants.h"
#include "RowColumnClass.h"
#include "ColorClass.h"
#include "input.h"

//This class contains a dynamically allocated 2D array of zeros and ones to 
//represent a pattern. The location of the pattern on the image, the numbers
//of rows and columns and the color of the pattern are also stored in it.
class PatternClass
{
    private:
        RowColumnClass upperLeft;
        int numRow;
        int numColumn;
        ColorClass color;
        int **pattern;
    public:
        //This default constructor makes the pattern an empty pointer
        PatternClass();
        //This destructor releases the dynamically allocated memory
        ~PatternClass();
        //This function reads the data from file and stores the pattern object
        bool readPattern(string fname);
        //This function specifies the location of the upper left point of 
        //the pattern on the image
        void setUpperLeft(RowColumnClass &uL);
        //This function specifies the color of the pattern
        void setColor(ColorClass &inColor);
        //This function returns the location of the upper left point of 
        //the pattern on the image
        RowColumnClass getUpperLeft();
        //This function returns the location of the lower right point of
        //the pattern on the image
        RowColumnClass getLowerRight();
        //This function returns the color of the pattern
        ColorClass getColor();
        //This function returns the pointer of the 2D array of integers
        //representing the pattern
        int **getPattern();
};

#endif // _PATTERNCLASS_H_