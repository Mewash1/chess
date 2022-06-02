#include <gtest/gtest.h>
#include "TesterClasses/TestingBoard.h"
#include "../PlayerLib/player.h"

TEST(Blocking, RookBlocksKing)
{
    TestingBoard b (new TestingPlayer('w', "Player 1", true), new TestingPlayer('b', "Player 2", true), true);
    
    b.add_new_figure(new King('w'), 0, 0);
    b.add_new_figure(new Rook('b'), 1, 1);
    
    EXPECT_THROW(b.move_figure(std::make_tuple(0, 0), std::make_tuple(1, 0)), std::logic_error);
    EXPECT_THROW(b.move_figure(std::make_tuple(0, 0), std::make_tuple(0, 1)), std::logic_error);

    b.force_move(0, 0, 2, 2);
    EXPECT_THROW(b.move_figure(std::make_tuple(0, 0), std::make_tuple(1, 2)), std::logic_error);
    EXPECT_THROW(b.move_figure(std::make_tuple(0, 0), std::make_tuple(2, 1)), std::logic_error);
    
}

TEST(Blocking, BishopBlocksKing)
{
    TestingBoard b (new TestingPlayer('w', "Player 1", true), new TestingPlayer('b', "Player 2", true), true);
    
    b.add_new_figure(new King('w'), 1, 0);
    b.add_new_figure(new Bishop('b'), 1, 1);
    EXPECT_THROW(b.move_figure(std::make_tuple(1, 0), std::make_tuple(0, 0)), std::logic_error);
    EXPECT_THROW(b.move_figure(std::make_tuple(1, 0), std::make_tuple(2, 0)), std::logic_error);

    b.force_move(1, 0, 1, 2);
    EXPECT_THROW(b.move_figure(std::make_tuple(1, 2), std::make_tuple(0, 2)), std::logic_error);
    EXPECT_THROW(b.move_figure(std::make_tuple(1, 2), std::make_tuple(2, 2)), std::logic_error);
}

TEST(Blocking, QueenBlocksKing)
{
    TestingBoard b (new TestingPlayer('w', "Player 1", true), new TestingPlayer('b', "Player 2", true), true);
    
    b.add_new_figure(new King('w'), 0, 2);
    b.add_new_figure(new Queen('b'), 2, 3);
    
    EXPECT_THROW(b.move_figure(std::make_tuple(0, 2), std::make_tuple(0, 3)), std::logic_error);
    EXPECT_THROW(b.move_figure(std::make_tuple(0, 2), std::make_tuple(1, 2)), std::logic_error);

    b.force_move(0, 2, 0, 4);
    EXPECT_THROW(b.move_figure(std::make_tuple(0, 4), std::make_tuple(0, 3)), std::logic_error);
    EXPECT_THROW(b.move_figure(std::make_tuple(0, 4), std::make_tuple(1, 4)), std::logic_error);

    b.force_move(0, 4, 4, 4);
    EXPECT_THROW(b.move_figure(std::make_tuple(4, 4), std::make_tuple(3, 4)), std::logic_error);
    EXPECT_THROW(b.move_figure(std::make_tuple(4, 4), std::make_tuple(4, 3)), std::logic_error);

    b.force_move(4, 4, 4, 2);
    EXPECT_THROW(b.move_figure(std::make_tuple(4, 2), std::make_tuple(3, 2)), std::logic_error);
    EXPECT_THROW(b.move_figure(std::make_tuple(4, 2), std::make_tuple(4, 3)), std::logic_error);

    b.force_move(4, 2, 3, 0);
    EXPECT_THROW(b.move_figure(std::make_tuple(3, 0), std::make_tuple(2, 0)), std::logic_error);

    b.force_move(3, 0, 3, 5);
    EXPECT_THROW(b.move_figure(std::make_tuple(3, 5), std::make_tuple(2, 5)), std::logic_error);
}

TEST(Blocking, HorseBlocksKing)
{
    TestingBoard b (new TestingPlayer('w', "Player 1", true), new TestingPlayer('b', "Player 2", true), true);
    
    b.add_new_figure(new King('w'), 1, 1);
    b.add_new_figure(new Horse('b'), 2, 2);
    EXPECT_THROW(b.move_figure(std::make_tuple(1, 1), std::make_tuple(1, 0)), std::logic_error);
    EXPECT_THROW(b.move_figure(std::make_tuple(1, 1), std::make_tuple(0, 1)), std::logic_error);

    b.force_move(1, 1, 1, 3);
    EXPECT_THROW(b.move_figure(std::make_tuple(1, 3), std::make_tuple(0, 3)), std::logic_error);
    EXPECT_THROW(b.move_figure(std::make_tuple(1, 3), std::make_tuple(1, 4)), std::logic_error);

    b.force_move(1, 3, 3, 3);
    EXPECT_THROW(b.move_figure(std::make_tuple(3, 3), std::make_tuple(3, 4)), std::logic_error);
    EXPECT_THROW(b.move_figure(std::make_tuple(3, 3), std::make_tuple(4, 3)), std::logic_error);

    b.force_move(1, 3, 3, 3);
    EXPECT_THROW(b.move_figure(std::make_tuple(3, 3), std::make_tuple(3, 4)), std::logic_error);
    EXPECT_THROW(b.move_figure(std::make_tuple(3, 3), std::make_tuple(4, 3)), std::logic_error);

    b.force_move(3, 3, 3, 1);
    EXPECT_THROW(b.move_figure(std::make_tuple(3, 1), std::make_tuple(4, 1)), std::logic_error);
    EXPECT_THROW(b.move_figure(std::make_tuple(3, 1), std::make_tuple(3, 0)), std::logic_error);
}


TEST(Blocking, PawnBlocksKing)
{
    TestingBoard b (new TestingPlayer('w', "Player 1", true), new TestingPlayer('b', "Player 2", true), true);
    
    b.add_new_figure(new King('w'), 2, 1);
    b.add_new_figure(new Pawn('b'), 1, 1);
    EXPECT_THROW(b.move_figure(std::make_tuple(2, 1), std::make_tuple(2, 0)), std::logic_error);
    EXPECT_THROW(b.move_figure(std::make_tuple(2, 1), std::make_tuple(2, 2)), std::logic_error);

}

TEST(Pin, RookProtectsKingFromRook)
{
    TestingBoard b (new TestingPlayer('w', "Player 1", true), new TestingPlayer('b', "Player 2", true), true);
    
    b.add_new_figure(new King('w'), 0, 0);
    b.add_new_figure(new Rook('w'), 0, 1);
    b.add_new_figure(new Rook('b'), 0, 7);

    EXPECT_THROW(b.move_figure(std::make_tuple(0, 1), std::make_tuple(1, 1)), std::logic_error);
}

TEST(Pin, RookProtectsKingFromQueen)
{
    TestingBoard b (new TestingPlayer('w', "Player 1", true), new TestingPlayer('b', "Player 2", true), true);
    
    b.add_new_figure(new King('w'), 0, 0);
    b.add_new_figure(new Rook('w'), 0, 1);
    b.add_new_figure(new Queen('b'), 0, 7);

    EXPECT_THROW(b.move_figure(std::make_tuple(0, 1), std::make_tuple(1, 1)), std::logic_error);
}

TEST(Pin, RookProtectsKingFromBishop)
{
    TestingBoard b (new TestingPlayer('w', "Player 1", true), new TestingPlayer('b', "Player 2", true), true);
    
    b.add_new_figure(new King('w'), 0, 0);
    b.add_new_figure(new Rook('w'), 1, 1);
    b.add_new_figure(new Bishop('b'), 7, 7);

    EXPECT_THROW(b.move_figure(std::make_tuple(1, 1), std::make_tuple(0, 1)), std::logic_error);
}

TEST(KingTake, Pawn)
{
    TestingBoard b (new TestingPlayer('w', "Player 1", true), new TestingPlayer('b', "Player 2", true), true);
    b.add_new_figure(new King('w'), 2, 1);
    b.add_new_figure(new Pawn('b'), 1, 1);

    b.move_figure(std::make_tuple(2, 1), std::make_tuple(1, 1));
    Figure* figure = b.get_dead_figure(0);
    ASSERT_EQ(figure->get_figure(), 'P');
}

TEST(KingTake, Rook)
{
    TestingBoard b (new TestingPlayer('w', "Player 1", true), new TestingPlayer('b', "Player 2", true), true);
    b.add_new_figure(new King('w'), 2, 0);
    b.add_new_figure(new Rook('b'), 1, 1);

    b.move_figure(std::make_tuple(2, 0), std::make_tuple(1, 1));
    Figure* figure = b.get_dead_figure(0);
    ASSERT_EQ(figure->get_figure(), 'R');
}

TEST(KingTake, Bishop)
{
    TestingBoard b (new TestingPlayer('w', "Player 1", true), new TestingPlayer('b', "Player 2", true), true);
    b.add_new_figure(new King('w'), 2, 1);
    b.add_new_figure(new Bishop('b'), 1, 1);

    b.move_figure(std::make_tuple(2, 1), std::make_tuple(1, 1));
    Figure* figure = b.get_dead_figure(0);
    ASSERT_EQ(figure->get_figure(), 'B');
}

TEST(KingTake, Horse)
{
    TestingBoard b (new TestingPlayer('w', "Player 1", true), new TestingPlayer('b', "Player 2", true), true);
    b.add_new_figure(new King('w'), 2, 1);
    b.add_new_figure(new Horse('b'), 1, 1);

    b.move_figure(std::make_tuple(2, 1), std::make_tuple(1, 1));
    Figure* figure = b.get_dead_figure(0);
    ASSERT_EQ(figure->get_figure(), 'H');
}

TEST(RookTake, Pawn)
{
    TestingBoard b (new TestingPlayer('w', "Player 1", true), new TestingPlayer('b', "Player 2", true), true);
    b.add_new_figure(new Rook('w'), 2, 1);
    b.add_new_figure(new Pawn('b'), 1, 1);

    b.move_figure(std::make_tuple(2, 1), std::make_tuple(1, 1));
    Figure* figure = b.get_dead_figure(0);
    ASSERT_EQ(figure->get_figure(), 'P');
}

TEST(RookTake, Rook)
{
    TestingBoard b (new TestingPlayer('w', "Player 1", true), new TestingPlayer('b', "Player 2", true), true);
    b.add_new_figure(new Rook('w'), 2, 1);
    b.add_new_figure(new Rook('b'), 1, 1);

    b.move_figure(std::make_tuple(2, 1), std::make_tuple(1, 1));
    Figure* figure = b.get_dead_figure(0);
    ASSERT_EQ(figure->get_figure(), 'R');
}

TEST(RookTake, Queen)
{
    TestingBoard b (new TestingPlayer('w', "Player 1", true), new TestingPlayer('b', "Player 2", true), true);
    b.add_new_figure(new Rook('w'), 2, 1);
    b.add_new_figure(new Queen('b'), 1, 1);

    b.move_figure(std::make_tuple(2, 1), std::make_tuple(1, 1));
    Figure* figure = b.get_dead_figure(0);
    ASSERT_EQ(figure->get_figure(), 'Q');
}

TEST(RookTake, Bishop)
{
    TestingBoard b (new TestingPlayer('w', "Player 1", true), new TestingPlayer('b', "Player 2", true), true);
    b.add_new_figure(new Rook('w'), 2, 1);
    b.add_new_figure(new Bishop('b'), 1, 1);

    b.move_figure(std::make_tuple(2, 1), std::make_tuple(1, 1));
    Figure* figure = b.get_dead_figure(0);
    ASSERT_EQ(figure->get_figure(), 'B');
}

TEST(RookTake, Horse)
{
    TestingBoard b (new TestingPlayer('w', "Player 1", true), new TestingPlayer('b', "Player 2", true), true);
    b.add_new_figure(new Rook('w'), 2, 1);
    b.add_new_figure(new Horse('b'), 1, 1);

    b.move_figure(std::make_tuple(2, 1), std::make_tuple(1, 1));
    Figure* figure = b.get_dead_figure(0);
    ASSERT_EQ(figure->get_figure(), 'H');
}


TEST(QueenTake, Pawn)
{
    TestingBoard b (new TestingPlayer('w', "Player 1", true), new TestingPlayer('b', "Player 2", true), true);
    b.add_new_figure(new Queen('w'), 2, 1);
    b.add_new_figure(new Pawn('b'), 1, 1);

    b.move_figure(std::make_tuple(2, 1), std::make_tuple(1, 1));
    Figure* figure = b.get_dead_figure(0);
    ASSERT_EQ(figure->get_figure(), 'P');
}

TEST(QueenTake, Rook)
{
    TestingBoard b (new TestingPlayer('w', "Player 1", true), new TestingPlayer('b', "Player 2", true), true);
    b.add_new_figure(new Queen('w'), 2, 1);
    b.add_new_figure(new Rook('b'), 1, 1);

    b.move_figure(std::make_tuple(2, 1), std::make_tuple(1, 1));
    Figure* figure = b.get_dead_figure(0);
    ASSERT_EQ(figure->get_figure(), 'R');
}

TEST(QueenTake, Queen)
{
    TestingBoard b (new TestingPlayer('w', "Player 1", true), new TestingPlayer('b', "Player 2", true), true);
    b.add_new_figure(new Queen('w'), 2, 1);
    b.add_new_figure(new Queen('b'), 1, 1);

    b.move_figure(std::make_tuple(2, 1), std::make_tuple(1, 1));
    Figure* figure = b.get_dead_figure(0);
    ASSERT_EQ(figure->get_figure(), 'Q');
}

TEST(QueenTake, Bishop)
{
    TestingBoard b (new TestingPlayer('w', "Player 1", true), new TestingPlayer('b', "Player 2", true), true);
    b.add_new_figure(new Queen('w'), 2, 1);
    b.add_new_figure(new Bishop('b'), 1, 1);

    b.move_figure(std::make_tuple(2, 1), std::make_tuple(1, 1));
    Figure* figure = b.get_dead_figure(0);
    ASSERT_EQ(figure->get_figure(), 'B');
}

TEST(QueenTake, Horse)
{
    TestingBoard b (new TestingPlayer('w', "Player 1", true), new TestingPlayer('b', "Player 2", true), true);
    b.add_new_figure(new Queen('w'), 2, 1);
    b.add_new_figure(new Horse('b'), 1, 1);

    b.move_figure(std::make_tuple(2, 1), std::make_tuple(1, 1));
    Figure* figure = b.get_dead_figure(0);
    ASSERT_EQ(figure->get_figure(), 'H');
}



TEST(BishopTake, Pawn)
{
    TestingBoard b (new TestingPlayer('w', "Player 1", true), new TestingPlayer('b', "Player 2", true), true);
    b.add_new_figure(new Bishop('w'), 2, 1);
    b.add_new_figure(new Pawn('b'), 1, 0);

    b.move_figure(std::make_tuple(2, 1), std::make_tuple(1, 0));
    Figure* figure = b.get_dead_figure(0);
    ASSERT_EQ(figure->get_figure(), 'P');
}

TEST(BishopTake, Rook)
{
    TestingBoard b (new TestingPlayer('w', "Player 1", true), new TestingPlayer('b', "Player 2", true), true);
    b.add_new_figure(new Bishop('w'), 2, 1);
    b.add_new_figure(new Rook('b'), 1, 0);

    b.move_figure(std::make_tuple(2, 1), std::make_tuple(1, 0));
    Figure* figure = b.get_dead_figure(0);
    ASSERT_EQ(figure->get_figure(), 'R');
}

TEST(BishopTake, Queen)
{
    TestingBoard b (new TestingPlayer('w', "Player 1", true), new TestingPlayer('b', "Player 2", true), true);
    b.add_new_figure(new Bishop('w'), 2, 1);
    b.add_new_figure(new Queen('b'), 1, 0);

    b.move_figure(std::make_tuple(2, 1), std::make_tuple(1, 0));
    Figure* figure = b.get_dead_figure(0);
    ASSERT_EQ(figure->get_figure(), 'Q');
}

TEST(BishopTake, Bishop)
{
    TestingBoard b (new TestingPlayer('w', "Player 1", true), new TestingPlayer('b', "Player 2", true), true);
    b.add_new_figure(new Bishop('w'), 2, 1);
    b.add_new_figure(new Bishop('b'), 1, 0);

    b.move_figure(std::make_tuple(2, 1), std::make_tuple(1, 0));
    Figure* figure = b.get_dead_figure(0);
    ASSERT_EQ(figure->get_figure(), 'B');
}

TEST(BishopTake, Horse)
{
    TestingBoard b (new TestingPlayer('w', "Player 1", true), new TestingPlayer('b', "Player 2", true), true);
    b.add_new_figure(new Bishop('w'), 2, 1);
    b.add_new_figure(new Horse('b'), 1, 0);

    b.move_figure(std::make_tuple(2, 1), std::make_tuple(1, 0));
    Figure* figure = b.get_dead_figure(0);
    ASSERT_EQ(figure->get_figure(), 'H');
}



TEST(PawnTake, Pawn)
{
    TestingBoard b (new TestingPlayer('w', "Player 1", true), new TestingPlayer('b', "Player 2", true), true);
    b.add_new_figure(new Pawn('w'), 2, 1);
    b.add_new_figure(new Pawn('b'), 1, 0);

    b.move_figure(std::make_tuple(2, 1), std::make_tuple(1, 0));
    Figure* figure = b.get_dead_figure(0);
    ASSERT_EQ(figure->get_figure(), 'P');
}

TEST(PawnTake, Rook)
{
    TestingBoard b (new TestingPlayer('w', "Player 1", true), new TestingPlayer('b', "Player 2", true), true);
    b.add_new_figure(new Pawn('w'), 2, 1);
    b.add_new_figure(new Rook('b'), 1, 0);

    b.move_figure(std::make_tuple(2, 1), std::make_tuple(1, 0));
    Figure* figure = b.get_dead_figure(0);
    ASSERT_EQ(figure->get_figure(), 'R');
}

TEST(PawnTake, Queen)
{
    TestingBoard b (new TestingPlayer('w', "Player 1", true), new TestingPlayer('b', "Player 2", true), true);
    b.add_new_figure(new Pawn('w'), 2, 1);
    b.add_new_figure(new Queen('b'), 1, 0);

    b.move_figure(std::make_tuple(2, 1), std::make_tuple(1, 0));
    Figure* figure = b.get_dead_figure(0);
    ASSERT_EQ(figure->get_figure(), 'Q');
}

TEST(PawnTake, Bishop)
{
    TestingBoard b (new TestingPlayer('w', "Player 1", true), new TestingPlayer('b', "Player 2", true), true);
    b.add_new_figure(new Pawn('w'), 2, 1);
    b.add_new_figure(new Bishop('b'), 1, 0);

    b.move_figure(std::make_tuple(2, 1), std::make_tuple(1, 0));
    Figure* figure = b.get_dead_figure(0);
    ASSERT_EQ(figure->get_figure(), 'B');
}

TEST(PawnTake, Horse)
{
    TestingBoard b (new TestingPlayer('w', "Player 1", true), new TestingPlayer('b', "Player 2", true), true);
    b.add_new_figure(new Pawn('w'), 2, 1);
    b.add_new_figure(new Horse('b'), 1, 0);

    b.move_figure(std::make_tuple(2, 1), std::make_tuple(1, 0));
    Figure* figure = b.get_dead_figure(0);
    ASSERT_EQ(figure->get_figure(), 'H');
}


TEST(Mate, RookAndQueen)
{
    TestingBoard b (new TestingPlayer('w', "Player 1", true), new TestingPlayer('b', "Player 2", true), true);
    b.add_new_figure(new King('w'), 0, 0);
    b.add_new_figure(new Rook('b'), 0, 7);
    b.add_new_figure(new Queen('b'), 1, 7);

    ASSERT_EQ(b.mate_check(), true);
}

TEST(Castling, LongWhiteCast)
{
    TestingBoard b (new TestingPlayer('w', "Player 1", true), new TestingPlayer('b', "Player 2", true), true);
    b.add_new_figure(new King('w'), 7, 4);
    b.add_new_figure(new Rook('w'), 7, 0);
    
    b.move_figure(std::make_tuple(7, 4), std::make_tuple(7, 2));
    Figure* figure1 = b.get_figure(7, 2);
    Figure* figure2 = b.get_figure(7, 3);
    ASSERT_EQ(figure1->get_figure(), 'K');
    ASSERT_EQ(figure2->get_figure(), 'R');
}

TEST(Castling, LongWhiteCastImpossible)
{
    TestingBoard b (new TestingPlayer('w', "Player 1", true), new TestingPlayer('b', "Player 2", true), true);
    b.add_new_figure(new King('w'), 7, 4);
    b.add_new_figure(new Rook('w'), 7, 0);

    // king at check
    b.add_new_figure(new Rook('b'), 0, 4);
    EXPECT_THROW(b.move_figure(std::make_tuple(7, 4), std::make_tuple(7, 2)), std::logic_error);

    // rook in the way
    b.force_move(0, 4, 0, 7);
    b.add_new_figure(new Rook('w'), 7, 1);
    EXPECT_THROW(b.move_figure(std::make_tuple(7, 4), std::make_tuple(7, 2)), std::logic_error);

    b.force_move(7, 1, 6, 1);
    b.get_figure(7, 0)->set_moved(true);
    EXPECT_THROW(b.move_figure(std::make_tuple(7, 4), std::make_tuple(7, 2)), std::logic_error);

    b.get_figure(7, 0)->set_moved(false);
    b.get_figure(7, 4)->set_moved(true);
    EXPECT_THROW(b.move_figure(std::make_tuple(7, 4), std::make_tuple(7, 2)), std::logic_error);
}

TEST(Castling, ShortWhiteCast)
{
    TestingBoard b (new TestingPlayer('w', "Player 1", true), new TestingPlayer('b', "Player 2", true), true);
    b.add_new_figure(new King('w'), 7, 4);
    b.add_new_figure(new Rook('w'), 7, 7);
    
    b.move_figure(std::make_tuple(7, 4), std::make_tuple(7, 6));
    Figure* figure1 = b.get_figure(7, 6);
    Figure* figure2 = b.get_figure(7, 5);
    ASSERT_EQ(figure1->get_figure(), 'K');
    ASSERT_EQ(figure2->get_figure(), 'R');
}

TEST(Castling, ShortWhiteCastImpossible)
{
    TestingBoard b (new TestingPlayer('w', "Player 1", true), new TestingPlayer('b', "Player 2", true), true);
    b.add_new_figure(new King('w'), 7, 4);
    b.add_new_figure(new Rook('w'), 7, 7);

    // king at check
    b.add_new_figure(new Rook('b'), 0, 4);
    EXPECT_THROW(b.move_figure(std::make_tuple(7, 4), std::make_tuple(7, 2)), std::logic_error);

    // rook in the way
    b.force_move(0, 4, 0, 7);
    b.add_new_figure(new Rook('w'), 7, 6);
    EXPECT_THROW(b.move_figure(std::make_tuple(7, 4), std::make_tuple(7, 2)), std::logic_error);

    b.force_move(7, 6, 6, 1);
    b.get_figure(7, 7)->set_moved(true);
    EXPECT_THROW(b.move_figure(std::make_tuple(7, 4), std::make_tuple(7, 2)), std::logic_error);

    b.get_figure(7, 7)->set_moved(false);
    b.get_figure(7, 4)->set_moved(true);
    EXPECT_THROW(b.move_figure(std::make_tuple(7, 4), std::make_tuple(7, 2)), std::logic_error);
}


TEST(Castling, LongBlackCast)
{
    TestingBoard b (new TestingPlayer('w', "Player 1", true), new TestingPlayer('b', "Player 2", true), false);
    b.add_new_figure(new King('b'), 0, 4);
    b.add_new_figure(new Rook('b'), 0, 0);
    
    b.move_figure(std::make_tuple(0, 4), std::make_tuple(0, 2));
    Figure* figure1 = b.get_figure(0, 2);
    Figure* figure2 = b.get_figure(0, 3);
    ASSERT_EQ(figure1->get_figure(), 'K');
    ASSERT_EQ(figure2->get_figure(), 'R');
}

TEST(Castling, LongBlackCastImpossible)
{
    TestingBoard b (new TestingPlayer('w', "Player 1", true), new TestingPlayer('b', "Player 2", true), false);
    b.add_new_figure(new King('b'), 0, 4);
    b.add_new_figure(new Rook('b'), 0, 0);

    // king at check
    b.add_new_figure(new Rook('w'), 7, 4);
    EXPECT_THROW(b.move_figure(std::make_tuple(0, 4), std::make_tuple(0, 2)), std::logic_error);

    // rook in the way
    b.force_move(7, 4, 0, 7);
    b.add_new_figure(new Rook('b'), 0, 2);
    EXPECT_THROW(b.move_figure(std::make_tuple(0, 4), std::make_tuple(0, 2)), std::logic_error);

    b.force_move(0, 2, 6, 1);
    b.get_figure(0, 0)->set_moved(true);
    EXPECT_THROW(b.move_figure(std::make_tuple(0, 4), std::make_tuple(0, 2)), std::logic_error);

    b.get_figure(0, 0)->set_moved(false);
    b.get_figure(0, 4)->set_moved(true);
    EXPECT_THROW(b.move_figure(std::make_tuple(0, 4), std::make_tuple(0, 2)), std::logic_error);
}

TEST(Castling, ShortBlackCast)
{
    TestingBoard b (new TestingPlayer('w', "Player 1", true), new TestingPlayer('b', "Player 2", true), false);
    b.add_new_figure(new King('b'), 0, 4);
    b.add_new_figure(new Rook('b'), 0, 7);
    
    b.move_figure(std::make_tuple(0, 4), std::make_tuple(0, 6));
    Figure* figure1 = b.get_figure(0, 6);
    Figure* figure2 = b.get_figure(0, 5);
    ASSERT_EQ(figure1->get_figure(), 'K');
    ASSERT_EQ(figure2->get_figure(), 'R');
}

TEST(Castling, ShortBlackCastImpossible)
{
    TestingBoard b (new TestingPlayer('w', "Player 1", true), new TestingPlayer('b', "Player 2", true), false);
    b.add_new_figure(new King('b'), 0, 4);
    b.add_new_figure(new Rook('b'), 0, 7);

    // king at check
    b.add_new_figure(new Rook('w'), 7, 4);
    EXPECT_THROW(b.move_figure(std::make_tuple(0, 4), std::make_tuple(0, 2)), std::logic_error);

    // rook in the way
    b.force_move(7, 4, 0, 7);
    b.add_new_figure(new Rook('b'), 0, 6);
    EXPECT_THROW(b.move_figure(std::make_tuple(0, 4), std::make_tuple(0, 2)), std::logic_error);

    b.force_move(0, 6, 6, 1);
    b.get_figure(0, 7)->set_moved(true);
    EXPECT_THROW(b.move_figure(std::make_tuple(0, 4), std::make_tuple(0, 2)), std::logic_error);

    b.get_figure(0, 7)->set_moved(false);
    b.get_figure(0, 4)->set_moved(true);
    EXPECT_THROW(b.move_figure(std::make_tuple(0, 4), std::make_tuple(0, 2)), std::logic_error);
}