#include "Board.hpp"
#include "Direction.hpp"
#include <string>
#include <iostream>
#include <stdexcept>

using namespace ariel;
using namespace std;

        void Board::post(unsigned int, unsigned int, ariel::Direction, string){
            cout << "post() demo here!" << endl;

        }

        string Board::read(unsigned int, unsigned int, ariel::Direction, unsigned int){
            return "123";

        }

        void Board::show(){
            cout << "show() demo here!" << endl;

        }
