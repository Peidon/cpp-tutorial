//
// Created by Pedro's Jet on 25/2/2026.
//

#include "intervals.h"
#include <boost/test/unit_test.hpp>

namespace letscode56 {

    BOOST_AUTO_TEST_CASE(intervals) {
        vector<vector<int>> intervals = {{1,3},{2,6},{8,10},{15,18}};
        const vector<vector<int>> expected = {{1,6},{8,10},{15,18}};
        const vector<vector<int>> got = Solution::merge(intervals);
        BOOST_ASSERT(got.size() == expected.size());
        for (int i=0; i<expected.size(); i++) {
            BOOST_CHECK_EQUAL_COLLECTIONS(got.at(i).begin(),got.at(i).end(), expected.at(i).begin(), expected.at(i).end());
        }
    }

    BOOST_AUTO_TEST_CASE(merge0) {
        vector<vector<int>> intervals = {{1,4},{4,5}};
        const vector<vector<int>> expected = {{1,5}};
        const vector<vector<int>> got = Solution::merge(intervals);
        BOOST_ASSERT(got.size() == expected.size());
        for (int i=0; i<expected.size(); i++) {
            BOOST_CHECK_EQUAL_COLLECTIONS(got.at(i).begin(),got.at(i).end(), expected.at(i).begin(), expected.at(i).end());
        }
    }
} // letscode56