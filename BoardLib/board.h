#include "../PlayerLib/player.h"
#include "include_all_figures.h"
#include <string>
#include <iostream>

class Board{
    private:
        Player* player1, player2, current_player;
        Figure* table[8][8] = {{NULL}};
        Figure* graveyard[32] = {NULL};
        std::string force_move_figure(tuple<int,int>, tuple<int,int>);//used for special moves


    public:
        Board(Player *player1, Player *player2);
        void remove_figure();
        std::string move_figure(tuple<int,int>, tuple<int,int>);
        vector<tuple<int,int>>  validate_move();
        void kill_figure(tuple<int, int>);
        void revive_figure(int graveyard_index, tuple<int,int>);
        //void dump
        Player* end_turn(); //end turn returns next player
        friend std::ostream& operator<<(std::ostream& os, const Board b);
};