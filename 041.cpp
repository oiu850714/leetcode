#include <vector>
#include <algorithm>


class Solution {
public:
    int firstMissingPositive(std::vector<int>& A) {
        auto isNegative = [](auto E) { return E <= 0; };
        auto PositiveEnd = std::remove_if(A.begin(), A.end(), isNegative);
        A.erase(PositiveEnd, A.end());
        if (A.empty()) {
            return 1;
        }

        std::sort(A.begin(), A.end()); // n log n
        if (A[0] != 1) {
            return 1;
        }

        for (size_t Idx = 1; Idx < A.size(); Idx++) {
            if (A[Idx] - A[Idx - 1] > 1) {
                return A[Idx- 1] + 1;
            }
        }

        return A.back() + 1;
    }
};


int main() {
    std::vector<int> A1{-1, -3};
    std::vector<int> A2{7, 8, 9, 11, 12};
    Solution s;
    s.firstMissingPositive(A1);
    s.firstMissingPositive(A2);
}