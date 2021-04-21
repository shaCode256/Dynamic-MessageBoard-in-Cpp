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
        if (long(row) + length - 1 > usMaxSize) //check that the word can fit in the board
        {
            throw exception(); 
        }
        if (col + length - 1 > colMaxVal) //update colMaxVal
        {
            colMaxVal = col + length - 1;
        }
        if (long(col) + length - 1 > usMaxSize) //check that the word can fit in the board
        {
            throw exception(); //check that
        }
        for (unsigned int i = 0; i < length; i++)//insert the word in the map
        {
            charsMap[row][col] = str.at(i);
            col++;
        }
        break;
    }
    case (Direction::Vertical):
    {
        if (long(col) + length - 1 > usMaxSize) //check that the word can fit in the board
        {
            throw exception(); //check that
        }
        if (col + length - 1 > colMaxVal) //update colMaxVal
        {
            colMaxVal = col + length - 1;
        }
        if (row + length - 1 > rowMaxVal)//update the rowMaxVal
        {
            rowMaxVal = row + length - 1;
        }
        for (unsigned int i = 0; i < length; i++)//insert the word in the map
        {
            charsMap[row][col] = str.at(i);
            row++;
        }
        break;
    }
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
        if (long(row) + length - 1 > usMaxSize) //check that reading in in the board
        {
            throw exception(); 
        }
        for (unsigned int i = 0; i < length; i++)
        {
            word += 0== charsMap[row][col] ? '_' : charsMap[row][col];
            col++;
        }
        break;
    }
    case (Direction::Vertical):
    {
            if (long(col) + length - 1 > usMaxSize) //check that the reading in the board
        {
            throw exception(); //check that
        }
        for (unsigned int i = 0; i < length; i++)
        {
            word += 0== charsMap[row][col] ? '_' : charsMap[row][col];
            row++;
        }
        break;
    }
        throw exception(); //illegal direction
    }
    return word;
}

void Board::show()
{
    fill_empty_cells();
    
        for(unsigned int printRow= colMinVal; printRow<= colMaxVal+4; printRow++ ){ //print first row
            cout << "_";
        }
        cout << "\n";
        for (unsigned int row = rowMinVal; row <= rowMaxVal; row++)
        {
            cout << "__"; //print first __ to "add 2 columns"
            for (unsigned int col = colMinVal; col <= colMaxVal; col++)
            {
                cout << charsMap[row][col];
            }
            cout << "__"; //print first __ to "add 2 columns"
            cout << "\n"; //end of this line
        }

        for(unsigned int printRow= colMinVal; printRow<= colMaxVal+4; printRow++ ){ //print last row
            cout << "_";
        }
}

void Board::fill_empty_cells(){
    //filling the empty spaces
    for (unsigned int row = rowMinVal - 1; row <= rowMaxVal + 1; row++)
    {
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