#include<co/unitest.h>
#include "coins.h"

DEF_test(coins_dp)
{
    Comb c = Comb();

    DEF_case(coins_1)
    {
        EXPECT_EQ(c.solution_N(1), 1);
    }

    DEF_case(coins_4)
    {
        EXPECT_EQ(c.solution_N(4), 1);
    }

    DEF_case(coins_6)
    {
        EXPECT_EQ(c.solution_N(6), 2);
    }
}