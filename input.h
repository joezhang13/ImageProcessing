#ifndef _INPUT_H_
#define _INPUT_H_

#include "constants.h"

//This function inputs an integer from the ifstream to a variable
//with error handling
bool input(ifstream &inFile, int &val);

//This function inputs an integer from the istream to a variable
//with error handling
bool input(istream &inStream, int &val);

//This function inputs two integers from the istream to two variables
//with error handling
bool input(istream &inStream, int &firstVal, int &secondVal);

#endif // _INPUT_H_