
#include <vector>

using namespace std;

namespace letcode63
{
    class Solution
    {
    public:
        int uniquePathsWithObstaclesOpti(vector<vector<int>> &obstacleGrid)
        {
            int n = obstacleGrid.size(), m = obstacleGrid.at(0).size();
            vector<int> f(m);

            f[0] = (obstacleGrid[0][0] == 0);
            for (int i = 0; i < n; ++i)
            {
                for (int j = 0; j < m; ++j)
                {
                    if (obstacleGrid[i][j] == 1)
                    {
                        f[j] = 0;
                        continue;
                    }
                    if (j - 1 >= 0 && obstacleGrid[i][j - 1] == 0)
                    {
                        f[j] += f[j - 1];
                    }
                }
            }

            return f.back();
        }

        int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
        {
            vector<vector<int>> dp(obstacleGrid.begin(), obstacleGrid.end());

            dp[0][0] = obstacleGrid[0][0] ^ 1;

            for (int i = 0; i < dp.size(); i++)
            {
                auto v = dp.at(i);

                if (v.size() > 0 && i > 0)
                {
                    dp[i][0] = dp[i - 1][0];
                    if (obstacleGrid[i][0] == 1)
                    {
                        dp[i][0] = 0;
                    }
                }

                for (int j = 1; j < v.size(); j++)
                {
                    if (i == 0)
                    {
                        dp[i][j] = dp[i][j - 1];
                    }
                    if (obstacleGrid[i][j] == 1)
                    {
                        dp[i][j] = 0;
                        continue;
                    }

                    if (i > 0)
                    {
                        dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
                    }
                }
            }
            return dp[dp.size() - 1].back();
        }
    };
}