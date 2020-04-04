/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

#include <string>
using std::string;

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* Lst1, ListNode* Lst2) {
        ListNode *Result = new ListNode(0); //dummy node
        ListNode *Prev = Result, *Curr = Result->next;

        int Carry = 0;
        while (Lst1 || Lst2) {
            Prev->next = Curr = new ListNode(0);
            int Value = Carry;
            if (Lst1) {
                Value += Lst1->val;
                Lst1 = Lst1->next;
            }
            if (Lst2) {
                Value += Lst2->val;
                Lst2 = Lst2->next;
            }

            Curr->val = Value % 10;
            Carry = Value / 10;

            Prev = Curr;
            Curr = Prev->next;
        }

        auto Temp = Result;
        Result = Result->next;
        delete Temp; // delete dummy node

        if (Carry) {
            Prev->next = new ListNode(1);
        }

        return Result;
    }
};
