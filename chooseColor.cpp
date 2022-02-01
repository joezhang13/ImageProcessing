#include <iostream>
#include <fstream>
using namespace std;

#include "chooseColor.h"

void chooseColor(ColorClass &color)
{
    bool enterColor = false;
    int colorOption;

    while (!enterColor)
    {
        //used descriptive constants for printing menu
        cout << RED_OPTION << ".  Red" << endl;
        cout << GREEN_OPTION << ".  Green" << endl;
        cout << BLUE_OPTION << ".  Blue" << endl;
        cout << BLACK_OPTION << ".  Black" << endl;
        cout << WHITE_OPTION << ".  White" << endl;
        cout << "Enter int for rectangle color: ";
        if (input(cin, colorOption))
        {
            if (colorOption >= RED_OPTION && 
                colorOption <= WHITE_OPTION)
            {
                enterColor = true;
            }
            else
            {
                cout << "Avaliable choices are " << RED_OPTION << ", " <<
                        GREEN_OPTION << ", " << BLUE_OPTION << ", " <<
                        BLACK_OPTION << ", " << WHITE_OPTION << ". " << 
                        "Please enter again..." << endl;
            }
        }
    }

    switch (colorOption)
    {
        case RED_OPTION:
        {
            color.setToRed();
            break;
        }
        case GREEN_OPTION:
        {
            color.setToGreen();
            break;
        }
        case BLUE_OPTION:
        {
            color.setToBlue();
            break;
        }
        case BLACK_OPTION:
        {
            color.setToBlack();
            break;
        }
        case WHITE_OPTION:
        {
            color.setToWhite();
            break;
        }
    }
}