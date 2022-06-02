#include <gtest/gtest.h>
#include "TesterClasses/TestingBoard.h"
#include "../PlayerLib/player.h"

TEST(Board, KingAndRook)
{
    TestingBoard b (new TestingPlayer('w', "Player 1", true), new TestingPlayer('b', "Player 2", true), true);
    
    b.add_new_figure(new King('w'), 0, 0);
    
    b.add_new_figure(new Rook('b'), 1, 3);
    
    EXPECT_THROW(b.move_figure(std::make_tuple(0, 0), std::make_tuple(1, 0)), std::logic_error);
}

TEST(Board, KingAndPawn)
{
    TestingBoard b (new TestingPlayer('w', "Player 1", true), new TestingPlayer('b', "Player 2", true), true);
    
    b.add_new_figure(new King('w'), 0, 0);
    
    b.add_new_figure(new Pawn('b'), 0, 1);
    
    b.move_figure(std::make_tuple(0, 0), std::make_tuple(0, 1));
    char figure = b.get_dead_figure(0)->get_figure();
    ASSERT_EQ(figure, 'P');
}