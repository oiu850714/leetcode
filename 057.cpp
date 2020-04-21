#include <vector>
#include <algorithm>

using Intervals = std::vector<std::vector<int>>;
using Interval = std::vector<int>;

class Solution {
public:
    Intervals insert(Intervals& OldIntervals, Interval &NewInterval) {
        OldIntervals.push_back(NewInterval);
        return merge_(OldIntervals);
    }

// copy from problem 56
private:
    Intervals merge_(Intervals& OldIntervals) {
        if (OldIntervals.empty()) {
            return {};
        }

        std::sort(OldIntervals.begin(), OldIntervals.end());

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

    bool canMerge_(Interval LeftInterval, Interval RightInterval) {
        return LeftInterval[1] >= RightInterval[0];
    }
};