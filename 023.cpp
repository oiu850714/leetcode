#include <exception>
#include <vector>

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
    ListNode* mergeKLists(std::vector<ListNode*>& Lists) {
        // edge case
        if (Lists.empty()) {
            return nullptr;
        }

        do {
            Lists = pairMerge_(Lists);
        } while (Lists.size() > 1);

        return Lists[0];
    }

private:
    std::vector<ListNode *> pairMerge_(const std::vector<ListNode *> &Lists) {
        std::vector<ListNode* > PairMergedLists;
        for (size_t i = 0; i < Lists.size();) {
            if (i == Lists.size() - 1) {
                PairMergedLists.push_back(Lists[i]);
                break;
            }

            PairMergedLists.push_back(mergeTwoLists_(Lists[i], Lists[i + 1]));
            i += 2;
        }
        return PairMergedLists;
    }

    // copy from problem 21
    ListNode* mergeTwoLists_(ListNode* L1, ListNode* L2) {
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
    ListNode N1{1}, N2{2}, N3{4}, N4{1}, N5{3}, N6{4};

    std::vector<ListNode*> KLists{&N1, &N2, &N3, &N4, &N5, &N6};
    Solution s;
    auto l = s.mergeKLists(KLists);
}