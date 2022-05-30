#include "game.h"
#include <iostream>
using std::cout;
using std::cin;
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
    cout << "Welcome to CHESS!\n";
    while (true)
    {
        cout << "Please choose the game mode: \n 1. VS Human \n 2. VS Computer\n";
        cin >> gamemode;
        if (gamemode != 1 && gamemode != 2)
            cout << "Wrong option. Try again! \n";
        else
            break;
    }
    char color;
    while (true)
    {
        cout << "Please choose your color: \n(w)hite\n(b)lack";
        cin >> color;
        if (color != 'w' && color != 'b')
            cout << "Wrong option. Try again! \n";
        else
            break;
    }
    
    Player* player1 = new Player(color, "Player 1");
    if (color == 'w')
        color = 'b';
    else
        color = 'w';
    Player* player2 = new Player(color, "Player 2", false);
    Board* board = new Board(player1, player2); 

    this->player1 = player1;
    this->player2 = player2;
    if (this->player1->get_color() == 'w')
        current_player = player1;
    else
        current_player = player2;
    this->board = board;
}

void Game::next_turn()
{
    board->switch_current_player();
    if (current_player == player1)
        current_player = player2;
    else
        current_player = player1;
}