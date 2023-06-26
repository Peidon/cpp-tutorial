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
        TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
    };

    class Solution
    {
    public:
        int maxDepth(TreeNode *root)
        {
            if (root == nullptr)
            {
                return 0;
            }

            auto left = maxDepth(root->left);
            auto right = maxDepth(root->right);

            int max_d = left > right ? left : right;

            return max_d + 1;
        }

        int maxDepthUseQ(TreeNode *root)
        {
            if (root == nullptr)
            {
                return 0;
            }

            std::vector<TreeNode *> q = {root};

            int ans = 0;
            while (q.size())
            {

                int siz = q.size(); // 记录当前层的数量
                while (siz > 0)
                {
                    TreeNode *node = q.back();
                    q.pop_back();
                    siz--;

                    if (node->left)
                    {
                        q.push_back(node->left);
                    }

                    if (node->right)
                    {
                        q.push_back(node->right);
                    }
                    
                }

                ans++;
            }
        }
    };

}
