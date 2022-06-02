#include <gtest/gtest.h>
#include "../ChessLib/figures/figure.h"
#include "include_all_figures.h"

TEST(King, GettersAndSetters)
{
    King k('w');
    ASSERT_EQ(k.get_color(), 'w');
    ASSERT_EQ(k.get_figure(), 'K');
    ASSERT_EQ(k.get_num_of_moves(), 1);
    
    k.take();
}