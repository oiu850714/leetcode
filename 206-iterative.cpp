/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* Head) {
        if (Head == nullptr) {
            return Head;
        }

        auto P = Head;
        while (P->next != nullptr) {
            auto MovedNode = P->next;
            P->next = MovedNode->next;
            MovedNode->next = Head;
            Head = MovedNode;
        }

        return Head;
    }
};