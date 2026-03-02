//
// Created by Pedro's Jet on 1/3/2026.
//

#include "heap.h"

#include <boost/test/unit_test.hpp>
#include <tuple>

namespace letscode {
    BOOST_AUTO_TEST_CASE(kTH_largest) {
        const vector<tuple<vector<int>,int,int>> testsdata = {
            std::make_tuple(vector<int>{3,2,1,5,6,4}, 2, 5),
            std::make_tuple(vector<int>{3,2,3,1,2,4,5,5,6}, 4, 4)
        };
        for (tuple<vector<int>,int,int> td: testsdata) {
            vector<int> nums = std::get<0>(td);
            const int k = std::get<1>(td);
            int expect = std::get<2>(td);
            int got = Solution::findKthLargest(nums, k);
            BOOST_TEST(got == expect);
        }
    }
}
