 /* 

 *
 * TEST FOR SNOWMAN.CPP
 *
 * AUTHOR: Shavit Luzon
 *
 * Date: 2021-03
 *

*/

#include "Board.hpp"
#include "Direction.hpp"
#include "doctest.h"
#include <stdexcept>
#include <iostream>
#include <cmath>
#include "doctest.h"
#include <string>
using namespace std;
using namespace ariel; 

/* 
  Functions to check: read, post.
 */

TEST_CASE("Overwriting existing posts") {

    ariel::Board board;

    board.post(/*row=*/100, /*column=*/200, Direction::Horizontal, "abcd");
	CHECK(board.read(/*row=*/99, /*column=*/201, Direction::Vertical, /*length=*/3) == "_b_"); 
	// prints "_b_" (starts at row 99 which is empty; then at row 100 there is "b"; then row 101 is empty again).

	board.post(/*row=*/99, /*column=*/202, Direction::Vertical, "xyz");
	CHECK(board.read(/*row=*/100, /*column=*/200, Direction::Horizontal, /*length=*/6)== "abyd__");  
	// prints "abyd__" (First letters are ab; then y from the "xyz"; then d; then two empty cells).

    board.post(/*row=*/0, /*column=*/0, Direction::Vertical, "11111");
    board.post(/*row=*/1, /*column=*/0, Direction::Vertical, "2");
    board.post(/*row=*/2, /*column=*/0, Direction::Vertical, "3");

	CHECK(board.read(/*row=*/0, /*column=*/0, Direction::Vertical, /*length=*/5)== "12311");  
    board.post(/*row=*/4, /*column=*/0, Direction::Vertical, "45");

	CHECK(board.read(/*row=*/0, /*column=*/0, Direction::Vertical, /*length=*/1)== "1");  
	CHECK(board.read(/*row=*/0, /*column=*/0, Direction::Vertical, /*length=*/2)== "12");  
	CHECK(board.read(/*row=*/0, /*column=*/0, Direction::Vertical, /*length=*/3)== "123");  
	CHECK(board.read(/*row=*/0, /*column=*/0, Direction::Vertical, /*length=*/4)== "1231");  
    board.post(/*row=*/0, /*column=*/0, Direction::Vertical, "12345");
	CHECK(board.read(/*row=*/0, /*column=*/0, Direction::Vertical, /*length=*/5)== "12345");  
 
}

TEST_CASE("Not enough space for the required word to be posted- out of range") {
    ariel::Board board;

	CHECK_THROWS_AS(board.post(/*row=*/0, /*column=*/65535, Direction::Vertical, "12345"), out_of_range);  
	CHECK_THROWS_AS(board.post(/*row=*/65535, /*column=*/65535, Direction::Vertical, "12345678910"), out_of_range);  
	CHECK_THROWS_AS(board.post(/*row=*/0, /*column=*/65535, Direction::Vertical, "123"), out_of_range);  
	CHECK_THROWS_AS(board.post(/*row=*/65535, /*column=*/65535, Direction::Vertical, "12"), out_of_range);  
	CHECK_THROWS_AS(board.post(/*row=*/65535, /*column=*/65535, Direction::Vertical, "1"), out_of_range);  
	CHECK_THROWS_AS(board.post(/*row=*/65533, /*column=*/65535, Direction::Vertical, "123456"), out_of_range);  
	CHECK_THROWS_AS(board.post(/*row=*/65532, /*column=*/0, Direction::Vertical, "1234567"), out_of_range);  
	CHECK_THROWS_AS(board.post(/*row=*/65531, /*column=*/65535, Direction::Vertical, "12345678"), out_of_range);  
	CHECK_THROWS_AS(board.post(/*row=*/65530, /*column=*/65535, Direction::Vertical, "12"), out_of_range);  
	CHECK_THROWS_AS(board.post(/*row=*/65534, /*column=*/0, Direction::Vertical, "12"), out_of_range);  
}


TEST_CASE("Word cannot be read from the location- out of range") {
    ariel::Board board;

	CHECK_THROWS_AS(board.read(/*row=*/0, /*column=*/65535, Direction::Vertical, /*length=*/5), out_of_range);  
	CHECK_THROWS_AS(board.read(/*row=*/65535, /*column=*/65535, Direction::Vertical, /*length=*/45), out_of_range);  
	CHECK_THROWS_AS(board.read(/*row=*/0, /*column=*/65535, Direction::Vertical, /*length=*/3), out_of_range);  
	CHECK_THROWS_AS(board.read(/*row=*/65535, /*column=*/0, Direction::Vertical, /*length=*/2), out_of_range);  
	CHECK_THROWS_AS(board.read(/*row=*/65535, /*column=*/65535, Direction::Vertical, /*length=*/1), out_of_range);  
	CHECK_THROWS_AS(board.read(/*row=*/65533, /*column=*/0, Direction::Vertical, /*length=*/5), out_of_range);  
	CHECK_THROWS_AS(board.read(/*row=*/65532, /*column=*/0, Direction::Vertical, /*length=*/5), out_of_range);  
	CHECK_THROWS_AS(board.read(/*row=*/65531, /*column=*/65535, Direction::Vertical, /*length=*/5), out_of_range);  
	CHECK_THROWS_AS(board.read(/*row=*/65530, /*column=*/65535, Direction::Vertical, /*length=*/25), out_of_range);  
	CHECK_THROWS_AS(board.read(/*row=*/65542, /*column=*/0, Direction::Vertical, /*length=*/55), out_of_range);  
}

TEST_CASE("Reading a 'random' empty place in the board") {
	ariel::Board board;
	CHECK(board.read(/*row=*/0, /*column=*/0, Direction::Vertical, /*length=*/4)== "____");  
	CHECK(board.read(/*row=*/30, /*column=*/0, Direction::Vertical, /*length=*/3)== "___");  
	CHECK(board.read(/*row=*/6, /*column=*/5, Direction::Vertical, /*length=*/2)== "__");
	CHECK(board.read(/*row=*/10, /*column=*/0, Direction::Vertical, /*length=*/4)== "____");  
	CHECK(board.read(/*row=*/20, /*column=*/0, Direction::Vertical, /*length=*/3)== "___");  
	CHECK(board.read(/*row=*/50, /*column=*/5, Direction::Vertical, /*length=*/2)== "__");  
	CHECK(board.read(/*row=*/0, /*column=*/6, Direction::Vertical, /*length=*/4)== "____");  
	CHECK(board.read(/*row=*/40, /*column=*/7, Direction::Vertical, /*length=*/3)== "___");  
	CHECK(board.read(/*row=*/6, /*column=*/89, Direction::Vertical, /*length=*/2)== "__");  
	CHECK(board.read(/*row=*/17, /*column=*/0, Direction::Vertical, /*length=*/4)== "____");  
	CHECK(board.read(/*row=*/30, /*column=*/9, Direction::Vertical, /*length=*/3)== "___");  
	CHECK(board.read(/*row=*/6, /*column=*/95, Direction::Vertical, /*length=*/2)== "__");    
}