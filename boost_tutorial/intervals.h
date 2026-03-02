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
        int start = 0;
        for (int i=1; i<intervals.size(); i++) {
            if (intervals[start].back() < intervals[i].front()) {
                merged.push_back(vector<int>{intervals[start].front(), max(intervals[start].back(), intervals[i-1].back())});
                start = i;
            }
        }
        merged.push_back(vector<int>{intervals[start].front(), max(intervals[start].back(), intervals.back().back())});
        return merged;
    }
};
} // letscode56

#endif //TUTORIAL_INTERVALS_H