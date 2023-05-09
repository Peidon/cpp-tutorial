#include <vector>

using namespace std;

namespace letcode
{
    class Solution
    {
    public:
        int maxProfit(vector<int> &prices)
        {
            int min_price = 1e4;
            int max_price = 0;
            int profit = 0;

            for (const int v : prices)
            {

                if (v < min_price)
                {
                    min_price = v;
                    max_price = v;
                }

                if (v > max_price)
                {
                    max_price = v;

                    profit = profit + max_price - min_price;
    
                    min_price = v;
                }
            }

            return profit;
        }
    };

}