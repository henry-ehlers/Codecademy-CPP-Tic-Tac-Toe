#include <iostream>
#include <vector>
#include "fun.hpp"

int main() {

	// Start the Game
	game_start();

	// Initialize Key Variables
	bool game_ongoing = true;
	int players[2] = {0, 1};
	int fields_remaining = 3*3;
	int winner = -1;

	// Intialize an empty board
	std::vector<std::vector<char>> board = {
		{' ', ' ', ' '},
		{' ', ' ', ' '},
		{' ', ' ', ' '}
	};

	// Game Loop
	while (game_ongoing) {

		// Iterate over each of the two players
		for (int player : players) {

			// Display the current state of the board
			print_board(board);

			// Get the current player's input
			get_player_input(player, board);

			// check whether player has wone
			if (check_victory(player, board)) {
				game_ongoing = false;
				winner = player;
				break;
			}

			// check whether board is completely filled
			if (fields_remaining-- == 0) {
				game_ongoing = false;
				break;
			}
		}
	}

	// print endgame
	if (winner == -1) {
		std::cout << "A Draw!\n";
	} else {
		std::cout << "Congratulation to Player " << winner << " for winning this round of TIC TAC TOE!\n";
	}
}