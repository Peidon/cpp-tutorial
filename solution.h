#include <vector>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *buildList(vector<int> a)
{
    ListNode *l1 = new ListNode();
    ListNode *p = l1;

    for (const int num: a)
    {
        if (!p)
        {
            p = new ListNode();
        }

        p->val = num;
        p = p->next;
    }
    return l1;
}

class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        int res_val = l1->val + l2->val;
        int overflow = res_val % 10;
        
        ListNode *res = new ListNode(res_val / 10);

        // temparory point
        ListNode *tp = res->next;

        while (l1->next && l2->next)
        {
            l1 = l1->next;
            l2 = l2->next;

            // build next node
            res_val = l1->val + l2->val + overflow;
            ListNode *next_node = new ListNode(res_val / 10);

            tp = next_node;

            // reset next overflow
            overflow = res_val % 10;

            // point to next node
            tp = tp->next;
        }

        while (l1->next)
        {
            l1 = l1->next;
            res_val = l1->val + overflow;

            ListNode *next_node = new ListNode(res_val / 10);

            tp = next_node;

            // reset next overflow
            overflow = res_val % 10;

            // point to next node
            tp = tp->next;
        }

        while (l2->next)
        {
            l2 = l2->next;
            res_val = l2->val + overflow;

            ListNode *next_node = new ListNode(res_val / 10);

            tp = next_node;

            // reset next overflow
            overflow = res_val % 10;

            // point to next node
            tp = tp->next;
        }

        return res;
    }
};