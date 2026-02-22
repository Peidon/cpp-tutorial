#pragma once
#include <vector>
#include <string>
#include <set>

using namespace std;

namespace letcode22
{

class Solution
{
    static vector<string> f(const int i)
    {

        if (i == 0)
        {
            return {""};
        }

        if (i == 1)
        {
            return {"()"};
        }

        vector<string> ans;

        for (int p = 0; p < i; p ++)
        {
            const int q = i-1-p;

            vector<string> l1 = f(p);
            vector<string> l2 = f(q);

            for (const string& item1 : l1)
            {
                for (const string& item2 : l2)
                {
                    std::string item = "(" + item1 + ")";
                    item = item.append(item2);
                    ans.push_back(item);
                }
            }

        }

        return ans;
    }

public:
    static vector<string> generateParenthesis(const int n)
    {
        return f(n);
    }
};

}