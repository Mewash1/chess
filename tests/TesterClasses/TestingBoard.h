#include "../../BoardLib/board.h"
#include "TestingPlayer.h"
#include <tuple>

class TestingBoard : public Board
{
public:
    TestingBoard(TestingPlayer*, TestingPlayer*, bool);
    void force_move(int, int, int, int);
    void add_new_figure(Figure*, int, int);
    Figure* get_figure(int, int);
    Figure* get_dead_figure(int);
};