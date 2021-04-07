/**
 * Demo program for message-board exercise.
 * 
 * Author: Erel Segal-Halevi
 * Since : 2021-03
 */
#include <cmath>
#include <array>
#include "Board.hpp"
#include "doctest.h"
using namespace ariel;

#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>
using namespace std;
#include "Board.hpp"
#include "Direction.hpp"
using ariel::Direction;

#include <iostream>
#include <stdexcept>

int main()
{
	ariel::Board board;
	board.post(/*row=*/100, /*column=*/200, Direction::Horizontal, "abcd");
	//	cout << board.read(/*row=*/99, /*column=*/201, Direction::Vertical, /*length=*/3) << endl;
	// prints "_b_" (starts at row 99 which is empty; then at row 100 there is "b"; then row 101 is empty again).
	board.post(/*row=*/99, /*column=*/202, Direction::Vertical, "xyz");
	//	cout << board.read(/*row=*/100, /*column=*/200, Direction::Horizontal, /*length=*/6) << endl;
	// prints "abyd__" (First letters are ab; then y from the "xyz"; then d; then two empty cells).

	cout << "\n now showing the board \n";
	board.show(); // shows the board in a reasonable way. For example:
				  //    98   _________
				  //    99:  ____x____
				  //    100: __abyd___
				  //    101: ____z____
				  //    102: _________

	// _________
	// ___x____
	// ___abyd_
	// ___z____
	// _________

	// ________
	// ____x___
	// __abyd__
	// ____z___
	// ________

	// ________
	// ___x___
	// __abyd__
	// ___z___
	// ________
}
