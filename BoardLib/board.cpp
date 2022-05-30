#include "board.h"
// #include "../PlayerLib/player.h"
#include <vector>
#include <tuple>
#include <Windows.h>

using namespace std;

Board::Board(Player *player1, Player *player2)
{
    // for (int i = 0; i < 8; i++)
    //     for (int j = 0; j < 8; j++)
    //         table[i][j] = NULL;

    int v = 0;
    for (int i = 8; i > 6; i--)
        for (int j = 0; j < 8; j++)
        {
            table[i][j] = player1->get_figures()[v];
            v++;
        }

    v = 0;
    for (int i = 0; i < 2; i++)
        for (int j = 7; j >= 0; j--)
        {
            table[i][j] = player2->get_figures()[v];
            v++;
        }

    this->player1 = player1;
    this->player2 = player2;
    current_player = player1;
}

std::string Board::move_figure(tuple<int, int> old_cord, tuple<int, int> new_cord)
{
    Figure *moved_piece = table[get<0>(old_cord)][get<1>(old_cord)];
    string temp = "";
    temp += to_string(get<0>(old_cord));
    temp += to_string(get<1>(old_cord));
    temp += " ";
    temp += moved_piece->get_token();
    temp += " ";
    temp += to_string(get<0>(new_cord));
    temp += to_string(get<1>(new_cord));

    if (table[get<0>(new_cord)][get<1>(new_cord)] != NULL)
    {
        // current_player.points += table[get<0>(new_cord)][get<1>(new_cord)]->take();
        table[get<0>(new_cord)][get<1>(new_cord)]->take();
    }
    table[get<0>(new_cord)][get<1>(new_cord)] = moved_piece;
    return temp;
}

void Board::dump()
{
    for (int y = 7; y >= 0; --y)
    {
        for (int i = 0; i < 8; i++)
        {
            if (table[i][y] == NULL)
            {
                cout << " ";
                break;
            }
            cout << table[i][y]->get_token();
        }
        cout << endl;
    }
}

void print_row(int i, const Board b) {
    HANDLE hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 15);
    srand(time(NULL));
    for (int j = 0; j < 8; j++) {
        if (b.table[i][j] == NULL)
            std::cout << "   |";
        else {
            std::cout << ' ' << (b.table[i][j])->get_token() << " |";
        }
    }
    std::cout << endl;
}

std::ostream &operator<<(std::ostream &os, const Board b)
{
    HANDLE hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 14);
    std::cout << "-------------------------------------" << std::endl;
    std::cout << "|   | A | B | C | D | E | F | G | H |" << std::endl;
    std::cout << "-------------------------------------" << std::endl;
    for (int i = 0; i < 8; i++) {
        SetConsoleTextAttribute(hConsole, 14);
        std::cout << "| " << (i + 1) << " |";
        SetConsoleTextAttribute(hConsole, 15);
        print_row(i, b);
        std::cout << "-------------------------------------" << std::endl;
    }
}
