#include <exception>
/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* Head, int N) {
        auto SelectedP = &Head, GoToTheEnd = &Head;
        int Interval = 0;
        while (Interval < N && *GoToTheEnd) {
            GoToTheEnd = &(*GoToTheEnd)->next;
            Interval++;
        }
        if (Interval != N) {
            // GoToTheEnd 還沒跟開頭隔 N 個 node 就到 list 尾端了
            throw std::exception();
        }

        while (*GoToTheEnd) {
            SelectedP = &(*SelectedP)->next;
            GoToTheEnd = &(*GoToTheEnd)->next;
        }
        auto RemovedNode = *SelectedP;
        *SelectedP = (*SelectedP)->next;
        // delete(RemovedNode); // Nodes 用 new 才要 delete
        return Head;
    }
};

int main() {
    ListNode N1{1}, N2{2}, N3{3}, N4{4}, N5{5};
    N1.next = &N2;
    N2.next = &N3;
    N3.next = &N4;
    N4.next = &N5;

    Solution s;
    s.removeNthFromEnd(&N1, 2);
}