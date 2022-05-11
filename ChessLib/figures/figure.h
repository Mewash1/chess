#include <vector>
#include <iostream>

using std::cout;
using std::endl;
using std::tuple;
using std::vector;

class Figure
{
private:
    bool moved;
    char figure;
    char color;
    bool taken;
    unsigned int price;

public:
    Figure(char figure);
    vector<char> figures;
    // geters
    char get_figure() const noexcept;
    char get_color() const noexcept;
    bool is_taken() const noexcept;
    vector<tuple<int>> get_moves() const noexcept; // return vector of all movements to further
    // seters
    unsigned int take() noexcept;
    void set_figure(char new_name);
}