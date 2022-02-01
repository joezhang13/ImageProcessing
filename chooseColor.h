#ifndef _CHOOSECOLOR_H_
#define _CHOOSECOLOR_H_

#include "constants.h"
#include "input.h"
#include "ColorClass.h"

//This function specifies the color based on the input of the user.
//If a valid choice is made, a color will be assigned and the function 
//will return true. Otherwise, the color will not be changed and it will
//return false
void chooseColor(ColorClass &color);

#endif // _CHOOSECOLOR_H_