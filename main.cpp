#include <iostream>
#include "TutorialConfig.h.in"
#include <vector>
#include "solution.h"

#include "letcode/stock.h"

using namespace std;

int main(int argc, char **argv)
{
    vector<int> a = {1, 2, 3};
    vector<int> b = {4, 5, 6};

    ListNode* l1 = buildList(a);
    ListNode* l2 = buildList(b);

    Solution* so = new Solution();
    ListNode* l = so->addTwoNumbers(l1, l2);

    while (l)
    {
        cout << l->val << " ";
        l = l->next;
    }

    cout << endl << "LeetCode Solution" << endl;

    letcode::Solution* sl = new letcode::Solution();
    vector<int> prices = {7,6,4,3,1};
    cout << sl -> maxProfit(prices) << endl;

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
