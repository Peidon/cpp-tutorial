#include <vector>
#include <string>
#include <set>

using namespace std;

namespace letcode22
{

    class Solution
    {
    private:
        vector<string> f(int i)
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
                int q = i-1-p;

                auto l1 = f(p);
                auto l2 = f(q);

                for (const string item1 : l1)
                {
                    for (const string item2 : l2)
                    {
                        ans.push_back("(" + item1 + ")" + item2);
                    }
                }

            }

            return ans;
        }

    public:
        vector<string> generateParenthesis(int n)
        {
            return f(n);
        }
    };

}