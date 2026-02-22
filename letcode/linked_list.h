#pragma once
#include <vector>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    explicit ListNode(const int x) : val(x), next(nullptr) {}
    ListNode(const int x, ListNode *next) : val(x), next(next) {}

    ~ListNode() = default;
};

inline ListNode *buildList(const vector<int>& a)
{
    auto* h = new ListNode(); // head
    const shared_ptr<ListNode> p(h);
    ListNode* t = p.get(); // tail
    
    for(const int item: a) {
        auto* node = new ListNode(item);
        t->next = node;
        t = t->next;
    }

    return h->next;
}

/**
 * C++17 introduced guaranteed copy elision.
 * When returning a local object by value, the object is constructed directly in the caller’s storage.
 * No copy or move occurs, and this is guaranteed by the standard.
 * @param l
 * @return
 */
inline vector<int> toVector(const ListNode* l) {
    vector<int> v;

    while (l) {
        v.push_back(l->val);
        l = l->next;
    }

    return v;
}

class Solution
{
public:
    static ListNode *addTwoNumbers(const ListNode *l1, const ListNode *l2)
    {
        int res_val = l1->val + l2->val;
        int overflow = res_val / 10;
        
        auto *res = new ListNode(res_val % 10);
        const shared_ptr<ListNode> t(res);

        // temporary point
        ListNode* tp = t.get();

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