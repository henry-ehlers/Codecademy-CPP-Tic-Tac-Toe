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
}

void game_start() {
	std::cout << "===========\n";
	std::cout << "TIC TAC TOE\n";
	std::cout << "===========\n";
	std::cout << "Two players take turn trying to get three in a row.\n";
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
		std::cout << "Player " << player << ", what column [0, 1, 2]?\n";
		std::cin >> col;
		if ( (col < 3 ) && ( col >= 0 ) && ( row[col] == ' ' ) ) {
			std::cout << "Column selected by player " << player << ": " << col << "\n"; 
			valid_input = true;
		} else {
			std::cout << "Provided column is invalid. Please try again.\n";
		}
	}
	return col;
}

int get_row(int player, std::vector<std::vector<char>> &board) {
	bool valid_input = false;
	int row;
	while (!valid_input) {
		std::cout << "Player " << player << ", what row [0,1,2]?\n";
		std::cin >> row;
		if ( (row < 3 ) && ( row >= 0 ) && ( row_slot_available(board[row]) ) ) {
			std::cout << "Row selected by player " << player << ": " << row << "\n"; 
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