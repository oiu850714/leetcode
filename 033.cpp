#include <vector>
#include <iostream>
#include <algorithm>

// TODO: need to fundamentally understand all boundary cases in binary search...
// https://medium.com/@CalvinChankf/how-to-deal-with-lower-upper-bound-binary-search-b9ce744673df
class Solution {
public:
    int search(std::vector<int>& SortedRotatedVector, int Target) {
        // edge case
        if (SortedRotatedVector.empty()) {
            return -1;
        }

        if (SortedRotatedVector.size() == 1) {
            return SortedRotatedVector[0] == Target ? 0 : -1;
        }

        // 找到最大值的位置
        auto L = findPivot_(SortedRotatedVector);
        // 然後再對最大值(包含)兩邊兩邊分別做 binary search

        // 因為搜尋要包含最大的 element，也就是 L 指向的 element
        // 所以 range end 是 L + 1
        auto It = std::lower_bound(SortedRotatedVector.cbegin(), L + 1, Target);
        if (It != L + 1 && *It == Target) {
            return It - SortedRotatedVector.cbegin();
        }

        It = std::lower_bound(L + 1, SortedRotatedVector.cend(), Target);
        if (It != SortedRotatedVector.cend() && *It == Target) {
            return It - SortedRotatedVector.cbegin();
        }

        return -1;
    }

private:
    std::vector<int>::const_iterator findPivot_(const std::vector<int> &SortedRotatedVector) {
        // 先找到最大值，最大值的位置等於斷點
        // 個人覺得找最大值有點不直覺，附上自己的證明
        // https://i.imgur.com/DXYEq6i.jpg
        auto L = SortedRotatedVector.begin(), R = SortedRotatedVector.end() - 1;
        while (L != R - 1) { // 還存在 element(s)
            auto M = L + (R - L) / 2;
            // 這裡因為是要找最大值，不能把 M 指向的 element 剔除
            if (*L > *M) {
                R = M;
            } else {
                L = M;
            }
        }
        if (*L < *R) {
            L = R;
        }
        // L now becomes Index of largest element
        return L;
    }
};

int main() {
    std::vector<int> vec{4,5,6,7,8,1,2,3};
    Solution s;
    std::cout << s.search(vec, 8) << std::endl;
}