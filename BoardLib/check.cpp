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

void Board::promote_figure(tuple<int, int> position)
{
    std::string selection;
    while (true)
    {
        cout << "select figure you want to promote pawn to:" << endl
             << "Q, B, H, R:" << endl;
        cin >> selection;

        if (selection.size() != 1)
            cout << "Wrong length of coordinates: try again!\n";
        else if (toupper(selection[0]) != 'Q' && toupper(selection[0]) != 'B' && toupper(selection[0]) != 'H' && toupper(selection[0]) != 'R')
            cout << "wrong selection, try again" << endl;
        else
            break;
    }
    delete table[get<0>(position)][get<1>(position)];
    switch (selection[0])
    {
    case 'Q':
        table[get<0>(position)][get<1>(position)] = new Queen(current_player->get_color());
        current_player.
        break;
    case 'B':
        /* code */
        break;
    case 'H':
        /* code */
        break;
    case 'R':
        /* code */
        break;
    default:
        cout << "failed to promote" << endl;
        promote_figure(position);
        break;
    }
}
