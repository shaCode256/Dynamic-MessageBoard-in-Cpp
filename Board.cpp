#include "Board.hpp"
#include "Direction.hpp"
#include <string>
#include <iostream>
#include <stdexcept>
#include <map>
#include <iostream>
#include <cassert>

using namespace ariel;
using namespace std;

const unsigned int usMaxSize = 4294967295;

unsigned int rowMinVal = usMaxSize;
unsigned int rowMaxVal = 0;
unsigned int colMinVal = usMaxSize;
unsigned int colMaxVal = 0;

void Board::post(unsigned int row, unsigned int col, ariel::Direction direction, string str)
{
    unsigned int length = str.length();
    if (row < rowMinVal)
    {
        rowMinVal = row;
    }
    if (col < colMinVal)
    {
        colMinVal = col;
    }
    switch (direction)
    {
    case (Direction::Horizontal):
    { //left to right- horizontal
        if (long(row) + length - 1 > usMaxSize)
        {
            throw exception(); //check that
        }
        if (col + length - 1 > colMaxVal)
        {
            colMaxVal = col + length - 1;
        }

        for (unsigned int i = 0; i < length; i++)
        {
            charsMap[row][col] = str.at(i);
            col++;
        }
        break;
    }
    case (Direction::Vertical):
    {
        if (long(col) + length - 1 > usMaxSize)
        {
            throw exception(); //check that
        }
        if (row + length - 1 > rowMaxVal)
        {
            rowMaxVal = row + length - 1;
        }
        for (unsigned int i = 0; i < length; i++)
        {
            charsMap[row][col] = str.at(i);
            row++;
        }
        break;
    }
        //else:
        throw exception(); //illegal direction
    }
}

string Board::read(unsigned int row, unsigned int col, ariel::Direction direction, unsigned int length)
{
    fill_empty_cells();
    string word;
    switch (direction)
    {
    case (Direction::Horizontal):
    { //left to right- horizontal
        for (unsigned int i = 0; i < length; i++)
        {
            word += charsMap[row][col];
            col++;
        }
        break;
    }
    case (Direction::Vertical):
    {
        for (unsigned int i = 0; i < length; i++)
        {
            word = word += charsMap[row][col];
            row++;
        }
        break;
    }
        //else:
        throw exception(); //illegal direction
    }
    return word;
}

void Board::show()
{
    fill_empty_cells();
    //printing out the whole charsMap
    for (unsigned int row = rowMinVal - 1; row <= rowMaxVal + 1; row++)
    {
        for (unsigned int col = colMinVal - 2; col <= colMaxVal + 2; col++)
        {
            cout << charsMap[row][col];
        }
        // if (row < rowMaxVal+1)
        // {
        cout << "\n"; //end of this line
        // }
    }

    // cout << "\n"
    // "maxcol is "
    // << colMaxVal << "\n";
    // cout << "mincol is " << colMinVal << "\n";
    // cout << "maxrow is " << rowMaxVal << "\n";
    // cout << "minrow is " << rowMinVal << "\n";
}

void Board::fill_empty_cells(){
    //filling the empty spaces
    for (unsigned int row = rowMinVal - 1; row <= rowMaxVal + 1; row++)
    {
        //cout << "colMaxVal is: " << colMaxVal << "\n";
        for (unsigned int col = colMinVal - 2; col <= colMaxVal + 2; col++)
        {
            if (charsMap.find(row) == charsMap.end()) // row not found
            {
                charsMap[row][col] = '_'; //will do it for all the row: will do all columns
            }
            else
            {                                                       //row is found, check if col
                if (charsMap[row].find(col) == charsMap[row].end()) //if col not found
                {
                    charsMap[row][col] = '_';
                }
            }
        }
    }
}




// Some reference:
// https://stackoverflow.com/questions/26281979/c-loop-through-map
// https://stackoverflow.com/questions/22889347/how-can-i-print-the-content-of-mapstring-mapint-int-to-cout