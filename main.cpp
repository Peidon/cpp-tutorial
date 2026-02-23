#include <iostream>

#include "TutorialConfig.h.in"
#include <vector>
#include "letcode/parentheses.h"

using namespace std;

int main(const int argc, char **argv)
{
    const vector<string> parenths = letscode22::Solution::generateParenthesis(Number);
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
