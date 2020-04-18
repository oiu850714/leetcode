/**
 * Definition for singly-linked list.
 */
#include <exception>
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* L1, ListNode* L2) {
        ListNode* Ret = nullptr;
        ListNode** End = &Ret;
        while (L1 || L2) {
            if (L1 == nullptr) {
                *End = L2;
                return Ret;
            }
            if (L2 == nullptr) {
                *End = L1;
                return Ret;
            }

            if (L1->val <= L2->val) {
                *End = L1;
                L1 = L1->next;
            } else {
                *End = L2;
                L2 = L2->next;
            }
            (*End)->next = nullptr;
            End = &(*End)->next;
        }
        return Ret;
    }
};

int main() {
    /*
    // test 1
    ListNode N1{1}, N2{2}, N3{4};
    ListNode N4{1}, N5{3}, N6{4};
    N1.next = &N2;
    N2.next = &N3;

    N4.next = &N5;
    N5.next = &N6;
    */

    // test 2
    ListNode N1{1};
    Solution s;

    s.mergeTwoLists(&N1, nullptr);
}