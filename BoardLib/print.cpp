#include "board.h"
#include <vector>
#include <tuple>
#include <map>

using namespace std;

void Board::print_row(int i) const // prints out a row of chessboard and places figures at right spots
// i is the number of the row in the chessboard, so eg. print_row(4) will print out 4th row with its figures
{
    srand(time(NULL));
    if (current_player->get_color() == 'w') // if whites play, we don't turn the chessboard
    {
        for (int j = 0; j < 8; j++)
        {
            if (table[i][j] == NULL && j != 7)
                std::cout << "\033[090m   |\033[0m";
            else if (table[i][j] == NULL && j == 7)
                std::cout << "\033[090m   \033[0m";
            else if ((table[i][j])->get_color() == 'w' && j != 7)
                std::cout << ' ' << (table[i][j])->get_token() << "\033[90m |\033[0m";
            else if ((table[i][j])->get_color() == 'w' && j == 7)
                std::cout << ' ' << (table[i][j])->get_token() << ' ';
            else if ((table[i][j])->get_color() == 'b' && j != 7)
                std::cout << "\033[31m " << (table[i][j])->get_token() << " \033[90m|\033[0m";
            else
                std::cout << "\033[31m " << (table[i][j])->get_token() << ' ';
        }
        std::cout << "\033[33m| " << (8 - i) << " |\033[0m";
    }
    else // if blacks play, we turn the chessboard so that it's easier to make the right move
    {
        for (int j = 0; j < 8; j++)
        {
            if (table[7 - i][7 - j] == NULL && j != 7)
                std::cout << "\033[90m   |\033[0m";
            else if (table[7 - i][7 - j] == NULL && j == 7)
                std::cout << "\033[90m   \033[0m";
            else if ((table[7 - i][7 - j])->get_color() == 'w' && j != 7)
                std::cout << ' ' << (table[7 - i][7 - j])->get_token() << "\033[90m |\033[0m";
            else if ((table[7 - i][7 - j])->get_color() == 'w' && j == 7)
                std::cout << ' ' << (table[7 - i][7 - j])->get_token() << ' ';
            else if ((table[7 - i][7 - j])->get_color() == 'b' && j != 7)
                std::cout << "\033[31m " << (table[7 - i][7 - j])->get_token() << " \033[90m|\033[0m";
            else
                std::cout << "\033[31m " << (table[7 - i][7 - j])->get_token() << ' ';
        }
        std::cout << "\033[33m| " << (i + 1) << " |\033[0m";
    }
    std::cout << endl;
}

void Board::print() const // printing out the chess board with figures on their current places
{
    std::cout << "\033c"; // clear console so that only the current state of game is showed
    std::cout << "\033[33m-----------------------------------------" << std::endl;
    if (current_player->get_color() == 'w')
        std::cout << "|   | A | B | C | D | E | F | G | H |   |" << std::endl;
    else
        std::cout << "|   | H | G | F | E | D | C | B | A |   |" << std::endl;
    std::cout << "-----------------------------------------\033[0m" << std::endl;
    for (int i = 0; i < 8; i++)
    {
        if (current_player->get_color() == 'w')
            std::cout << "\033[33m| " << (8 - i) << " |\033[0m";
        else
            std::cout << "\033[33m| " << (i + 1) << " |\033[0m";
        print_row(i);
        std::cout << "\033[33m-----\033[0m";
        std::cout << "\033[90m-------------------------------\033[33m-----\033[0m" << std::endl;
    }
    if (current_player->get_color() == 'w')
        std::cout << "\033[33m|   | A | B | C | D | E | F | G | H |   |" << std::endl;
    else
        std::cout << "\033[33m|   | H | G | F | E | D | C | B | A |   |" << std::endl;
    std::cout << "-----------------------------------------\033[0m" << std::endl;
    print_graveyard();
    std::cout << current_player->get_name() << "'s turn\n"; // prints out which player's turn it is
}

void Board::print_graveyard() const // prints out figures that are already taken, both for white and black teams (in two seperate lines)
{
    std::vector<char> temp;
    for (int i = 0; i < graveyard.size(); ++i)
    {
        if (graveyard[i] == NULL)
            break;
        if (graveyard[i]->get_color() == 'w')
            cout << "\033[0m" << graveyard[i]->get_token() << ' ';
        else if (graveyard[i]->get_color() == 'b')
            temp.push_back(graveyard[i]->get_token());
    }
    cout << "\033[31m" << endl;
    for (int j = 0; j < temp.size(); j++)
    {
        cout << temp[j] << ' ';
    }
    cout << "\033[0m" << endl;
}