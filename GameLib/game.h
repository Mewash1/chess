#include "../BoardLib/board.h"
#include "../PlayerLib/player.h"
#include <tuple>

class Game
{
private:
    Player *player1, *player2, *current_player;
    Board *board;

public:
    Game() noexcept;
    ~Game();
    void menu() noexcept;
    void show_board() { board->print(); }
    std::string move_figure(std::tuple<int, int> old_cor, std::tuple<int, int> new_cor) { return board->move_figure(old_cor, new_cor); }
    std::string player_turn();
    std::string cpu_turn();
    void switch_player() noexcept;
    bool mate_check() const noexcept;
    Player *get_player1() const noexcept { return player1; }
    Player *get_player2() const noexcept { return player2; }
    Player *get_current_player() const noexcept { return current_player; }
    Board *get_board() const noexcept { return board; }
};