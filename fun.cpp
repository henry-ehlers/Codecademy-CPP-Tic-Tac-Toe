#include <vector>
#include <iostream>

void print_board(std::vector<std::vector<char>> board) {
  for (int row; row < 3; row++) {
    for (int col; col < 3; col ++) {
      std::cout << board[row][col];
    }
    std::cout << "\n;";
  }
}