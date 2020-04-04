// 參考 31 題
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        std::sort(begin(nums), end(nums));

        auto ret = vector<vector<int>>{};

        do {
            ret.push_back(nums);
        } while (nextPermutation(nums));

        return ret;
    }

    bool nextPermutation(vector<int>& Nums) {
        if (Nums.empty() || Nums.size() == 1) {
            return false;
        }

        auto Current = Nums.end() - 1;

        while (true) {
            auto After = Current--;

            if (*Current < *After) {
                auto JustLargerThanCurrent = Nums.end();
                while (*Current >= *--JustLargerThanCurrent)
                    ;
                std::iter_swap(Current, JustLargerThanCurrent);
                std::reverse(After, Nums.end());
                return true;
            }

            if (Current == Nums.begin()) {
                // Largest Permutation
                std::reverse(Nums.begin(), Nums.end());
                return false;
            }
        }
    }
};
