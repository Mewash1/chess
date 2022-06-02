#include "board.h"
#include <vector>
#include <tuple>
#include <map>

using namespace std;

void Board::print_row(int i)
{
    /*HANDLE hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 15);*/
    srand(time(NULL));
    if (current_player->get_color() == 'w') // no turning
    // if (true)
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
    }
    else
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
    }
    std::cout << "\033[33m| " << (8 - i) << " |\033[0m";
    std::cout << endl;
}

void Board::print()
{
    /*HANDLE hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 14);*/
    std::cout << "\033c"; // clear
    std::cout << "\033[33m-----------------------------------------" << std::endl;
    if (current_player->get_color() == 'w')
        std::cout << "|   | A | B | C | D | E | F | G | H |   |" << std::endl;
    else
        std::cout << "|   | H | G | F | E | D | C | B | A |   |" << std::endl;
    std::cout << "-----------------------------------------\033[0m" << std::endl;
    for (int i = 0; i < 8; i++)
    {
        // SetConsoleTextAttribute(hConsole, 14);
        // if (true)
        if (current_player->get_color() == 'w')
            std::cout << "\033[33m| " << (8 - i) << " |\033[0m";
        else
            std::cout << "\033[33m| " << (i + 1) << " |\033[0m";
        // SetConsoleTextAttribute(hConsole, 15);
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
    std::cout << current_player->get_name() << "'s turn\n";
}

void Board::print_graveyard()
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