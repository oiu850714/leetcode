/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode* swapPairs(ListNode* Head) {
        auto PHead = &Head;
        while (swapNextTwoNodes(PHead)) {
            PHead = &((*PHead)->next->next);
        }

        return Head;
    }

private:
    bool swapNextTwoNodes(ListNode** P) {
        // 如果沒有剩下 Node 或者只剩一個 Node，則不用 swap
        if (*P == nullptr || (*P)->next == nullptr) {
            return false;
        }

        auto N1 = (*P), N2 = N1->next;
        (*P) = N2;
        N1->next = N2->next;
        N2->next = N1;
        return true;
    }
};

int main() {
    ListNode N1{1}, N2{2}, N3{3}, N4{4};
    N1.next = &N2;
    N2.next = &N3;
    N3.next = &N4;

    Solution s;
    s.swapPairs(&N1);
}