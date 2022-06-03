#include "TestingBoard.h"
#include "../../PlayerLib/player.h"
#include <tuple>

using std::get;

TestingBoard::TestingBoard(TestingPlayer* player1, TestingPlayer* player2, bool first_current)
{
    this->player1 = player1;
    this->player2 = player2;

    if (first_current)
        current_player = player1;
    else
        current_player = player2;
}

void TestingBoard::force_move(int x, int y, int nx, int ny)
{
    if (table[x][y] != NULL)
    {
        table[nx][ny] = table[x][y];

        if (table[nx][ny]->get_figure() == 'K')
            current_player->set_king(std::make_tuple(nx, ny));

    }
}

void TestingBoard::add_new_figure(Figure* new_figure, int x, int y)
{
    table[x][y] = new_figure;
    if (table[x][y]->get_figure() == 'K')
        if (player1->get_color() == 'w' && new_figure->get_color() == 'w')
            player1->set_king(std::make_tuple(x, y));
        else if (player1->get_color() == 'w' && new_figure->get_color() == 'b')
            player2->set_king(std::make_tuple(x, y));
        else if (player1->get_color() == 'b' && new_figure->get_color() == 'b')
            player2->set_king(std::make_tuple(x, y));
        else if (player1->get_color() == 'b' && new_figure->get_color() == 'w')
            player1->set_king(std::make_tuple(x, y));
}

Figure* TestingBoard::get_figure(int x, int y)
{
    if (table[x][y] != NULL)
        return table[x][y];
    else
        throw std::out_of_range("space is empty");
}

Figure* TestingBoard::get_dead_figure(int index)
{
    return graveyard[index];
}