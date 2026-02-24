#pragma once
#include <vector>

using namespace std;

namespace letcode63
{
class Solution
{
public:
    static int uniquePathsWithObstaclesOpti(const vector<vector<int>> &obstacleGrid)
    {
        const unsigned long n = obstacleGrid.size();
        const unsigned long m = obstacleGrid.at(0).size();
        vector<int> f(m);

        f[0] = obstacleGrid[0][0] == 0;
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                if (obstacleGrid[i][j] == 1)
                {
                    f[j] = 0;
                }
                else if (j > 0 && obstacleGrid[i][j - 1] == 0)
                {
                    f[j] += f[j - 1];
                }
            }
        }

        return f.back();
    }


    // letscode63 optimization
    static int uniquePath(const vector<vector<int>> &obstacleGrid) {
        const unsigned int dp_size = obstacleGrid.front().size();
        vector<int> dp(dp_size, 0);
        dp[0] = obstacleGrid[0][0] ^ 1;
        for (int i=1; i<dp_size; i++) {
            dp[i] = obstacleGrid[0][i] == 1 ? 0: dp[i-1];
        }

        for (int i=1; i < obstacleGrid.size(); i++) {
            for (int j=0; j<dp_size; j++) {
                dp[j] = obstacleGrid[i][j] == 1 ? 0 : j>0 ? dp[j] + dp[j-1] : dp[j];
            }
        }

        return dp.back();
    }

    // letscode63
    static int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
    {
        vector<vector<int>> dp(obstacleGrid.begin(), obstacleGrid.end());
        // if obstacleGrid[0][0] = 1, dp[0][0] = 0
        // else obstacleGrid[0][0] = 0, dp[0][0] = 1
        // because 1 represents obstacle, there are no path include square where an obstacle.
        dp[0][0] = obstacleGrid[0][0] ^ 1;

        // assume no obstacle
        // dp[0][x] = dp[0][x-1]
        // dp[y][0] = dp[y-1][0]
        for (int i = 0; i < dp.size(); i++)
        {
            vector<int> v = dp.at(i);

            if (!v.empty() && i > 0)
            {
                dp[i][0] = obstacleGrid[i][0] == 1 ? 0 : dp[i - 1][0];
            }

            for (int j = 1; j < v.size(); j++)
            {
                if (obstacleGrid[i][j] == 1)
                {
                    dp[i][j] = 0;
                }
                else
                {
                    dp[i][j] = i==0 ? dp[i][j - 1] : dp[i - 1][j] + dp[i][j - 1];
                }
            }
        }
        return dp.back().back();
    }
};
}