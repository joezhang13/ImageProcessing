#ifndef _CONSTANTS_H_
#define _CONSTANTS_H_

//default values
const int MIN_COLOR = 0;
const int MAX_COLOR = 255;
const int DEFAULT_ROW_COL = 0;
const int PATTERN_SOLID = 1;
const int PATTERN_EMPTY = 0;
const int NUM_IGNORE = 200;
const char CHAR_IGNORE = '\n';
const string MAGIC_NUMBER = "P3";
const string DEFAULT_NAME = "Default.ppm";

//main menu options
const int ADD_RECTANGLE = 1;
const int ADD_PATTERN = 2;
const int INSERT_IMAGE = 3;
const int WRITE_IMAGE = 4;
const int EXIT_PROGRAM = 5;

//rectangle specifying options
const int TWO_CORNERS = 1;
const int CORNER_AND_LENGTH = 2;
const int CENTER_AND_LENGTH = 3;

//rectangle filling options
const int NOT_FILLED = 1;
const int FILLED = 2;

//color options
const int RED = 1;
const int GREEN = 2;
const int BLUE = 3;
const int BLACK = 4;
const int WHITE = 5;

#endif // _CONSTANTS_H_