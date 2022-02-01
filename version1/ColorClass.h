#ifndef _COLORCLASS_H_
#define _COLORCLASS_H_

#include "Constants.h"
#include "input.h"

//This class contains 3 integers in the range from 0 to 255 
//to specify the RGB values of a color object.
class ColorClass
{
    private:
        int red;
        int green;
        int blue;
        //This function clips the invalid value to the valid range. 
        //If the value is less the the allowed minimum, it will be 
        //clipped to the minimum. If the value is larger than the maximum,
        //it will be clipped to the maximum. 
        void clip(int &inValue);
        //This function examines 3 component values. If any value needs 
        //clipping to be within the valid range, the function returns true,
        //otherwise it returns false.
        bool clipColor(int &inRed, int &inGreen, int &inBlue);
    public:
        //This default constructor sets the color object's initial RGB values 
        //to the values for white.
        ColorClass();
        //This constructor sets the color object's initial RGB values 
        //to the provided values.
        ColorClass(int inRed, int inGreen, int inBlue);
        //This function sets the RGB values to the values for black.
        void setToBlack();
        //This function sets the RGB values to the values for full red.
        void setToRed();
        //This function sets the RGB values to the values for full green.
        void setToGreen();
        //This function sets the RGB values to the values for full blue.
        void setToBlue();
        //This function sets the RGB values to the values for white.
        void setToWhite();
        //This function sets each RGB value to the corresponding input value.
        bool setTo(int inRed, int inGreen, int inBlue);
        //This function sets each RGB value to the corresponding value
        //from the input color.
        bool setTo(ColorClass &inColor);
        //This function causes each RGB value to have the corresponding value 
        //from the input color added to it.
        bool addColor(ColorClass &rhs);
        //This function causes each RGB value to have the corresponding value 
        //from the input color substracted from it.
        bool subtractColor(ColorClass &rhs);
        //This function adjusts the brightness of the color object 
        //by multiplying each RGB value by the adjustment factor provided.
        bool adjustBrightness(double adjFactor);
        //This function prints the component color values to the screen.
        void printComponentValues();
        //This function reads the RGB values from a file and stores them 
        //in the object.
        bool readFromFile(ifstream &inFile);
        //This function writes the RGB vaues of the object to a file.
        void writeToFile(ofstream &outFile);
        //This function returns true if the input color is the same as 
        //the object, false if they are not the same.
        bool isEqualTo(ColorClass &inColor);
};

#endif // _COLORCLASS_H_