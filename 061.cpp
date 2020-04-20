#include <utility>
#include <tuple>

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
    // 我先傾向找出 list 長度，以及 list 末端位置
    // 然後再找到該切的位置重新串接 nodes
    // 而不是把尾巴拔 k 次
    // 「該切的位置」: 假設 list 長度為 len，要 rotate k 次，則可以在第 list - k % list 的位置切開 list
    // 例如長度為 5，要 rotate 2 次，則可以在 5 - 2 % 5 = 3 的位置切開 list
    ListNode* rotateRight(ListNode* Head, int Rotate) {
        if (Head == nullptr || Head->next == nullptr) {
            return Head;
        }

        int ListLength;
        ListNode** TailPointer;
        std::tie(ListLength, TailPointer) = getListLenAndAddrOfTail_(Head);

        // rotate 次數剛好是 list 長度的倍數，等於沒轉
        if (Rotate % ListLength == 0) {
            return Head;
        }

        auto CutPointer = &Head;
        auto Count = ListLength - (Rotate % ListLength);
        while (Count > 0) {
            CutPointer = &(*CutPointer)->next;
            Count--;
        }

        *TailPointer = Head;
        Head = *CutPointer;
        *CutPointer = nullptr;

        return Head;
    }

private:
    std::pair<int, ListNode**> getListLenAndAddrOfTail_(ListNode* Head) {
        int ListLength = 0;
        auto P = &Head;
        while (*P != nullptr) {
            ListLength++;
            P = &(*P)->next;
        }
        return {ListLength, P};
    }
};

int main() {
    ListNode N1{1}, N2{2}, N3{3}, N4{4}, N5{5};
    N1.next = &N2;
    N2.next = &N3;
    N3.next = &N4;
    N4.next = &N5;

    Solution s;
    s.rotateRight(&N1, 2);
}