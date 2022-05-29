#include "include_all_figures.h"
using std::vector;

class Player
{
private:
    bool human;
    char color;
    vector<Figure*> figures;
public:
    Player(char color, bool human = true);
    vector<Figure*> get_figures() {return figures;}
};