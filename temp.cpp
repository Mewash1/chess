#include "./BoardLib/board.h"
// #include "./PlayerLib/player.h"

int main()
{
    Player p1('w', true);
    Player p2('b', true);

    Board b(&p1, &p2);
    b.dump();
    return 0;
}