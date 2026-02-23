#include<co/unitest.h>
#include "linked_list.h"
#include <vector>

DEF_test(add_two_numbers) {
    const vector<int> a = {1, 2, 3};
    const vector<int> b = {4, 5, 6};

    ListNode* l1 = buildList(a);
    ListNode* l2 = buildList(b);
    const ListNode* l = Solution::addTwoNumbers(l1, l2);
    const vector<int> v = toVector(l);
    const vector<int> expected = {5, 7, 9};
    EXPECT_EQ(v.size(), 3);
    for (int i = 0; i < v.size(); i++) {
        EXPECT_EQ(v[i], expected[i]);
    }
}

DEF_test(swap_pairs) {
    const vector<int> a = {1, 2, 3, 4};
    ListNode* l1 = buildList(a);
    const ListNode* l2 = Solution::swapPairs(l1);
    const vector<int> v = toVector(l2);
    const vector<int> expected = {2, 1, 4, 3};
    EXPECT_EQ(v.size(), 4);
    for (int i = 0; i < v.size(); i++) {
        EXPECT_EQ(v[i], expected[i]);
    }
}