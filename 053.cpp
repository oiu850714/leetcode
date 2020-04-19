#include <vector>
#include <algorithm>

class Solution {
public:
    int maxSubArray(std::vector<int>& Nums) {
        if (Nums.empty()) {
            throw std::exception();
        }
        // 存 end 停在 index N 的 subarray 的 max sum
        std::vector<int> MaxSumEndAtN(Nums.size());

        // 初始化第一個 element
        MaxSumEndAtN[0] = Nums[0];

        for (size_t Idx = 1; Idx < Nums.size(); Idx++) {
            // https://i.imgur.com/ybN8Zuc.jpg
            // 對於 end 停在 Idx 的所有 subarray
            // 最大的 subarray 可以從:
            //      所有停在 Idx-1 的 subarray + Nums[Idx]
            //      或者頭尾都在 Idx 的 sub (one element only) array
            //      最大的那個來決定
            MaxSumEndAtN[Idx] = std::max(MaxSumEndAtN[Idx - 1] + Nums[Idx], Nums[Idx]);
        }
        return *std::max_element(MaxSumEndAtN.begin(), MaxSumEndAtN.end());
    }
};