#include <iostream>

#include "TutorialConfig.h.in"
#include <vector>
#include "letcode/linked_list.h"

#include "letcode/stock.h"
#include "letcode/parenth_gen.h"

using namespace std;

int main(const int argc, char **argv)
{
    vector prices = {7,6,4,3,1};
    cout << letcode::Solution::maxProfit(prices) << endl;

    const vector<string> parenths = letcode22::Solution::generateParenthesis(3);
    for (const string& item : parenths)
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
