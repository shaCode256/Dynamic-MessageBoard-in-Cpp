#pragma once
#include <string>
#include "Direction.hpp"
#include <stdexcept>
#include <map>
#include <iostream>
#include <cassert>

using ariel::Direction;

namespace ariel{

using namespace std;

    class Board{
        private:
            map<unsigned int, map<unsigned int, char>> charsMap;
        public:
            void post(unsigned int row, unsigned int col, Direction direction, string str);
            string read(unsigned int row, unsigned int col, Direction direction, unsigned int length);
            void show();
            void fill_empty_cells();

    };

}

	// board.post(/*row=*/100, /*column=*/200, Direction::Horizontal, "abcd");
	// cout << board.read(/*row=*/99, /*column=*/201, Direction::Vertical, /*length=*/3) << endl;  
	// 	// prints "_b_" (starts at row 99 which is empty; then at row 100 there is "b"; then row 101 is empty again).
	// board.post(/*row=*/99, /*column=*/202, Direction::Vertical, "xyz");
	// cout << board.read(/*row=*/100, /*column=*/200, Direction::Horizontal, /*length=*/6) << endl;  
	