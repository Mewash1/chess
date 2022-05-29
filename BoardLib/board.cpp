#include "board.h"
#include "../player.h"
#include <vector>

using namespace std;

Board::Board(vector white_pieces, vector)
{
    King king_white('w');
    King king_black('b');
    table[5][0] = &king_white;
    table[4][8] = &king_black;
}

Board::std::string move_figure(tuple<int, int> old_cord, tuple<int, int> new_cords);