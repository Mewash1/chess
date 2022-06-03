#include "board.h"
// #include "../PlayerLib/player.h"
#include <vector>
#include <tuple>
#include <map>
//#include <Windows.h>

using namespace std;

Board::Board(Player *player1, Player *player2) // sets figures at their places and sets current player's color
{
    int v = 0;
    for (int i = 7; i >= 6; i--)
        for (int j = 0; j < 8; j++)
        {
            if (player1->get_color() == 'w')
                table[i][j] = player1->get_figures()[v];
            else
                table[i][j] = player2->get_figures()[v];
            v++;
        }

    v = 0;
    for (int i = 0; i < 2; i++)
        for (int j = 7; j >= 0; j--)
        {
            if (player1->get_color() == 'w')
                table[i][j] = player2->get_figures()[v];
            else
                table[i][j] = player1->get_figures()[v];
            v++;
        }

    this->player1 = player1;
    this->player2 = player2;
    if (this->player1->get_color() == 'w')
        current_player = player1;
    else
        current_player = player2;
}

// void Board::dump()
// {
//     for (int y = 7; y >= 0; --y)
//     {
//         for (int i = 0; i < 8; i++)
//         {
//             if (table[i][y] == NULL)
//             {
//                 cout << " ";
//                 break;
//             }
//             cout << table[i][y]->get_token();
//         }
//         cout << endl;
//     }
// }

// prints were here

void Board::switch_current_player() noexcept
{
    if (current_player == player1)
        current_player = player2;
    else
        current_player = player1;
}

std::map<int, char> m = {{0, 'a'}, {1, 'b'}, {2, 'c'}, {3, 'd'}, {4, 'e'}, {5, 'f'}, {6, 'g'}, {7, 'h'}};
// ^used when player gives the coordinates for their move (eg. move "a4" is translated using this map so that the program understands that)

std::string Board::move_figure(tuple<int, int> old_cord, tuple<int, int> new_cord, bool simulate)
{
    if (table[get<0>(old_cord)][get<1>(old_cord)] == NULL)
        throw out_of_range("chose an empty space");
    if (get<0>(new_cord) > 8 or get<1>(new_cord) > 8 or get<0>(new_cord) < 0 or get<1>(new_cord) < 0)
        throw out_of_range("left playable area");

    Figure *moved_piece = table[get<0>(old_cord)][get<1>(old_cord)];

    // prints the last move that the enemy made
    string temp = "";
    temp += (m[get<1>(old_cord)]);
    temp += to_string(8 - get<0>(old_cord));
    temp += "(";
    temp += moved_piece->get_token();
    temp += ") ---> ";
    temp += (m[get<1>(new_cord)]);
    temp += to_string(8 - get<0>(new_cord));

    if (moved_piece->get_figure() == 'K' && moved_piece->get_num_of_moves() == 1) // try castling
    {
        std::string cast = castling(new_cord);
        if (cast != "")
        {
            temp += cast;
            return temp;
        }
    }

    if (!validate_move(moved_piece, old_cord, new_cord))
        throw out_of_range("illegal move!");

    // checks if there is any figure in the place user wants to move their piece on;
    if (table[get<0>(new_cord)][get<1>(new_cord)] != NULL)
    {
        purgatory = table[get<0>(new_cord)][get<1>(new_cord)];
        // ->take();
    }
    table[get<0>(new_cord)][get<1>(new_cord)] = moved_piece;
    table[get<0>(new_cord)][get<1>(new_cord)]->set_moved(true);
    table[get<0>(old_cord)][get<1>(old_cord)] = NULL;
    if (moved_piece->get_figure() == 'K')
    {
        current_player->set_king(new_cord);
    }

    bool temp_at_check = at_check(current_player);
    bool end_throw = false;

    if (temp_at_check or simulate)
    {
        table[get<0>(new_cord)][get<1>(new_cord)] = purgatory;
        purgatory = NULL;
        table[get<0>(old_cord)][get<1>(old_cord)] = moved_piece;
        table[get<0>(old_cord)][get<1>(old_cord)]->set_moved(false);
        if (moved_piece->get_figure() == 'K')
        {
            current_player->set_king(old_cord);
        }
        if (temp_at_check)
        {
            end_throw = true;
        }
    }

    if (purgatory != NULL)
        take_figure(purgatory);

    if (moved_piece->get_figure() == 'P')
    {
        moved_piece->set_num_of_moves(1);
        if ((get<0>(new_cord) == 0 || get<0>(new_cord) == 7) && !simulate)
            promote_figure(new_cord);
    }

    // cout << temp << endl;
    if (end_throw)
    {
        throw logic_error("you will be at check");
    }

    return temp;
}

bool zero_direction(int move_a, int delta_a) noexcept
{ // chceck for expected zero vector
    return bool(move_a == 0 && delta_a == 0);
}
bool same_direction(int move_a, int delta_a) noexcept
{ // check for linear combination
    return bool(delta_a % move_a == 0);
}
bool one_direction(int move_a, int delta_a) noexcept // pun intended
{
    if (zero_direction(move_a, delta_a))
        return true;
    if (move_a != 0)
        return same_direction(move_a, delta_a);
    else
        return false;
}

bool turn_direction(int move_a, int delta_a) noexcept
{ // check for common vector turn
    return bool((delta_a * move_a > 0) or (move_a == 0 && delta_a == 0));
}

bool check_direction(int move_x, int move_y, int delta_x, int delta_y) noexcept
{

    return bool((one_direction(move_x, delta_x) &&
                 one_direction(move_y, delta_y)) &&
                (turn_direction(move_x, delta_x) &&
                 turn_direction(move_y, delta_y)));
}

bool Board::validate_move(Figure *moved, tuple<int, int> const old_cord, tuple<int, int> const cords)
{
    // check player
    if (current_player->get_color() != moved->get_color())
    {
        throw out_of_range("Chosen figure does not belong to you!");
    }

    vector<tuple<int, int>> moves = moved->get_moves();

    if (moved->get_figure() == 'P')
    {
        moves = get_pawn_moves(old_cord);
    }
    int steps = moved->get_num_of_moves();

    tuple<int, int> direction;
    int delta_x, delta_y, pos_x, pos_y;
    delta_x = get<0>(cords) - get<0>(old_cord);
    delta_y = get<1>(cords) - get<1>(old_cord);
    pos_x = get<0>(old_cord);
    pos_y = get<1>(old_cord);

    if (old_cord == cords)
        return false;

    for (int k = 0; k < moves.size(); ++k)
    {
        direction = moves[k];
        int move_x = get<0>(direction);
        int move_y = get<1>(direction);

        if (check_direction(move_x, move_y, delta_x, delta_y)) // moves in direction checks for same orientation
            for (int i = 0; i < steps; ++i)
            {
                pos_x += move_x;
                pos_y += move_y;
                if (pos_x == get<0>(cords) && pos_y == get<1>(cords))
                {
                    if (table[pos_x][pos_y] == NULL or table[pos_x][pos_y]->get_color() != moved->get_color())
                    {
                        return true;
                    }
                }

                else
                {
                    if (table[pos_x][pos_y] != NULL)
                        return false;
                }
            }
    }
    return false;
}

void Board::take_figure(Figure *looser)
{
    graveyard.push_back(looser);
    looser->take();
    purgatory = NULL;
}

vector<tuple<int, int>> Board::get_pawn_moves(tuple<int, int> old_cord) const
{
    vector<tuple<int, int>> moves;
    int pos_x = get<0>(old_cord);
    int pos_y = get<1>(old_cord);
    if (table[pos_x][pos_y] == NULL)
    {
        return moves;
    }

    if (table[pos_x][pos_y]->get_color() == 'b')
    {
        if (table[pos_x + 1][pos_y + 1] != NULL)
            moves.push_back(make_tuple(1, 1));
        if (table[pos_x + 1][pos_y] == NULL)
            moves.push_back(make_tuple(1, 0));
        if (table[pos_x + 2][pos_y] == NULL && !(table[pos_x][pos_y]->is_moved()))
            table[pos_x][pos_y]->set_num_of_moves(2);
        if (table[pos_x + 1][pos_y - 1] != NULL)
            moves.push_back(make_tuple(1, -1));
    }
    else
    {
        if (table[pos_x - 1][pos_y + 1] != NULL)
            moves.push_back(make_tuple(-1, 1));
        if (table[pos_x - 1][pos_y] == NULL)
            moves.push_back(make_tuple(-1, 0));
        if (table[pos_x - 2][pos_y] == NULL && !(table[pos_x][pos_y]->is_moved()))
            table[pos_x][pos_y]->set_num_of_moves(2);
        if (table[pos_x - 1][pos_y - 1] != NULL)
            moves.push_back(make_tuple(-1, -1));
    }
    return moves;
}
