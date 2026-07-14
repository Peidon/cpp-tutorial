//
// Created by Pedro's Jet on 25/2/2026.
//

#ifndef TUTORIAL_INTERVALS_H
#define TUTORIAL_INTERVALS_H
#include <vector>
#include <algorithm>

using namespace std;

namespace letscode56 {
class Solution {

    static bool compareIntervals(const vector<int> &a, const vector<int> &b) {
        return a.front() < b.front();
    }

public:
    static vector<vector<int>> merge(vector<vector<int>>& intervals) {
        std::sort(intervals.begin(), intervals.end(), compareIntervals);
        vector<vector<int>> merged;
        int cur = 0; // track the current iterate item which is going to push in the merged list

        // init i = 1, cur = 0
        // cur + 1 <= i
        for (int i=1; i<intervals.size(); i++) {

            // To find the first i, cur_end < i_start, indicates i_start can be next merged interval start
            if (intervals[cur].back() < intervals[i].front()) {

                // start is definite, choose the max end as final end from current and (i-1)_th interval
                merged.push_back(vector<int>{intervals[cur].front(), max(intervals[cur].back(), intervals[i-1].back())});

                // move current pointer farward to i
                cur = i;
            }
        }

        // cur <= last (size - 1)
        // determine last interval
        merged.push_back(vector<int>{intervals[cur].front(), max(intervals[cur].back(), intervals.back().back())});
        return merged;
    }
};
} // letscode56

#endif //TUTORIAL_INTERVALS_H