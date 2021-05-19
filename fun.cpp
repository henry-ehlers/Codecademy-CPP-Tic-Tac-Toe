#include <vector>
#include <iostream>

void print_board(std::vector<std::vector<char>> board) {
	for (int row = 0; row < 3; row++) {
		if (row == 2 || row == 1) {
			std::cout << "-|-|-\n";
		}
		for (int col = 0; col < 3; col++) {
    		std::cout << board[row][col];
    		if (col == 0 || col == 1) {
    			std::cout << "|";
    		}
		}
		std::cout << "\n";
  	}
}