class Board{
    private:
        void* table[8][8];
    public:
        Board();
        void place_figure();
        void remove_figure();
        void move_figure();
        
}