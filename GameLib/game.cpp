#include "game.h"
#include <iostream>
#include <map>
#include <stdlib.h> /* srand, rand */
#include <time.h>

using std::cin;
using std::cout;
Game::Game()
{
    this->player1 = NULL;
    this->player2 = NULL;
    this->current_player = NULL;
    this->board = NULL;
}

void Game::menu()
{
    int gamemode;
    char color;
    cout << "Welcome to CHESS!\n";
    while (true)
    {
        cout << "Please choose the game mode: \n 1. Human \n 2. Ai vs Ai\n";
        cin >> gamemode;
        if (gamemode != 1 && gamemode != 2)
            cout << "Wrong option. Try again! \n";
        else
            break;
    }
    if (gamemode == 1) // skip manual color selectrion in AvA mode
    {
        while (true)
        {
            cout << "Please choose your color: \n(w)hite\n(b)lack\n";
            cin >> color;
            if (color != 'w' && color != 'b')
                cout << "Wrong option. Try again! \n";
            else
                break;
        }
    }
    else
    {
        color = 'w';
    }

    if (gamemode == 1)
        player1 = new Player(color, "Player 1");
    else
        player1 = new Player(color, "Ai 1.072", false);

    if (color == 'w') // swap color betwen player creation
        color = 'b';
    else
        color = 'w';

    if (gamemode == 1)
        while (true)
        {
            cout << "Please choose the opponent mode: \n 1. VS Human \n 2. VS Computer\n";
            cin >> gamemode;
            if (gamemode != 1 && gamemode != 2)
                cout << "Wrong option. Try again! \n";
            else
                break;
        }

    if (gamemode == 1)
        player2 = new Player(color, "Player 2");
    else
        player2 = new Player(color, "Ai 2.21", false);

    Board *board = new Board(player1, player2);

    if (this->player1->get_color() == 'w')
        current_player = player1;
    else
        current_player = player2;
    this->board = board;
}

std::string Game::player_turn()
{

    std::string temp_return; // used to return
    int old_row, new_row;
    char old_column, new_column;
    std::map<char, int> m = {{'a', 0}, {'b', 1}, {'c', 2}, {'d', 3}, {'e', 4}, {'f', 5}, {'g', 6}, {'h', 7}};
    std::string old_coords, new_coords;
    while (true)
    {
        while (true)
        {
            cout << "Type the orgin of your figure: ";
            cin >> old_coords;
            if (old_coords.size() != 2)
                cout << "Wrong length of coordinates: try again!\n";
            else if (m[tolower(old_coords[0])] == 0 && tolower(old_coords[0]) != 'a')
                cout << "First character is not a valid column: try again!\n";
            else if (!(std::isdigit(old_coords[1])))
                cout << "Second character is not a number: try again!\n";
            else if (((int)(old_coords[1]) - '0') < 1 || ((int)(old_coords[1]) - '0') > 8)
                cout << "Second character is not a valid row number: try again!\n";

            else
                break;
        }
        old_row = (int)(old_coords[1]) - '0';
        old_row--;
        old_column = tolower(old_coords[0]);

        while (true)
        {
            cout << "Type the target of your figure: ";
            cin >> new_coords;
            if (new_coords.size() != 2)
                cout << "Wrong length of coordinates: try again!\n";
            else if (m[tolower(new_coords[0])] == 0 && tolower(new_coords[0]) != 'a')
                cout << "First character is not a valid column: try again!\n";
            else if (!(std::isdigit(new_coords[1])))
                cout << "Second character is not a number: try again!\n";
            else if (((int)(new_coords[1]) - '0') < 1 || ((int)(new_coords[1]) - '0') > 8)
                cout << "Second character is not a valid row number: try again!\n";
            else
                break;
        }

        new_row = (int)(new_coords[1]) - '0';
        new_row--;
        new_column = tolower(new_coords[0]);
        try
        {
            temp_return = (*this).move_figure(std::make_tuple(7 - old_row, m[old_column]), std::make_tuple(7 - new_row, m[new_column]));
        }
        catch (const std::exception &exc)
        {
            cout << exc.what() << endl;
            continue;
        }
        catch (...)
        {
            cout << "unnkown error" << endl;
            continue;
        }
        break;
    }
    return temp_return;
}

std::string Game::cpu_turn()
{
    std::string temp_return; // used to return
    srand(time(NULL));
    while (true)
    {
        int x = rand() % 8;
        int y = rand() % 8;
        int new_x = rand() % 8;
        int new_y = rand() % 8;

        try
        {
            temp_return = this->move_figure(std::make_tuple(x, y), std::make_tuple(new_x, new_y));
        }
        catch (const std::exception &exc)
        {
            // cout << exc.what() << endl;
            continue;
        }
        catch (...)
        {
            // cout << "unnkown error" << endl;
            continue;
        }
        break;
    }
    return temp_return;
}

void Game::switch_player()
{
    board->switch_current_player();
    if (current_player == player1)
        current_player = player2;
    else
        current_player = player1;
}

bool Game::mate_check()
{
    return board->mate_check();
}
