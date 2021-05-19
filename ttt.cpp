#include <iostream>
#include <vector>

#include "fun.hpp"

int main() {
  std::vector<std::vector<char>> board = {
  	{' ', ' ', ' '},
    {' ', ' ', ' '},
    {' ', ' ', ' '}
  };
  print_board(board);
}