#include <vector>
#include <iostream>
#include "fun.hpp"
#include <stdlib.h> 

void print_board(std::vector<std::vector<char>> board) {
	for (int row = 0; row < 3; row++) {
		if (row == 2 || row == 1) {
			std::cout << "---|---|---\n";
		}
		for (int col = 0; col < 3; col++) {
    		std::cout << " " << board[row][col] << " ";
    		if (col == 0 || col == 1) {
    			std::cout << "|";
    		}
		}
		std::cout << "\n";
  	}
  	std::cout << "\n";
}

void game_start() {
	std::cout << "===========\n";
	std::cout << "TIC TAC TOE\n";
	std::cout << "===========\n";
	std::cout << "Two players take turn trying to get three in a row.\n\n";
}

void get_player_input(int player, std::vector<std::vector<char>> &board) {
	
	// Initialize Variables
	char player_token = (player == 1) ? 'x' : 'o';

	// What Row?
	int row = get_row(player, board);

	// What Column?
	int col = get_col(player, board[row]);
	
	// Add Player choice to board
	populate_board(player_token, board, row, col);

}

void populate_board(char player_token, std::vector<std::vector<char>> &board, int row, int col) {
	if (board[row][col] != ' ') {
		EXIT_FAILURE;
	} else {
		board[row][col] = player_token;
	}
	
}

int get_col(int player, std::vector<char> &row) {
	bool valid_input = false;
	int col;
	while (!valid_input) {
		std::cout << "Player " << player << ", what column [0, 1, 2]: ";
		std::cin >> col;
		if ( (col < 3 ) && ( col >= 0 ) && ( row[col] == ' ' ) ) {
			valid_input = true;
		} else {
			std::cout << "Provided column is invalid. Please try again.\n";
		}
	}
	std::cout << "\n";
	return col;
}

int get_row(int player, std::vector<std::vector<char>> &board) {
	bool valid_input = false;
	int row;
	while (!valid_input) {
		std::cout << "Player " << player << ", what row [0,1,2]: ";
		std::cin >> row;
		if ( (row < 3 ) && ( row >= 0 ) && ( row_slot_available(board[row]) ) ) {
			valid_input = true;
		} else {
			std::cout << "Provided row is invalid. Please try again.\n";
		}
	}
	return row;
}

bool row_slot_available(std::vector<char> &row) {
	int empty = 0;
	for (char col : row) {
		if (col == ' ') {
			empty += 1; 
		}
	}
	return empty > 0;
}

bool horizontal_win(char player_token, std::vector<std::vector<char>> &board) {
	bool horizontal_win;
	for (std::vector<char> row : board) {
		horizontal_win = true;
		for (char col : row) {
			if (col != player_token) {
				horizontal_win = false;
				break;
			}
		}
		if (horizontal_win) {
			return horizontal_win;
		}
	}
	return horizontal_win;
}

bool vertical_win(char player_token, std::vector<std::vector<char>> &board) {
	bool vertical_win;
	for (int col = 0; col < 3; col++) {
		vertical_win = true;
		for (int row = 0; row < 3; row++) {
			if (board[row][col] != player_token) {
				vertical_win = false;
				break;
			}
		}
		if (vertical_win) {
			return vertical_win;
		}
	}
	return vertical_win;
}

bool diagonal_win(char player_token, std::vector<std::vector<char>> &board) {

	// Check Top-Right to Bottom-Lef
	bool diagonal_win = true;
	for (int index = 0; index < 3; index++) {
		if (board[index][index] != player_token) {
			diagonal_win = false;
			break;
		}
	}
	if (diagonal_win) {
		return diagonal_win;
	}
	
	// Check Top-Left to Bottom-right
	diagonal_win = true;
	for (int index = 0; index < 3; index++) {
		if (board[index][2-index] != player_token) {
			diagonal_win = false;
			break;
		}
	}
	return diagonal_win;
}

bool check_victory(int player, std::vector<std::vector<char>> &board) {
	
	// Get player token of current player
	char player_token = (player == 1) ? 'x' : 'o';

	// Check if horizontal win condition holds
	if (horizontal_win(player_token, board)) {
		return true;

	// Check if vertical win condition holds
	} else if (vertical_win(player_token, board)) {
		return true;

	// Check if diagonal win condition holds
	} else if (diagonal_win(player_token, board)) {
		return true;

	// No winner yet
	} else {
		return false;
	}
}