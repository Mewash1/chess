#include "../PlayerLib/player.h"
#include <string>
#include <iostream>
#ifndef BOARD_H
#define BOARD_H

class Board
{
private:
    Player *player1, *player2, *current_player;
    Figure *table[8][8] = {{NULL}};
    Figure *graveyard[32] = {NULL};


    public:
        Board(Player *player1, Player *player2);
        void remove_figure();
        std::string move_figure(tuple<int,int>, tuple<int,int>);
        vector<tuple<int,int>>  validate_move();
        // void kill_figure(tuple<int, int>);
        void revive_figure(int graveyard_index, tuple<int,int>);
        void dump();
        Player* end_turn(); //end turn returns next player
        void print();
        void print_row(int i);
        void switch_current_player();
};

#endif
