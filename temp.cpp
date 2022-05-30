#include "./BoardLib/board.h"
#include "./GameLib/game.h"
// #include "./PlayerLib/player.h"
#include <iostream>
#include <map>

using std::cout;
using std::cin;

int main()
{
    Game game;
    std::map<std::string, int> m = {{"A", 0}, {"B", 1}, {"C", 2}, {"D", 3}, {"E", 4}, {"F", 5}, {"G", 6}, {"H", 7}};
    game.menu();
    
    while (true)
    {
        game.show_board();
        int old_row, new_row;
        std::string old_column, new_column;

        cout << "Choose the row of your figure: ";
        cin >> old_row;

        cout << "Choose the column of your figure: ";
        cin >> old_column;

        cout << "Choose the new row of your figure: ";
        cin >> new_row;

        cout << "Choose the new column of your figure: ";
        cin >> new_column;

        old_row--;
        new_row--;

        if (game.get_player1()->get_color() == 'w')
            game.move_figure(std::make_tuple(7 - old_row, m[old_column]), std::make_tuple(7 - new_row, m[new_column]));
        else
            game.move_figure(std::make_tuple(old_row, 7 - m[old_column]), std::make_tuple(new_row, 7 - m[new_column]));
        //game.next_turn();
    }
    return 0;
}