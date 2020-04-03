#include <vector>
#include <algorithm>
#include <iostream>


class Solution {
public:
    std::vector<std::vector<int>> threeSum(std::vector<int>& Nums) {
        // corner case 1: input length < 3
        if (Nums.size() < 3) {
            return {};
        }

        std::vector<std::vector<int>> FindTriples;

        std::sort(Nums.begin(), Nums.end());
        for (auto i = 0; i < Nums.size() - 2; i++) {
            int FirstNum = Nums[i];

            // Nums[i] 右邊的 elements 都 > 0，不可能找到三個 elements 相加 = 0
            if (FirstNum > 0) {
                break;
            }

            // 如果 Nums[i] 跟他左邊的 element 值相等，則接下來找到的 triples 一定都重複
            if (i > 0 && Nums[i - 1] == Nums[i]) {
                continue;
            }

            size_t left = i + 1;
            size_t right = Nums.size() - 1;

            while (left < right) {
                if (Nums[left] + Nums[right] == -(FirstNum)) {
                    FindTriples.push_back({FirstNum, Nums[left++], Nums[right--]});
                    // 如果 left 右邊的數跟 left 一樣則略過，否則會找到一樣的 triple
                    while (left < right && Nums[left - 1] == Nums[left]) {
                        ++left;
                    }
                    // right 判斷跟 left 對稱
                    while (left < right && Nums[right + 1] == Nums[right]) {
                        --right;
                    }
                } else if (Nums[left] + Nums[right] > -(FirstNum)){
                    // 三個數相加 > 0，Nums[right] 太大了，往左找
                    --right;
                } else {
                    // 三個數相加 < 0，Nums[left] 太小了，往右找
                    ++left;
                }
            }
        }
        return FindTriples;
    }
};