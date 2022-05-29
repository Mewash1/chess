#include <vector>
#include <iostream>
#ifndef FIGURE_H
#define FIGURE_H
using std::cout;
using std::endl;
using std::tuple;
using std::vector;

class Figure
{
protected:
    bool moved = false;
    char figure;
    char token;
    char color;
    bool taken;
    unsigned int price;
    int num_of_moves;
    vector<tuple<int,int>> moves;

public:
    Figure();
    Figure(char color);
    vector<char> figures;
    // geters
    char get_figure() const noexcept;
    char get_color() const noexcept;
    int get_num_of_moves();
    void set_num_of_moves(int new_num);
    bool is_taken() const noexcept;
    vector<tuple<int,int>> get_moves() const noexcept; // return vector of all movements to further
    char get_token() const noexcept;
    // seters
    unsigned int take() noexcept;
};

#endif