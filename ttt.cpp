#include <iostream>
#include <vector>
#include "fun.hpp"

int main() {

	// Start the Game
	game_start();

	// Initialize Key Variables
	bool game_ongoing = true;
	int players[2] = {0, 1};
	std::vector<std::vector<char>> board = {
		{' ', ' ', ' '},
		{' ', ' ', ' '},
		{' ', ' ', ' '}
	};

	// 
	while (game_ongoing) {
		for (int player : players) {
			print_board(board);
			get_player_input(player, board);
		}
	}

	//
}