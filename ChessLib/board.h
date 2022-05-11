class Board{
    private:
        void* table[8][8];
    public:
        Board();
        void place_pawn();
        void remove_pawn();
        void move_pawn();
}