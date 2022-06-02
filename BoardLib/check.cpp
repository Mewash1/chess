#include "board.h"
#include <vector>
#include <tuple>
#include <stdlib.h> /* srand, rand */
#include <time.h>

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
    if (current_player->get_humanity())
        while (true)
        {
            cout << "Select figure you want to promote pawn to:" << endl
                 << "Q, B, H, R:" << endl;
            cin >> selection;

            if (selection.size() != 1)
                cout << "Wrong length of coordinates: try again!\n";
            else if (toupper(selection[0]) != 'Q' && toupper(selection[0]) != 'B' && toupper(selection[0]) != 'H' && toupper(selection[0]) != 'R')
                cout << "wrong selection, try again" << endl;
            else
                break;
        }
    else
    {
        srand(time(NULL));
        vector<char> choices = {'Q', 'Q', 'B', 'H', 'R'}; // queen twice as likely to be selected
        selection = choices[rand() % 5];
    }
    delete table[get<0>(position)][get<1>(position)];
    Figure *fig;
    switch (toupper(char(selection[0])))
    {
    case 'Q':
        fig = new Queen(current_player->get_color());
        break;
    case 'B':
        fig = new Bishop(current_player->get_color());
        break;
    case 'H':
        fig = new Horse(current_player->get_color());
        break;
    case 'R':
        fig = new Rook(current_player->get_color());
        break;
    default:
        cout << "failed to promote" << endl;
        promote_figure(position);
        break;
    }
    table[get<0>(position)][get<1>(position)] = fig;
}
