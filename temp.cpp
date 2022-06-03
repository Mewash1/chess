#include "./BoardLib/board.h"
#include "./GameLib/game.h"
// #include "./PlayerLib/player.h"
#include <iostream>
#include <fstream>
#include <map>
#include <thread>
#include <chrono>

using std::cin;
using std::cout;

int main()
{
    Game game;
    game.menu();
    std::string print_string = "";
    std::string move_list = "";

    if (game.get_player1()->get_color() == 'w')
        move_list = move_list + "Player 1's color: white\n" + "Player 2's color: black\n\n";
    else
        move_list = move_list + "Player 1's color: black\n" + "Player 2's color: white\n\n";

    while (!game.mate_check())
    {
        if (game.get_current_player()->get_humanity())
        {
            game.show_board();
            cout << print_string << endl;
        }

        if (!game.get_player1()->get_humanity() && !game.get_player2()->get_humanity()) // show borad only for white bot if both players are bots
        {
            if (game.get_current_player()->get_color() == 'w')
                game.show_board();
            std::this_thread::sleep_for(std::chrono::milliseconds(150)); // sleep for more redable gameplay
        }

        if (game.get_current_player()->get_humanity())
            print_string = game.player_turn();
        else
            print_string = game.cpu_turn();

        move_list = move_list + game.get_current_player()->get_name() + ": " + print_string + "\n";
        game.switch_player();
    }
    move_list = move_list + "\n";
    game.show_board();
    cout << print_string << endl;
    if (game.get_board()->at_check(game.get_current_player()))
    {
        cout << game.get_current_player()->get_name() << " lost" << endl;
        move_list = move_list + game.get_current_player()->get_name() + " lost\n";
    }
    else
    {
        cout << "it's a Pat, no winner" << endl;
        move_list = move_list + "it's a Pat, no winner\n";
    }

    char choice;
    while (true)
    {
        cout << "Would you like to save your game to a file? (Y/N): ";
        cin >> choice;

        if (toupper(choice) == 'Y')
        {
            std::ofstream file;
            remove("saved_game.txt");
            file.open("saved_game.txt");
            file << move_list;
            file.close();
            return 0;
        }
        else if (toupper(choice) == 'N')
            return 0;
        else
            cout << "Wrong input: try again!\n";
    }
}