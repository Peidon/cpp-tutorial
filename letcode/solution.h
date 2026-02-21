#pragma once
#include <vector>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}

    ~ListNode() = default;
};

inline ListNode *buildList(const vector<int>& a)
{
    auto* h = new ListNode(); // head
    ListNode* t = h; // tail
    
    for(const int item: a) {
        auto* node = new ListNode(item);
        t->next = node;
        t = t->next;
    }
    
    return h->next;
}

class Solution
{
public:
    static ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        int res_val = l1->val + l2->val;
        int overflow = res_val / 10;
        
        auto *res = new ListNode(res_val % 10);

        // temporary point
        ListNode *tp = res;

        while (l1->next && l2->next)
        {
            l1 = l1->next;
            l2 = l2->next;

            // build next node
            res_val = l1->val + l2->val + overflow;
            auto *next_node = new ListNode(res_val % 10);

            // reset next overflow
            overflow = res_val / 10;

            // point to next node
            tp->next = next_node;
            tp = tp->next;
        }

        while (l1->next)
        {
            l1 = l1->next;
            res_val = l1->val + overflow;

            auto *next_node = new ListNode(res_val % 10);

            // reset next overflow
            overflow = res_val / 10;

            // point to next node
            tp->next = next_node;
            tp = tp->next;
        }

        while (l2->next)
        {
            l2 = l2->next;
            res_val = l2->val + overflow;

            auto *next_node = new ListNode(res_val % 10);

            // reset next overflow
            overflow = res_val / 10;

            // point to next node
            tp->next = next_node;
            tp = tp->next;
        }

        return res;
    }
};