// 參考
// https://stackoverflow.com/questions/11483060/stdnext-permutation-implementation-explanation
class Solution {
public:
    void nextPermutation(vector<int>& Nums) {
        if (Nums.empty() || Nums.size() == 1) {
            return;
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
                return;
            }

            if (Current == Nums.begin()) {
                // Largest Permutation
                std::reverse(Nums.begin(), Nums.end());
                return;
            }
        }
    }
};
