//
// Created by Pedro's Jet on 25/2/2026.
//

#ifndef TUTORIAL_INTERVALS_H
#define TUTORIAL_INTERVALS_H
#include <vector>
#include <algorithm>

using namespace std;

namespace letscode {
class Solution56 {

    static bool compareIntervals(const vector<int> &a, const vector<int> &b) {
        return a.front() < b.front();
    }

public:
    static vector<vector<int>> merge(vector<vector<int>>& intervals) {
        std::sort(intervals.begin(), intervals.end(), compareIntervals);
        int offset = 0; // mark the merged position of original vector

        for (int i=1; i<intervals.size(); i++) {

            if (intervals[offset].back() >= intervals[i].front()) {

                // start is definite, update end
                intervals[offset].back() = max(intervals[i].back(), intervals[offset].back());

            } else {
                // move current pointer farward
                intervals[++offset] = intervals[i];
            }
        }

        return {intervals.begin(), intervals.begin() + offset + 1};
    }
};
} // letscode

#endif //TUTORIAL_INTERVALS_H