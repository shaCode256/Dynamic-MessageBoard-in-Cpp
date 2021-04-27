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
        if (long(col) + length - 1 > usMaxSize) //check that the word can fit in the board
        {
            throw exception(); 
        }
        if (col + length - 1 > colMaxVal) //update colMaxVal
        {
            colMaxVal = col + length - 1;
        }
        if (long(row) > usMaxSize) //check that the row is in the board
        {
            throw exception(); //check that
        }
        if (row > rowMaxVal) //update rowMaxVal
        {
            rowMaxVal = row;
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
        if (long(row) + length - 1 > usMaxSize) //check that the word can fit in the board
        {
            throw exception(); //check that
        }
        if (col > colMaxVal) //update colMaxVal
        {
            colMaxVal = col;
        }
        if (long(col) > usMaxSize) //check that the col is in the board
        {
            throw exception(); //check that
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
        cout << "\n";
        for (unsigned int row = rowMinVal; row <= rowMaxVal; row++)
        {
            for (unsigned int col = colMinVal; col <= colMaxVal; col++)
            {
                cout << charsMap[row][col];
            }
            cout << "\n"; //end of this line
        }
}

void Board::fill_empty_cells(){
    //filling the empty spaces
    for (unsigned int row = rowMinVal; row <= rowMaxVal; row++)
    {
        for (unsigned int col = colMinVal; col <= colMaxVal; col++)
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