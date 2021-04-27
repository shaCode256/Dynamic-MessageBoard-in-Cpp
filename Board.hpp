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