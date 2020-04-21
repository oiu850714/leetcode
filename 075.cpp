#include <vector>
#include <algorithm>

class Solution {
public:
    void sortColors(std::vector<int>& Nums) {
        if (Nums.size() < 1) {
            return;
        }

        auto FirstArrangedTwo = moveTargetToEnd_(Nums.begin(), Nums.end(), 2);
        moveTargetToEnd_(Nums.begin(), FirstArrangedTwo, 1);
    }

private:
    std::vector<int>::iterator moveTargetToEnd_(std::vector<int>::iterator Begin, std::vector<int>::iterator End, int Target) {
        // [Begin, End)
        auto FirstArrangedTarget = End;
        auto FindTarget = Begin;

        while ((FindTarget = std::find(FindTarget, FirstArrangedTarget, Target)) != FirstArrangedTarget) {
            if (*--FirstArrangedTarget != Target) {
                std::iter_swap(FindTarget, FirstArrangedTarget);
            }
        }

        return FirstArrangedTarget;
    }
};

int main() {
    std::vector<int> Nums1{2,0,2,1,1,0,2,1,1,1,2,1,1,0,1,0,2,2,0,1,1,1,0,2,2,2,2,0,0,2,2,2,0,0,0};
    std::vector<int> Nums2{2, 0, 1};
    Solution s;
    s.sortColors(Nums1);
    s.sortColors(Nums2);
}