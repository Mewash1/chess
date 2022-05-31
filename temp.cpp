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
    while (true)
    {
        if (game.get_current_player()->get_humanity())
            game.player_turn();
        else
            game.cpu_turn();
        game.switch_player();
    }
    return 0;
}