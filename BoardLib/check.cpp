#include "board.h"
#include <vector>
#include <tuple>
#include <stdlib.h> /* srand, rand */
#include <time.h>

using namespace std;

bool Board::at_check(Player *player)
{
    char _color = current_player->get_color();
    int _count_dead = 0;
    for (int i = 0; i < graveyard.size(); ++i)
    {
        if (graveyard[i]->get_color() == _color)
        {
            ++_count_dead;
        }
    }
    if (_count_dead == 15)
        return true;

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

void Board::promote_figure(tuple<int, int> position, char new_fig)
{
    char selection = new_fig;
    if (new_fig == ' ')
        if (current_player->get_humanity())
            while (true)
            {
                cout << "Select figure you want to promote pawn to:" << endl
                     << "Q, B, H, R:" << endl;
                cin >> selection;

                if (toupper(selection) != 'Q' && toupper(selection) != 'B' && toupper(selection) != 'H' && toupper(selection) != 'R')
                    cout << "wrong selection, try again" << endl;
                else
                    break;
            }
        else
        {
            srand(time(NULL));
            char choices[5] = {'Q', 'Q', 'B', 'H', 'R'}; // queen twice as likely to be selected
            selection = choices[rand() % 5];
        }
    delete table[get<0>(position)][get<1>(position)];
    Figure *fig;
    switch (toupper(selection))
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
    current_player->add_figure(fig);
}

std::string Board::long_cast() noexcept
{
    // make_tuple(x,4) and table[x][4] are pos of a player king at the begining, later checked
    int x;
    if (current_player->get_color() == 'w')
        x = 7;
    else
        x = 0;

    if (table[x][4] != NULL && table[x][4]->get_figure() == 'K' && !table[x][4]->is_moved())     // check if king is where it should
        if (table[x][0] != NULL && table[x][0]->get_figure() == 'R' && !table[x][0]->is_moved()) // check if rook is where it should
            if (!table[x][0]->is_moved())
                if (table[x][1] == NULL && table[x][2] == NULL && table[x][3] == NULL)
                {
                    try
                    {
                        move_figure(make_tuple(x, 4), make_tuple(x, 3), true);
                        table[x][4]->set_num_of_moves(2);
                        move_figure(make_tuple(x, 4), make_tuple(x, 2), true); // will throw if movement is illegal -> check at any point
                    }
                    catch (const std::exception &e)
                    {
                        table[x][4]->set_num_of_moves(1);
                        return "";
                    }

                    // acctual move of a king
                    move_figure(make_tuple(x, 4), make_tuple(x, 2)); // movement shall be 2
                    table[x][2]->set_num_of_moves(1);                // reset movement
                    table[x][3] = table[x][0];
                    table[x][0] = NULL;
                    return "-ooo-";
                }
    return "";
}

std::string Board::short_cast() noexcept
{
    // make_tuple(x,4) and table[x][4] are pos of a player king at the begining, later checked
    int x;
    if (current_player->get_color() == 'w')
        x = 7;
    else
        x = 0;

    if (table[x][4] != NULL && table[x][4]->get_figure() == 'K' && !table[x][4]->is_moved())     // check if king is where it should
        if (table[x][7] != NULL && table[x][7]->get_figure() == 'R' && !table[x][7]->is_moved()) // check if rook is where it should
            if (!table[x][7]->is_moved())
                if (table[x][5] == NULL && table[x][6] == NULL)
                {
                    try
                    {
                        move_figure(make_tuple(x, 4), make_tuple(x, 5), true);
                        table[x][4]->set_num_of_moves(2);
                        move_figure(make_tuple(x, 4), make_tuple(x, 6), true); // will throw if movement is illegal -> check at any point
                    }
                    catch (const std::exception &e)
                    {
                        table[x][4]->set_num_of_moves(1);
                        return "";
                    }

                    // acctual move of a king
                    move_figure(make_tuple(x, 4), make_tuple(x, 6)); // movement shall be 2
                    table[x][6]->set_num_of_moves(1);                // reset movement
                    table[x][5] = table[x][7];
                    table[x][7] = NULL;
                    return "-oo-";
                }
    return "";
}

std::string Board::castling(tuple<int, int> new_cords) noexcept
{
    if (!at_check(current_player))
    {
        if (current_player->get_color() == 'w')
        {
            if (new_cords == make_tuple(7, 2)) // white long to left
            {
                return long_cast();
            }
            else if (new_cords == make_tuple(7, 6)) // white short to right
            {
                return short_cast();
            }
        }
        else // black castling
        {
            if (new_cords == make_tuple(0, 2)) // black long to left
            {
                return long_cast();
            }
            else if (new_cords == make_tuple(0, 6)) // white short to right
            {
                return short_cast();
            }
        }
    }
    return "";
}
