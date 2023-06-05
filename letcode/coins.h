
#include <vector>
// 六种面额 1、5、10、20、50、100 元的纸币，假设每种币值的数量都足够多，编写程序求组成N元（N为0~10000的非负整数）的不同组合的个数
class Comb
{
private:
    const int coins_[6];

    int f(int i, int j)
    {
        if (i == 0 || j == 0)
        {
            return 1;
        }
        int sum = 0;
        int k = 1;
        int temp = j;

        while (temp>0)
        {
            sum += f(i-1, temp);
            temp = j - k *coins_[i];
            k++;
        }

        return sum;
    }

public:
    Comb() : coins_ {1, 5, 10, 20, 50, 100} {};

    ~Comb() {};

    int solution_N(int N)
    {
        long F[N+1];
        for (int i =1; i <= N; i++)
        {
            F[i] = 0;
        }
        F[0] = 1;

        for(const int coin_val : coins_)
        {
            for(int j = coin_val; j <= N; j ++)
            {
                F[j] = F[j] + F[j-coin_val];
            }
        }
        return F[N];
    }
};