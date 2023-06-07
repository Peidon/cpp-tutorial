namespace letcode24{

/**
 * Definition for singly-linked list.
 */
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *swapPairs(ListNode *head)
    {
        ListNode* dummyHead;
        dummyHead->next = head;
        auto temp = dummyHead;
        while (temp->next!= nullptr && temp->next->next != nullptr)
        {
            auto node1 = temp->next;
            auto node2 = temp->next->next;
            temp->next = node2;
            node1->next = node2->next;
            node2->next = node1;

            temp = node1;
        }

        return dummyHead->next;
    }
};
}