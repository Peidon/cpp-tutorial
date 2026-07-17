//
// Created by Pedro's Jet on 25/2/2026.
//
#define BOOST_TEST_MODULE BoostTests
#include <boost/test/included/unit_test.hpp>

#include "heap.h"
#include "intervals.h"
#include <boost/test/unit_test.hpp>

namespace letscode {

    BOOST_AUTO_TEST_CASE(intervals_merge0) {
        vector<vector<int>> intervals = {{1,3},{2,6},{8,10},{15,18}};
        const vector<vector<int>> expected = {{1,6},{8,10},{15,18}};
        const vector<vector<int>> got = Solution56::merge(intervals);
        BOOST_ASSERT(got.size() == expected.size());
        for (int i=0; i<expected.size(); i++) {
            BOOST_CHECK_EQUAL_COLLECTIONS(got.at(i).begin(),got.at(i).end(), expected.at(i).begin(), expected.at(i).end());
        }
    }

    BOOST_AUTO_TEST_CASE(intervals_merge1) {
        vector<vector<int>> intervals = {{1,4},{4,5}};
        const vector<vector<int>> expected = {{1,5}};
        const vector<vector<int>> got = Solution56::merge(intervals);
        BOOST_ASSERT(got.size() == expected.size());
        for (int i=0; i<expected.size(); i++) {
            BOOST_CHECK_EQUAL_COLLECTIONS(got.at(i).begin(),got.at(i).end(), expected.at(i).begin(), expected.at(i).end());
        }
    }

    BOOST_AUTO_TEST_CASE(intervals_merge2) {
        vector<vector<int>> intervals = {{1,4},{0,2},{3,5}};
        const vector<vector<int>> expected = {{0,5}};
        const vector<vector<int>> got = Solution56::merge(intervals);
        BOOST_ASSERT(got.size() == expected.size());
        for (int i=0; i<expected.size(); i++) {
            BOOST_CHECK_EQUAL_COLLECTIONS(got.at(i).begin(),got.at(i).end(), expected.at(i).begin(), expected.at(i).end());
        }
    }

    BOOST_AUTO_TEST_CASE(intervals_merge3) {
        vector<vector<int>> intervals = {{3,3},{0,1},{0,0}};
        const vector<vector<int>> expected = {{0,1},{3,3}};
        const vector<vector<int>> got = Solution56::merge(intervals);
        BOOST_ASSERT(got.size() == expected.size());
        for (int i=0; i<expected.size(); i++) {
            BOOST_CHECK_EQUAL_COLLECTIONS(got.at(i).begin(),got.at(i).end(), expected.at(i).begin(), expected.at(i).end());
        }
    }

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
} // letscode