#include "board.h"
#include "../player.h"
#include <vector>

Board::Board(Player *player1, Player *player2)
{
    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++)
            table[i][j] = NULL;
        
    int v = 0;
    for (int i = 8; i > 6; i--)
        for (int j = 0; j < 8; j++)
            table[i][j] = player1->get_figures()[v];
            v++;
    
    v = 0;
    for (int i = 0; i < 2; i++)
        for (int j = 7; j >= 0; j--)
            table[i][j] = player2->get_figures()[v];
            v++;
}

std::string Board::move_figure(tuple<int,int> old_cord, tuple<int,int> new_cords)
{
    return 0;
}

std::ostream& operator<<(std::ostream& os, const Board b)
{
    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++)
            {
                if (b.table[i][j] == NULL)
                    os << 0;
                else
                    os << (b.table[i][j])->get_token();
            }
    return os;
}
