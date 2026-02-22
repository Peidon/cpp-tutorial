/**
 * Given six denominations of banknotes: 1, 5, 10, 20, 50, and 100, 
 * and assuming there are sufficient quantities of each denomination, 
 * write a program to calculate the number of different combinations 
 * that can form N (N is a non-negative integer from 0 to 10000).
 */
#pragma once
class Comb
{
    const int coins_[6];

    /**
     *
     * @param i index of coins_, iTH cion is the new coin added to form the j
     * @param j the target value that banknotes (coins) can form
     * @return the number of different combinations of these banknotes
     */
    int f(const int i, const int j)
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
    Comb() : coins_ {1, 5, 10, 20, 50, 100} {}

    ~Comb() = default;

    /**
     *
     * @param N the target value that banknotes can form
     * @return the number of different combinations of these banknotes
     */
    int solution_N(const int N) const {
        int F[N+1];
        for (int i =1; i <= N; i++)
        {
            F[i] = 0;
        }

        // F[0] = 1, this is very import
        // It's applicable to any scenarios
        F[0] = 1;

        // Considor this case, there is only one denomination, then for each x >= denomination, F[x] = 1.
        // If x < denomination, F[x] = 0

        // Then we can continue the derivation.
        // There is two denomination, and the new denomination > first one.
        // We can recalculate the F
        // F[j] = F[j] + F[j - denomination], that means we can divide the problem into two parts.
        // Part 1: got the j combinations didn't use the new denomination.
        // Part 2: got the (j - denomination) combinations used the new denomination.
        // Plus the results of two parts, we got the j combinations used the new denomination.

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