#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#include "Constants.h"
#include "RowColumnClass.h"
#include "ColorClass.h"
#include "RectangleClass.h"
#include "PatternClass.h"
#include "ColorImageClass.h"
#include "input.h"

//Name: Zhou Zhang
//Date: 11/04/2019
//Purpose: This project provides the users with the functions of
//reading images from PPM files, writing images to PPM files, 
//annotating images with rectangles and file-specified patterns,
//as well as inserting other images. It also includes the error
//handling for stream input/output

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
            cout << "1.  Annotate image with rectangle" << endl;
            cout << "2.  Annotate image with pattern from file" << endl;
            cout << "3.  Insert another image" << endl;
            cout << "4.  Write out current image" << endl;
            cout << "5.  Exit the program" << endl;
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
                int colorOption;
                ColorClass color;
                int fillOption;
                bool filling;

                //specify the location
                bool enterLocOption = false;
                while (!enterLocOption)
                {
                    cout << "1.  Specify upper left and lower right " << 
                            "corners of rectangle" << endl;
                    cout << "2.  Specify upper left corner and dimensions " <<
                            "of rectangle" << endl;
                    cout << "3.  Specify extent from center of " << 
                            "rectangle" << endl;
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
                            cout << "Avaliable choices are 1,2,3. " << 
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

                //specify the color
                bool enterColor = false;
                while (!enterColor)
                {
                    cout << "1.  Red" << endl;
                    cout << "2.  Green" << endl;
                    cout << "3.  Blue" << endl;
                    cout << "4.  Black" << endl;
                    cout << "5.  White" << endl;
                    cout << "Enter int for rectangle color: ";
                    if (input(cin, colorOption))
                    {
                        if (colorOption >= RED && colorOption <= WHITE)
                        {
                            enterColor = true;
                        }
                        else
                        {
                            cout << "Avaliable choices are 1,2,3,4,5. " << 
                                "Please enter again..." << endl;
                        }
                    }
                }

                switch (colorOption)
                {
                    case RED:
                    {
                        color.setToRed();
                        break;
                    }
                    case GREEN:
                    {
                        color.setToGreen();
                        break;
                    }
                    case BLUE:
                    {
                        color.setToBlue();
                        break;
                    }
                    case BLACK:
                    {
                        color.setToBlack();
                        break;
                    }
                    case WHITE:
                    {
                        color.setToWhite();
                        break;
                    }
                }
                rectangle.setColor(color);

                //specify the filling option
                bool enterFilling = false;
                while (!enterFilling)
                {
                    cout << "1.  No" << endl;
                    cout << "2.  Yes" << endl;
                    cout << "Enter int for rectangle fill option: ";
                    if (input(cin, fillOption))
                    {
                        if (fillOption >= NOT_FILLED && fillOption <= FILLED)
                        {
                            enterFilling = true;
                        }
                        else
                        {
                            cout << "Avaliable choices are 1,2. " << 
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
                int colorOption;
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

                //specify the color
                bool enterColor = false;
                while (!enterColor)
                {
                    cout << "1.  Red" << endl;
                    cout << "2.  Green" << endl;
                    cout << "3.  Blue" << endl;
                    cout << "4.  Black" << endl;
                    cout << "5.  White" << endl;
                    cout << "Enter int for pattern color: ";
                    if (input(cin, colorOption))
                    {
                        if (colorOption >= RED && colorOption <= WHITE)
                        {
                            enterColor = true;
                        }
                        else
                        {
                            cout << "Avaliable choices are 1,2,3,4,5. " << 
                                "Please enter again..." << endl;
                        }
                    }
                }

                switch (colorOption)
                {
                    case RED:
                    {
                        color.setToRed();
                        break;
                    }
                    case GREEN:
                    {
                        color.setToGreen();
                        break;
                    }
                    case BLUE:
                    {
                        color.setToBlue();
                        break;
                    }
                    case BLACK:
                    {
                        color.setToBlack();
                        break;
                    }
                    case WHITE:
                    {
                        color.setToWhite();
                        break;
                    }
                }
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
                int colorOption;
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

                //specify the transparecy color
                bool enterColor = false;
                while (!enterColor)
                {
                    cout << "1.  Red" << endl;
                    cout << "2.  Green" << endl;
                    cout << "3.  Blue" << endl;
                    cout << "4.  Black" << endl;
                    cout << "5.  White" << endl;
                    cout << "Enter int for transparecy color: ";
                    if (input(cin, colorOption))
                    {
                        if (colorOption >= RED && colorOption <= WHITE)
                        {
                            enterColor = true;
                        }
                        else
                        {
                            cout << "Avaliable choices are 1,2,3,4,5. " << 
                                "Please enter again..." << endl;
                        }
                    }
                }

                switch (colorOption)
                {
                    case RED:
                    {
                        emptyColor.setToRed();
                        break;
                    }
                    case GREEN:
                    {
                        emptyColor.setToGreen();
                        break;
                    }
                    case BLUE:
                    {
                        emptyColor.setToBlue();
                        break;
                    }
                    case BLACK:
                    {
                        emptyColor.setToBlack();
                        break;
                    }
                    case WHITE:
                    {
                        emptyColor.setToWhite();
                        break;
                    }
                }

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
                cout << "Avaliable choices are 1,2,3,4,5. " << 
                        "Please enter again..." << endl;
            }
        }
    }

    return 0;
}