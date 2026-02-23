#include <co/unitest.h>
#include "stock.h"

DEF_test(max_profit) {
    int got = letcode121::Solution::maxProfit(vector<int>{7,1,5,3,6,4});
    EXPECT_EQ(got, 5);

    got = letcode121::Solution::maxProfit(vector<int>{7,6,4,3,1});
    EXPECT_EQ(got, 0);
}