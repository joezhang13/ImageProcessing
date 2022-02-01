#ifndef _ROWCOLUMNCLASS_H_
#define _ROWCOLUMNCLASS_H_

#include "constants.h"

//This class contains the row and column index values 
//to specify the location of a pixel in an image.
class RowColumnClass
{
    private:
        int row;
        int col;
    public:
        //This default constructor sets the initial row and column index 
        //values to the default constants.
        RowColumnClass();
        //This constructor sets the initial row and column index values 
        //to the provided values.
        RowColumnClass(int inRow, int inCol); 
        //This function sets the row and column index values 
        //to the provided values.
        void setRowCol(int inRow, int inCol);
        //This function sets the row index value to the provided value.
        void setRow(int inRow);
        //This function sets the column index value to the provided value.
        void setCol(int inCol);
        //This function returns the row index value of the object.
        int getRow();
        //This function returns the column index value of the object.
        int getCol();
        //This function adds the row and column index values 
        //of the input object to the row and column values 
        //of the object the function is called on.
        void addRowColTo(RowColumnClass &inRowCol);
        //This function prints the row index and the column index 
        //of the object to the screen.
        void printRowCol();
        //This function copies the row index and the column index of the 
        //input object to the object the function is called on.
        void setTo(RowColumnClass &inRowCol);
};

#endif // _ROWCOLUMNCLASS_H_