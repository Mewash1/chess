#include <vector>
#include <iostream>

using std::cout;
using std::endl;
using std::tuple;
using std::vector;

class Figure
{
protected:
    bool moved;
    char figure;
    char token;
    char color;
    bool taken;
    unsigned int price;
    vector<tuple<int,int>> moves;

public:
    Figure();
    Figure(char color);
    vector<char> figures;
    // geters
    char get_figure() const noexcept;
    char get_color() const noexcept;
    bool is_taken() const noexcept;
    vector<tuple<int,int>> get_moves() const noexcept; // return vector of all movements to further
    char get_token() const noexcept;
    // seters
    unsigned int take() noexcept;
};