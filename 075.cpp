#include <vector>
#include <algorithm>

class Solution {
public:
    void sortColors(std::vector<int>& Nums) {
        if (Nums.size() < 1) {
            return;
        }

        auto LastTwo = moveTargetToEnd_(Nums.begin(), Nums.end(), 2);
        moveTargetToEnd_(Nums.begin(), LastTwo, 1);
        Nums.back();
    }

private:
    std::vector<int>::iterator moveTargetToEnd_(std::vector<int>::iterator Begin, std::vector<int>::iterator End, int Target) {
        // [Begin, End)
        auto FirstArrangedTarget = End;
        auto FindTarget = std::find(Begin, End, Target);

        while (FindTarget < --FirstArrangedTarget) {
            if (*FirstArrangedTarget != Target) {
                std::iter_swap(FindTarget, FirstArrangedTarget);
            }
            FindTarget = std::find(FindTarget, FirstArrangedTarget, Target);
            // 注意: 在最後一次 loop，FindTarget 會指向完全被搬到末端的 Targets 的第一個 Target
            // 而當 loop 結束時，FirstArrangedTarget 會指向 FindTarget 前一個位置
        }

        return FindTarget;
    }
};

int main() {
    std::vector<int> Nums1{2,0,2,1,1,0,2,1,1,1,2,1,1,0,1,0,2,2,0,1,1,1,0,2,2,2,2,0,0,2,2,2,0,0,0};
    std::vector<int> Nums2{2, 0, 1};
    Solution s;
    s.sortColors(Nums1);
    s.sortColors(Nums2);
}