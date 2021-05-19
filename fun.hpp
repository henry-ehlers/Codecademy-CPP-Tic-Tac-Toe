void print_board(std::vector<std::vector<char>> board);

void check_victory_condition(std::vector<std::vector<char>> &board);

void get_player_input(int player, std::vector<std::vector<char>> &board);

void game_start();

void game_end();

bool row_slot_available(std::vector<char> &row);

int get_row(int player, std::vector<std::vector<char>> &board);

int get_col(int player, std::vector<char> &row);

void populate_board(char player_token, std::vector<std::vector<char>> &board, int row, int col);

bool did_player_win(int player, std::vector<std::vector<char>> &board);

bool horizontal_win(char player_token, std::vector<std::vector<char>> &board);