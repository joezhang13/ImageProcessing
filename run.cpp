#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#include "constants.h"
#include "RowColumnClass.h"
#include "ColorClass.h"
#include "RectangleClass.h"
#include "PatternClass.h"
#include "ColorImageClass.h"
#include "input.h"
#include "chooseColor.h"

//Changes made for re-submission:
//1. changed the name of the constant header file: Constants.h -> constants.h
//2. added the functionality to reject the ppm files which exceed 
//   the required length: ColorImageClass.cpp (lines 85-94)
//3. changed the constant name of the color options: constants.h (lines 31-36)
//4. combined several IF statements by the OR operator: 
//   PatternClass.cpp (lines 40-44), ColorImageClass.cpp (lines 51-57)
//5. added a global function chooseColor to display the color menu and
//   read the input color from the user: chooseColor.h, proj3.cpp 
//   (lines 200-201, 277-278, 315-317)
//6. used descriptive constants for printing the options in menu: proj3.cpp
//   (lines 55-62, 91-97, 208-210, 345-349), chooseColor.cpp (lines 14-19)

int main()
{
    bool runProgram = true;
    int option;
    ColorImageClass image;
    string inFileName;

    cout << "Enter string for PPM image file name to load: ";
    cin >> inFileName;
    runProgram = image.readImage(inFileName);
    if (!runProgram)
    {
        cout << "The main image can't be loaded! Program is ended..." << endl;
    }
    while (runProgram)
    {
        bool enterMainOption = false;
        while (!enterMainOption)
        {
            //used descriptive constants for printing menu
            cout << ADD_RECTANGLE << ".  Annotate image with " << 
                    "rectangle" << endl;
            cout << ADD_PATTERN << ".  Annotate image with " << 
                    "pattern from file" << endl;
            cout << INSERT_IMAGE << ".  Insert another image" << endl;
            cout << WRITE_IMAGE << ".  Write out current image" << endl;
            cout << EXIT_PROGRAM << ".  Exit the program" << endl;
            cout << "Enter int for main menu choice: ";
            enterMainOption = input(cin, option);
        }

        switch (option)
        {
            //annotate with rectangle
            case ADD_RECTANGLE:
            {
                int locOption;
                int row;
                int column;
                int width;
                int height;
                int halfWidth;
                int halfHeight;
                RowColumnClass upperLeft;
                RowColumnClass lowerRight;
                RowColumnClass center;
                RectangleClass rectangle;
                ColorClass color;
                int fillOption;
                bool filling;

                //specify the location
                bool enterLocOption = false;
                while (!enterLocOption)
                {
                    //used descriptive constants for printing menu
                    cout << TWO_CORNERS << ".  Specify upper left and " << 
                            "lower right corners of rectangle" << endl;
                    cout << CORNER_AND_LENGTH << ".  Specify upper left " <<
                            "corner and dimensions of rectangle" << endl;
                    cout << CENTER_AND_LENGTH << ".  Specify extent from " << 
                            "center of rectangle" << endl;
                    cout << "Enter int for rectangle specification method: ";
                    if (input(cin, locOption))
                    {
                        if (locOption >= TWO_CORNERS && 
                            locOption <= CENTER_AND_LENGTH)
                        {
                            enterLocOption = true;
                        }
                        else
                        {
                            cout << "Avaliable choices are " << TWO_CORNERS <<
                                    ", " << CORNER_AND_LENGTH << ", " <<
                                    CENTER_AND_LENGTH << ". "
                                    "Please enter again..." << endl;
                        }
                    }
                }
                
                switch (locOption)
                {
                    //specify upper left and lower right corners
                    case TWO_CORNERS:
                    {
                        bool enterCorners = false;
                        while (!enterCorners)
                        {
                            cout << "Enter upper left corner " << 
                                    "row and column: ";
                            enterCorners = input(cin, row, column);
                        }
                        upperLeft.setRowCol(row, column);
                        enterCorners = false;
                        while (!enterCorners)
                        {
                            cout << "Enter lower right corner " << 
                                    "row and column: ";
                            enterCorners = input(cin, row, column);
                        }
                        lowerRight.setRowCol(row, column);
                        break;
                    }
                    //specify upper left and the height and the width
                    case CORNER_AND_LENGTH:
                    {
                        bool enterCornerLength = false;
                        while (!enterCornerLength)
                        {
                            cout << "Enter upper left corner " << 
                                    "row and column: ";
                            enterCornerLength = input(cin, row, column);
                        }
                        upperLeft.setRowCol(row, column);
                        enterCornerLength = false;
                        while (!enterCornerLength)
                        {
                            cout << "Enter int for number of rows: ";
                            enterCornerLength = input(cin, height);
                        }
                        enterCornerLength = false;
                        while (!enterCornerLength)
                        {
                            cout << "Enter int for number of columns: ";
                            enterCornerLength = input(cin, width);
                        }
                        row  = upperLeft.getRow() + height;
                        column = upperLeft.getCol() + width;
                        lowerRight.setRowCol(row, column);
                        break;
                    }
                    //specify center and the half height and the half width
                    case CENTER_AND_LENGTH:
                    {
                        bool enterCenterLength = false;
                        while (!enterCenterLength)
                        {
                            cout << "Enter rectangle center row and column: ";
                            enterCenterLength = input(cin, row, column);
                        }
                        center.setRowCol(row, column);
                        enterCenterLength = false;
                        while (!enterCenterLength)
                        {
                            cout << "Enter int for half number of rows: ";
                            enterCenterLength = input(cin, halfHeight);
                        }
                        enterCenterLength = false;
                        while (!enterCenterLength)
                        {
                            cout << "Enter int for half number of columns: ";
                            enterCenterLength = input(cin, halfWidth);
                        }
                        row = center.getRow() - halfHeight;
                        column = center.getCol() - halfWidth;
                        upperLeft.setRowCol(row, column);
                        row = center.getRow() + halfHeight;
                        column = center.getCol() + halfWidth;
                        lowerRight.setRowCol(row, column);
                        break;
                    }
                }
                rectangle.setLocation(upperLeft, lowerRight);

                //specify the color by the added chooseColor function
                chooseColor(color);
                rectangle.setColor(color);

                //specify the filling option
                bool enterFilling = false;
                while (!enterFilling)
                {
                    //used descriptive constants for printing menu
                    cout << NOT_FILLED << ".  No" << endl;
                    cout << FILLED << ".  Yes" << endl;
                    cout << "Enter int for rectangle fill option: ";
                    if (input(cin, fillOption))
                    {
                        if (fillOption >= NOT_FILLED && fillOption <= FILLED)
                        {
                            enterFilling = true;
                        }
                        else
                        {
                            cout << "Avaliable choices are " << NOT_FILLED <<
                                    ", " << FILLED << ". " <<
                                    "Please enter again..." << endl;
                        }
                    }
                }
    
                switch (fillOption)
                {
                    case NOT_FILLED:
                    {
                        filling = false;
                        break;
                    }
                    case FILLED:
                    {
                        filling = true;
                        break;
                    }
                }
                rectangle.setFilling(filling);

                image.addRectangle(rectangle);
                break;
            }

            //annotate with pattern from file
            case ADD_PATTERN:
            {
                string fname;
                PatternClass pattern;
                RowColumnClass upperLeft;
                int row;
                int column;
                ColorClass color;

                //read the pattern from file
                cout << "Enter string for file name containing pattern: ";
                cin >> fname;
                
                if(!pattern.readPattern(fname))
                {
                    break;
                }

                //specify the location of the pattern
                bool enterLocPattern = false;
                while (!enterLocPattern)
                {
                    cout << "Enter upper left corner of pattern " << 
                            "row and column: ";
                    enterLocPattern = input(cin, row, column);
                }
                
                upperLeft.setRowCol(row, column);
                pattern.setUpperLeft(upperLeft);

                //specify the color by the added chooseColor function
                chooseColor(color);
                pattern.setColor(color);

                image.addPattern(pattern);
                break;
            }

            //insert another image
            case INSERT_IMAGE:
            {
                string insertedFileName;
                ColorImageClass insertedImage;
                int row;
                int column;
                RowColumnClass upperLeft;
                ColorClass emptyColor;

                //read the image from file
                cout << "Enter string for file name of PPM image to insert: ";
                cin >> insertedFileName;
                
                if (!insertedImage.readImage(insertedFileName))
                {
                    break;
                }

                //specify the location of the inserted image
                bool enterLocImage = false;
                while (!enterLocImage)
                {
                    cout << "Enter upper left corner to insert " << 
                        "image row and column: ";
                    enterLocImage = input(cin, row, column);
                }
                
                upperLeft.setRowCol(row, column);

                //specify the transparecy color by the added 
                //chooseColor function
                chooseColor(emptyColor);

                image.insertImage(insertedImage, upperLeft, emptyColor);
                break;
            }

            //write image to file
            case WRITE_IMAGE:
            {
                string outFileName;

                cout << "Enter string for PPM file name to output: ";
                cin >> outFileName;
                
                image.writeImage(outFileName);
                break;
            }

            //exit the program
            case EXIT_PROGRAM:
            {
                cout << "Thank you for using this program" << endl;
                runProgram = false;
                break;
            }

            default:
            {
                //used descriptive constants for printing menu
                cout << "Avaliable choices are " << ADD_RECTANGLE << ", " <<
                        ADD_PATTERN << ", " << INSERT_IMAGE << ", " <<
                        WRITE_IMAGE << ", " << EXIT_PROGRAM << ". " << 
                        "Please enter again..." << endl;
            }
        }
    }

    return 0;
}
