#include <vector>
#include <algorithm>

using Intervals = std::vector<std::vector<int>>;
using Interval = std::vector<int>;

class Solution {
public:
    Intervals merge(Intervals& OldIntervals) { // murmur: 為何不傳個 vector<pair<int, int>> 呢..
        if (OldIntervals.empty()) {
            return {};
        }

        std::sort(OldIntervals.begin(), OldIntervals.end());
        // sort 之後，interval 左邊比較小的會排得比 interval 左邊比較大的還要前面
        // 若 interval 左邊都相同，則 interval 右邊較小的會排得 interval 右邊比較大的還要前面

        Intervals MergedIntervals;
        for (auto &OldInterval : OldIntervals) {
            if (MergedIntervals.empty()) {
                MergedIntervals.push_back(OldInterval);
                continue;
            }

            auto &Back = MergedIntervals.back();
            if (canMerge_(Back, OldInterval)) {
                Back = {
                    Back[0],
                    std::max(Back[1], OldInterval[1])
                };
            } else {
                MergedIntervals.push_back(OldInterval);
            }
        }
        return MergedIntervals;
    }
private:
    // 假設第一個區間在第二個區間左邊
    bool canMerge_(Interval LeftInterval, Interval RightInterval) {
        return LeftInterval[1] >= RightInterval[0];
    }
};