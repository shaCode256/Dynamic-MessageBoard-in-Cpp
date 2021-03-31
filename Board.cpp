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

const unsigned int usMaxSize= 4294967295;

map<unsigned int, map<unsigned int, char>> charsMap;
unsigned int rowMinVal = usMaxSize;
unsigned int rowMaxVal = 0;
unsigned int colMinVal = usMaxSize;
unsigned int colMaxVal = 0;

void Board::post(unsigned int row, unsigned int col, ariel::Direction direction, string str)
{
    unsigned int length= str.length();
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
        if (long(row)+length > usMaxSize ){
            throw exception(); //check that
        }
        if (col+length > colMaxVal)
        {
            colMaxVal = col+length;
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
        if (long(col)+length > usMaxSize ){
            throw exception(); //check that
        }
        if (row+length > rowMaxVal)
            {
                rowMaxVal = row+length; 
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
    string word;
    switch (direction)
    {
    case (Direction::Horizontal):
    { //left to right- horizontal
        for (unsigned int i = 0; i < length; i++)
        {
            word+= charsMap[row][col];
            col++;
        }
        break;
    }
    case (Direction::Vertical):
    {
        for (unsigned int i = 0; i < length; i++)
        {
            word = word+= charsMap[row][col];
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
    // if(rowMinVal > 0){
    //     cout << "_";
    // }
    // if(colMinVal > 0){
    //     for (unsigned int i = 0; i < rowMaxVal; i++)
    //     {
    //         cout << "_" << "\n";
    //     }

    for (unsigned int row = rowMinVal; row <= rowMaxVal; row++)
    {
     //   cout << row << ": ";
        for (unsigned int col = colMinVal; col <= colMaxVal; col++)
        {
            if (charsMap.find(row) == charsMap.end()) // row not found
            {
                cout  << "_"; //will do it for all the row: will do all columns
            }
            else
            {                                                       //row is found, check if col
                if (charsMap[row].find(col) == charsMap[row].end()) //if col not found
                {
                    cout << "_";
                }
                else
                { //yes col & yes row!
                    cout << charsMap[row][col];
                }
            }
        }
        cout << "\n"; //end of this line
    }

    cout<< "\n" "maxcol is "<< colMaxVal << "\n";
    cout << "mincol is "<< colMinVal << "\n";
    cout<< "maxrow is "<< rowMaxVal << "\n";
    cout << "minrow is "<< rowMinVal << "\n";

}

// map<unsigned int, map<unsigned int, char>>::iterator it;
// for (map<unsigned int, map<unsigned int, char>>::iterator it = charsMap.begin(); it != charsMap.end(); ++it)
// {
//     map<unsigned int, char> &internal_map = it->second;
//     for (map<unsigned int, char>::iterator it2 = internal_map.begin(); it2 != internal_map.end(); ++it2)
//     {
//         if (it2 != internal_map.begin())
//             cout << it2->second; //which is the char
//     }
//     cout << endl;
// }
//}

// https://stackoverflow.com/questions/26281979/c-loop-through-map
//https://stackoverflow.com/questions/22889347/how-can-i-print-the-content-of-mapstring-mapint-int-to-cout