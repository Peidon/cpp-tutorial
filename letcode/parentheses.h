#pragma once
#include <vector>
#include <string>
#include <set>

using namespace std;

namespace letscode22
{
/*
 * Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.
 */
class Solution
{
    /**
     *
     * @param i pairs of parentheses
     * @return combinations
     */
    static vector<string> f(const int i)
    {

        if (i == 0){return vector{string()};}
        if (i == 1){return vector{string("()")};}
        vector<string> combinations;

        for (int p = 0; p < i; p ++)
        {
            // for each loop, we divide the problem to two parts
            // f(i) = f(p) * f(q) + µ
            // p 0..i-1
            // q i-1..0
            // µ "()"
            const int q = i-1-p;
            vector<string> l1 = f(p);
            vector<string> l2 = f(q);

            for (const string& item1 : l1)
            {
                // for each combination from l1,
                // combination from l2 follows it.
                for (const string& item2 : l2)
                {
                    // You can think of this, how to add a "()" into a combination from f(i-1).
                    // because it should be well-formed parentheses,
                    // there should be one "(" on the most left, then ")" move forwad util most right.
                    std::string item = "(" + item1 + ")";
                    item = item.append(item2);
                    combinations.push_back(item);
                }
            }
        }
        return combinations;
    }

public:
    /**
     *
     * @param n pairs of parentheses
     * @return combinations
     */
    static vector<string> generateParenthesis(const int n)
    {
        return f(n);
    }
};

}