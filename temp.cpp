#include "./BoardLib/board.h"
#include "./GameLib/game.h"
// #include "./PlayerLib/player.h"
#include <iostream>
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
    while (!game.mate_check())
    {
        if (game.get_current_player()->get_humanity())
            game.show_board();
        cout << print_string << endl;
        if (game.get_current_player()->get_humanity())
            print_string = game.player_turn();
        else
            print_string = game.cpu_turn();
        game.switch_player();
        // std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }
    game.show_board();
    cout << print_string << endl;
    cout << game.get_current_player()->get_name() << " lost" << endl;
    return 0;
}