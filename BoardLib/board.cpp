#include "board.h"
#include "../PlayerLib/player.h"
#include <vector>
#include <tuple>

using namespace std;

Board::Board(Player *player1, Player *player2)
{
    // for (int i = 0; i < 8; i++)
    //     for (int j = 0; j < 8; j++)
    //         table[i][j] = NULL;

    int v = 0;
    for (int i = 8; i > 6; i--)
        for (int j = 0; j < 8; j++)
        {
            table[i][j] = player1->get_figures()[v];
            v++;
        }

    v = 0;
    for (int i = 0; i < 2; i++)
        for (int j = 7; j >= 0; j--)
        {
            table[i][j] = player2->get_figures()[v];
            v++;
        }

    this->player1 = player1;
    this->player2 = player2;
    current_player = player1;
}

std::string Board::move_figure(tuple<int, int> old_cord, tuple<int, int> new_cord)
{
    Figure *moved_piece = table[get<0>(old_cord)][get<1>(old_cord)];
    string temp = to_string(get<0>(old_cord)) + to_string(get<1>(old_cord));
    temp += " ";
    temp += moved_piece->get_token();
    temp += " ";
    string temp = to_string(get<0>(new_cord)) + to_string(get<1>(new_cord));

    if (table[get<0>(new_cord)][get<1>(new_cord)] != NULL)
    {
        // current_player.points += table[get<0>(new_cord)][get<1>(new_cord)]->take();
        table[get<0>(new_cord)][get<1>(new_cord)]->take();
    }
    table[get<0>(new_cord)][get<1>(new_cord)] = moved_piece;
}

void Board::dump()
{
    for (int y = 7; y >= 0; --y)
    {
        for (int i = 0; i < 8; i++)
        {
            if (table[i][y] == NULL)
            {
                cout << " ";
                break;
            }
            cout << table[i][y]->get_token();
        }
        cout << endl;
    }
}

std::ostream &operator<<(std::ostream &os, const Board b)
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
