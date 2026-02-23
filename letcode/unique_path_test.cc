#include<co/unitest.h>
#include "unique_path.h"
#include "co/log.h"

DEF_test(unique_path)
{

    DEF_case(path_0)
    {
        vector<vector<int>> input = {{1,0}};
        int a = letcode63::Solution::uniquePathsWithObstacles(input);
        EXPECT_EQ(a, 0);
    }

    DEF_case(path_1)
    {
        vector<vector<int>> input = {{0,1},{0,0}};
        int a = letcode63::Solution::uniquePathsWithObstacles(input);
        DLOG << "path_1" << a;
        EXPECT_EQ(a, 1);
    }
    DEF_case(path_2)
    {
        vector<vector<int>> input = {{0,0},{0,0}};
        int a = letcode63::Solution::uniquePathsWithObstacles(input);
        DLOG << "path_2" << a;
        EXPECT_EQ(a, 2);
    }
    DEF_case(path_3)
    {
        vector<vector<int>> input = {{0,0,0},{0,1,0},{0,0,0}};
        int a = letcode63::Solution::uniquePathsWithObstacles(input);
        EXPECT_EQ(a, 2);
    }
}