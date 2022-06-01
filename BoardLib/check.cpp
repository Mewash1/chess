#include "board.h"
#include <vector>
#include <tuple>

using namespace std;

bool Board::at_check(Player *player)
{
    tuple<int, int> king_pos = player->get_king();
    switch_current_player();

    for (int y = 0; y < 8; y++)
    {
        for (int x = 0; x < 8; x++)
        {
            if (table[x][y] == NULL)
                continue;
            try
            {
                if (validate_move(table[x][y], make_tuple(x, y), king_pos))
                {
                    switch_current_player();
                    return true;
                }
            }
            catch (const exception &exc)
            {
                continue;
            }
        }
    }
    switch_current_player();
    return false;
}

bool Board::mate_check()
{
    for (int y = 0; y < 8; y++)
    {
        for (int x = 0; x < 8; x++)
        {
            if (table[x][y] != NULL)
            {
                if (table[x][y]->get_color() != current_player->get_color())
                {
                    continue;
                }
                for (int ny = 0; ny < 8; ny++)
                {
                    for (int nx = 0; nx < 8; nx++)
                    {
                        try
                        {
                            move_figure(make_tuple(x, y), make_tuple(nx, ny), true);
                            // cout << x << y << " " << nx << ny << endl;
                            return false;
                        }
                        catch (...)
                        {
                            continue;
                        }
                    }
                }
            }
        }
    }
    return true;
}
