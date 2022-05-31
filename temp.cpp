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
    std::map<char, int> m = {{'A', 0}, {'B', 1}, {'C', 2}, {'D', 3}, {'E', 4}, {'F', 5}, {'G', 6}, {'H', 7}};
    game.menu();
    
    while (true)
    {
        game.show_board();
        int old_row, new_row;
        char old_column, new_column;

        std::string old_coords, new_coords;

        while (true)
        {
            cout << "Type the coordinates of your figure: ";
            cin >> old_coords;
            if (old_coords.size() != 2)
                cout << "Wrong length of coordinates: try again!\n";
            else if (!(std::isdigit(old_coords[0])))
                cout << "First character is not a number: try again!\n";
            else if (((int)(old_coords[0]) - '0') < 1 || ((int)(old_coords[0]) - '0') > 8)
                cout << "First character is not a valid row number: try again!\n";
            else if (m[old_coords[1]] == 0 && old_coords[1] != 'A')
                cout << "Second character is not a valid column: try again!\n";
            else
                break;
        }
        old_row = (int)(old_coords[0]) - '0';
        old_row--;
        old_column = old_coords[1];

        while (true)
        {
            cout << "Type the coordinates of your figure: ";
            cin >> new_coords;
            if (new_coords.size() != 2)
                cout << "Wrong length of coordinates: try again!\n";
            else if (!(std::isdigit(new_coords[0])))
                cout << "First character is not a number: try again!\n";
            else if (((int)(new_coords[0]) - '0') < 1 || ((int)(new_coords[0]) - '0') > 8)
                cout << "First character is not a valid row number: try again!\n";
            else if (m[new_coords[1]] == 0 && new_coords[1] != 'A')
                cout << "Second character is not a valid column: try again!\n";
            else
                break;
        }
        new_row = (int)(new_coords[0]) - '0';
        new_row--;
        new_column = new_coords[1];

        game.move_figure(std::make_tuple(7 - old_row, m[old_column]), std::make_tuple(7 - new_row, m[new_column]));
        
        game.next_turn();
    }
    return 0;
}