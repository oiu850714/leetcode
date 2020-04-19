#include <vector>
#include <algorithm>

using std::vector;
using std::lower_bound;
using std::upper_bound;

class Solution {
public:
    vector<int> searchRange(vector<int>& Nums, int Target) {
        auto LowerIt = std::lower_bound(Nums.begin(), Nums.end(), Target);
        auto UpperIt = std::upper_bound(Nums.begin(), Nums.end(), Target);
        if (LowerIt != Nums.end() && *LowerIt == Target) {
            return {static_cast<int>(LowerIt - Nums.begin()), static_cast<int>(UpperIt - 1 - Nums.begin())};
        } else {
            return {-1, -1};
        }

    }
};