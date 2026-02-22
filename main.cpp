#include <iostream>

#include "TutorialConfig.h.in"
#include <vector>
#include "letcode/solution.h"

#include "letcode/stock.h"
#include "letcode/parenth_gen.h"

using namespace std;

int main(const int argc, char **argv)
{
    const vector<int> a = {1, 2, 3};
    const vector<int> b = {4, 5, 6};

    const ListNode* l1 = buildList(a);
    const ListNode* l2 = buildList(b);

    const ListNode* l = Solution::addTwoNumbers(l1, l2);

    while (l)
    {
        cout << l->val << " ";
        l = l->next;
    }

    cout << endl << "LeetCode Solution" << endl;

    letcode::Solution* sl = new letcode::Solution();
    vector<int> prices = {7,6,4,3,1};
    cout << sl -> maxProfit(prices) << endl;

    letcode22::Solution* sl22 = new letcode22::Solution();
    vector<string> parenths = sl22->generateParenthesis(3);
    for (const string item : parenths)
    {
        cout << item << endl;
    }

    if (argc < 2)
    {
        // report version
        std::cout << argv[0] << " Version " << Tutorial_VERSION_MAJOR << "." << Tutorial_VERSION_MINOR << std::endl;
        std::cout << "Usage: " << argv[0] << " number" << std::endl;
        return 1;
    }
    std::cout << "Hello, world!\n";
    return 0;
}
