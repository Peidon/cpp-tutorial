
#include <vector>

using namespace std;

namespace letcode63
{
    class Solution
    {
    public:
        int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
        {
            vector<vector<int>> dp(obstacleGrid.begin(), obstacleGrid.end());

            int v_size;

            for (int i = 0; i < dp.size(); i++)
            {
                auto v = dp.at(i);
                if (v.size() > 0)
                {
                    dp[i][0] = 1;
                    if (obstacleGrid[i][0] == 1)
                    {
                        dp[i][0] = 0;
                    }
                    v_size = v.size() - 1;
                }

                for (int j = 1; j < v.size(); j++)
                {
                    if (i == 0)
                    {
                        dp[i][j] = 1;
                    }
                    if (obstacleGrid[i][j] == 1)
                    {
                        dp[i][j] = 0;
                        continue;
                    }

                    if (i > 0)
                    {
                        dp[i][j] = dp[i-1][j] + dp[i][j-1];
                    }
                }
            }
            return dp[dp.size() - 1][v_size];
        }
    };
}