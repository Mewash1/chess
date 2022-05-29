#include "../PlayerLib/player.h"
#include <string>

class Board
{
private:
    Player *player1, player2, current_player;
    Figure *table[8][8] = {{NULL}};
    Figure *graveyard[32] = {NULL};

public:
    Board();
    void remove_figure();
    std::string move_figure(tuple<int, int>, tuple<int, int>);
    vector<tuple<int, int>> validate_move();
    void kill_figure(tuple<int, int>);
    void revive_figure(int graveyard_index, tuple<int, int>);
    void dump();
    Player *end_turn(); // end turn returns next player
};