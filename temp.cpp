#include "./BoardLib/board.h"
#include "./GameLib/game.h"
// #include "./PlayerLib/player.h"
#include <iostream>
#include <map>

using std::cin;
using std::cout;

int main()
{
    Game game;
    game.menu();
    std::string print_string = "";
    while (!game.mate_check())
    {
        game.show_board();
        cout << print_string << endl;
        if (game.get_current_player()->get_humanity())
            print_string = game.player_turn();
        else
            print_string = game.cpu_turn();
        game.switch_player();
    }
    game.show_board();
    cout << print_string << endl;
    cout << game.get_current_player()->get_name() << " lost" << endl;
    return 0;
}