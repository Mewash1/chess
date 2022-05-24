#include "figure.h"
using std::cout;
using std::endl;
using std::tuple;
using std::vector;

class King : public Figure
{
};

vector<tuple<int>>
king_move()
{
    vector<tuple<int>> temp = {(1, 0), (-1, 0), (0, 1), (0, -1)};
    return temp;
}