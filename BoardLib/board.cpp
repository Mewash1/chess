#include "board.h"
// #include "../PlayerLib/player.h"
#include <vector>
#include <tuple>
//#include <Windows.h>

using namespace std;

Board::Board(Player *player1, Player *player2)
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

void Board::print_row(int i)
{
    /*HANDLE hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 15);*/
    srand(time(NULL));
    if (current_player->get_color() == 'w')
    {
        for (int j = 0; j < 8; j++)
        {
            if (table[i][j] == NULL)
                std::cout << "\033[090m   |\033[0m";
            else if ((table[i][j])->get_color() == 'w')
                std::cout << ' ' << (table[i][j])->get_token() << "\033[90m |\033[0m";
            else
                std::cout << "\033[31m " << (table[i][j])->get_token() << " \033[90m|\033[0m";
        }
    }
    else
    {
        for (int j = 0; j < 8; j++)
        {
            if (table[7 - i][7 - j] == NULL)
                std::cout << "\033[90m   |\033[0m";
            else if ((table[7 - i][7 - j])->get_color() == 'w')
                std::cout << ' ' << (table[7 - i][7 - j])->get_token() << "\033[90m |\033[0m";
            else
                std::cout << "\033[31m " << (table[7 - i][7 - j])->get_token() << " \033[90m|\033[0m";
        }
    }
    std::cout << endl;
}

void Board::print()
{
    /*HANDLE hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 14);*/
    std::cout << "\033c";
    std::cout << "\033[33m-------------------------------------" << std::endl;
    if (current_player->get_color() == 'w')
        std::cout << "|   | A | B | C | D | E | F | G | H |" << std::endl;
    else
        std::cout << "|   | H | G | F | E | D | C | B | A |" << std::endl;
    std::cout << "-------------------------------------\033[0m" << std::endl;
    for (int i = 0; i < 8; i++)
    {
        // SetConsoleTextAttribute(hConsole, 14);
        if (current_player->get_color() == 'w')
            std::cout << "\033[33m| " << (8 - i) << " |\033[0m";
        else
            std::cout << "\033[33m| " << (i + 1) << " |\033[0m";
        // SetConsoleTextAttribute(hConsole, 15);
        print_row(i);
        std::cout << "\033[33m-----\033[0m";
        std::cout << "\033[90m--------------------------------\033[0m" << std::endl;
    }
    std::cout << current_player->get_name() << "'s turn\n";
}

void Board::print_graveyard() {
    std::vector<Figure*> temp;
    for (int i = 0; i < 30; ++i) {
        if (graveyard[i] != 0 && graveyard[i]->get_color() == 'w')
            cout << graveyard[i] << "(white)" << ' ';
        else if (graveyard[i] != 0 && graveyard[i]->get_color() == 'b')
            cout << graveyard[i] << "(black)" << ' ';
        else
            continue;
    }
    cout << endl;
}

void Board::switch_current_player()
{
    if (current_player == player1)
        current_player = player2;
    else
        current_player = player1;
}

bool Board::at_check(Player *player)
{
    return false;
}

std::string Board::move_figure(tuple<int, int> old_cord, tuple<int, int> new_cord)
{
    if (table[get<0>(old_cord)][get<1>(old_cord)] == NULL)
        throw out_of_range("chose an empty space");
    if (get<0>(new_cord) > 8 or get<1>(new_cord) > 8 or get<0>(new_cord) < 0 or get<1>(new_cord) < 0)
        throw out_of_range("left playable area");

    Figure *moved_piece = table[get<0>(old_cord)][get<1>(old_cord)];

    string temp = "";
    temp += to_string(get<0>(old_cord));
    temp += " ";
    temp += to_string(get<1>(old_cord));
    temp += " ";
    temp += moved_piece->get_token();
    temp += " ";
    temp += to_string(get<0>(new_cord));
    temp += " ";
    temp += to_string(get<1>(new_cord));

    if (!validate_move(moved_piece, old_cord, new_cord))
        throw out_of_range("illegal move!");

    if (table[get<0>(new_cord)][get<1>(new_cord)] != NULL)
    {
        // current_player.points += table[get<0>(new_cord)][get<1>(new_cord)]->take();
        table[get<0>(new_cord)][get<1>(new_cord)]->take();
    }
    table[get<0>(new_cord)][get<1>(new_cord)] = moved_piece;
    table[get<0>(old_cord)][get<1>(old_cord)] = NULL;
    cout << temp << endl;

    if (moved_piece->get_figure() == 'P')
    {
        moved_piece->set_num_of_moves(1);
    }

    return temp;
}

bool zero_direction(int move_a, int delta_a)
{ // chceck for expected zero vector
    return bool(move_a == 0 && delta_a == 0);
}
bool same_direction(int move_a, int delta_a)
{ // check for linear combination
    return bool(delta_a % move_a == 0);
}
bool one_direction(int move_a, int delta_a) // pun intended
{
    if (zero_direction(move_a, delta_a))
        return true;
    if (move_a != 0)
        return same_direction(move_a, delta_a);
    else
        return false;
}

bool turn_direction(int move_a, int delta_a)
{ // check for common vector turn
    return bool((delta_a * move_a > 0) or (move_a == 0 && delta_a == 0));
}

bool check_direction(int move_x, int move_y, int delta_x, int delta_y)
{

    return bool((one_direction(move_x, delta_x) &&
                 one_direction(move_y, delta_y)) &&
                (turn_direction(move_x, delta_x) &&
                 turn_direction(move_y, delta_y)));
}

bool Board::validate_move(Figure *moved, tuple<int, int> old_cord, tuple<int, int> cords)
{
    // check player
    if (current_player->get_color() != moved->get_color())
        throw logic_error("Chosen figure does not belong to you!");

    int steps = moved->get_num_of_moves();
    vector<tuple<int, int>> moves = moved->get_moves();
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
                        if (at_check(current_player))
                            throw logic_error("You will be at check");
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
