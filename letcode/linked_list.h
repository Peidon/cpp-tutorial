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
    ListNode h; // head
    ListNode* t = &h; // tail
    
    for(const int item: a) {
        t->next = new ListNode(item);
        t = t->next;
    }
    return h.next;
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
    static ListNode* swapPairs(ListNode* head) {
        auto* dummy = new ListNode();
        dummy->next = head;
        ListNode* prev = dummy;

        while (prev != nullptr && prev->next != nullptr && prev->next->next != nullptr) {
            ListNode*left = prev->next;
            ListNode*right = prev->next->next;

            left->next = right->next;
            right->next = left;
            prev->next = right;

            prev = right->next;
        }

        return dummy->next;
    }


    static ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        int overflow = 0;
        ListNode* dummy = l1;
        ListNode* point = l1;

        while (l1 && l2 != nullptr)
        {
            const int v = l1->val + l2->val + overflow;
            point->val = v % 10;
            point = point->next;

            // reset next overflow
            overflow = v / 10;

            l1 = l1->next;
            l2 = l2->next;
        }

        while (l1 != nullptr)
        {
            const int v = l1->val + overflow;
            point->val = v % 10;
            point = point->next;

            // reset next overflow
            overflow = v / 10;
            l1 = l1->next;
        }

        point = l2;

        while (point != nullptr)
        {
            const int v = point->val + overflow;
            point -> val = v % 10;
            // reset next overflow
            overflow = v / 10;
            point = point->next;
        }
        return dummy;
    }
};