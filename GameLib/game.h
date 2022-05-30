#include "../BoardLib/board.h"
#include "../PlayerLib/player.h"
#include <tuple>

class Game
{
private:
    Player *player1, *player2;
    Board* board;
public:
    Game();
    void menu();
    void show_board() {board->print();}
    void move_figure(std::tuple<int, int> old_cor, std::tuple<int, int> new_cor) {board->move_figure(old_cor, new_cor);}
    void next_turn() {board->switch_current_player();}
    Player* get_player1() {return player1;}
    Player* get_player2() {return player2;}
};