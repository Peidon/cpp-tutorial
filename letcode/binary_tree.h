#pragma once
#include <vector>

/**
 * Definition for a binary tree node.
 */
namespace leetcode104
{

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    explicit TreeNode(const int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(const int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    static int maxDepth(const TreeNode *root)
    {
        if (root == nullptr)
        {
            return 0;
        }

        const int left = maxDepth(root->left);
        const int right = maxDepth(root->right);

        const int max_d = left > right ? left : right;

        return max_d + 1;
    }

    static int maxDepthUseQ(const TreeNode *root)
    {
        if (root == nullptr){return 0;}
        std::vector<TreeNode> q = {*root};

        int maxDepth = 0;
        while (q.size())
        {
            // record the quantity of current level.
            int siz = q.size();
            while (siz-- > 0)
            {
                const TreeNode *node = &q.back();
                q.pop_back();

                if (node->left){q.push_back(*node->left);}
                if (node->right){q.push_back(*node->right);}
            }
            maxDepth++;
        }
        return maxDepth;
    }
};

}
