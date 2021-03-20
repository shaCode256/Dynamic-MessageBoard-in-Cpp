#pragma once
#include <string>
#include "Direction.hpp"
using ariel::Direction;

namespace ariel{

using namespace std;

    class Board{
        public:
        void post(unsigned int, unsigned int, Direction, string);
        string read(unsigned int, unsigned int, Direction, unsigned int);
        void show();

    };
}

	// board.post(/*row=*/100, /*column=*/200, Direction::Horizontal, "abcd");
	// cout << board.read(/*row=*/99, /*column=*/201, Direction::Vertical, /*length=*/3) << endl;  
	// 	// prints "_b_" (starts at row 99 which is empty; then at row 100 there is "b"; then row 101 is empty again).
	// board.post(/*row=*/99, /*column=*/202, Direction::Vertical, "xyz");
	// cout << board.read(/*row=*/100, /*column=*/200, Direction::Horizontal, /*length=*/6) << endl;  
	