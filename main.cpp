#include "board_pieces.h" // Include contents of self constructed header files
#include "general_functions.h"
#include "board.h"

int main()
{
    // Creates the chess board & board location to vector location map
    board new_board;
    new_board.initialise_board();
    new_board.create_map();
    new_board.run_intro();
    // Plays game whilst there is no check mate
    while(new_board.get_check_mate() == false) {
        new_board.print_chess_and_moves();
        std::cout << new_board << std::endl;
        new_board.process_coordinate("from");
        new_board.process_coordinate("to");
        new_board.reset_move_assistant(); // If move assistant is on, move assistant is reset here
        new_board.move_piece();
        new_board.check_and_check_mate_test();
        new_board.change_turn();
        new_board.flip_board();
    }
    return 0;
}
