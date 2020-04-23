#include <vector>
#include <algorithm>


class Solution {
public:
    int firstMissingPositive(std::vector<int>& Nums) {
        // edge case: array 裡面沒有 1，直接回傳 1
        if (std::find(Nums.begin(), Nums.end(), 1) == Nums.end()) {
            return 1;
        }

        auto isNonPositiveOrGreaterThanN = [N = Nums.size()] (auto E) { return E <= 0 || E > N; };

        // 如果 element <= 0 或 > N 則改成 1
        std::replace_if(Nums.begin(), Nums.end(), isNonPositiveOrGreaterThanN, 1);
        // 現在 array elements 都介於 [1, N] 之間
        // 換句話說可以被拿來直接當作 Nums 的 index(要 -1 變成 zero-based)

        // 直接在 Nums 內標記目前找到的正數
        for (size_t Idx = 0; Idx < Nums.size(); Idx++) {
            auto FindPositive = std::abs(Nums[Idx]);
            // abs(Nums[Idx]) 是目前找到的一個正數
            Nums[FindPositive - 1] = -std::abs(Nums[FindPositive - 1]);
            // 直接將該正數當作 Nums 的 index (要 -1 變成 zero-based)
            // 並將該 index 內的值標記為負值
            // 代表該 index 是原本存在於 Nums 內的正數
        }

        // 最後再掃一次 array
        // 掃到第一個 index 內的 element 不是負值，代表該 index 之前沒有被標記過
        // 代表 Nums 原本不存在值相等於 index(+ 1) 的正數，直接回傳該 index(+ 1)
        auto isPositive = [] (auto E) { return E > 0; };
        return std::distance(Nums.begin(), std::find_if(Nums.begin(), Nums.end(), isPositive)) + 1;
        // edge case: 全部位置都被標記過，代表 Nums 原本的數字就是 1 ~ N
        // 回傳 N + 1
        // 上面這行在兩個情境下都適用
    }
};


int main() {
    std::vector<int> A1{-1, -3};
    std::vector<int> A2{7, 8, 9, 11, 12};
    Solution s;
    s.firstMissingPositive(A1);
    s.firstMissingPositive(A2);
}