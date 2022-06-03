#include "game.h"
#include <iostream>
#include <map>
#include <stdlib.h> /* srand, rand */
#include <time.h>

using std::cin;
using std::cout;
Game::Game() noexcept // sets everything to NULL, because we have to wait for the user's input from menu to create board and players
// (one of the players will be a human player or AI and board is dependant on players)
{
    this->player1 = NULL;
    this->player2 = NULL;
    this->current_player = NULL;
    this->board = NULL;
}

void Game::menu() noexcept
{
    char gamemode;
    char color;
    cout << "Welcome to CHESS!\n";
    while (true)
    {
        cout << "Please choose the game mode: \n 1. Human \n 2. Ai vs Ai\n";
        cin >> gamemode;
        if (gamemode != '1' && gamemode != '2')
            cout << "Wrong option. Try again! \n";
        else
            break;
    }
    if (gamemode == '1') // skip manual color selection in Ai v Ai mode
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

    if (gamemode == '1')
        player1 = new Player(color, "Player 1");
    else
        player1 = new Player(color, "Ai 1.072", false);

    if (color == 'w') // swap color between player creation
        color = 'b';
    else
        color = 'w';

    if (gamemode == '1')
        while (true)
        {
            cout << "Please choose the opponent mode: \n 1. VS Human \n 2. VS Computer\n";
            cin >> gamemode;
            if (gamemode != '1' && gamemode != '2')
                cout << "Wrong option. Try again! \n";
            else
                break;
        }

    if (gamemode == '1')
        player2 = new Player(color, "Player 2");
    else
        player2 = new Player(color, "Ai 2.21", false);

    Board *board = new Board(player1, player2);

    if (this->player1->get_color() == 'w') // whites always start in chess
        current_player = player1;
    else
        current_player = player2;
    this->board = board;
}

std::string Game::player_turn()
{

    std::string temp_return;     // used to return, mainly for testing
    int old_row, new_row;        // info from coords
    char old_column, new_column; // info from coords
    std::map<char, int> m = {{'a', 0}, {'b', 1}, {'c', 2}, {'d', 3}, {'e', 4}, {'f', 5}, {'g', 6}, {'h', 7}};
    std::string old_coords, new_coords;
    while (true)
    {
        while (true)
        {
            cout << "Type the origin of your figure: "; // example: a4, h2, ...
            cin >> old_coords;
            if (old_coords.size() != 2) // coords always have 2 characters
                cout << "Wrong length of coordinates: try again!\n";
            else if (m[tolower(old_coords[0])] == 0 && tolower(old_coords[0]) != 'a') // first coor will be a letter <a, h>
                cout << "First character is not a valid column: try again!\n";
            else if (!(std::isdigit(old_coords[1])))
                cout << "Second character is not a number: try again!\n";
            else if (((int)(old_coords[1]) - '0') < 1 || ((int)(old_coords[1]) - '0') > 8) // second coor will be a num <1, 8>
                cout << "Second character is not a valid row number: try again!\n";

            else
                break;
        }
        old_row = (int)(old_coords[1]) - '0';
        old_row--;                           // for a computer, row is always 1 less than what number is printed on chess board
        old_column = tolower(old_coords[0]); // used in case user puts eg. "A4" instead of "a4"

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

std::string Game::cpu_turn() // used when Player2 is AI and it is their turn
// here we randomise coords and check if move with such coords can be made; if not, try again
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

void Game::switch_player() noexcept
{
    board->switch_current_player();
    if (current_player == player1)
        current_player = player2;
    else
        current_player = player1;
}

bool Game::mate_check() const noexcept
{
    return board->mate_check();
}

Game::~Game()
{
    delete board;
    delete player1;
    delete player2;
}