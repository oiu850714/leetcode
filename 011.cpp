// https://leetcode.com/problems/container-with-most-water/discuss/6099/yet-another-way-to-see-what-happens-in-the-on-algorithm
// 根據解說內的二維陣列，每次挑掉一排，不管是一排 row 還是一排 column，陣列右上方的三角形都會越來越小，最後變成空的
// 三角形變成空的就代表所有邊界的組合都已經檢查過
// TODO: 三角形越來越小這個敘述應該可以寫成證明
// 目前想到的是每一次都會掃掉 N - i 個組合
// N 是邊界數量，i 是掃第 i 次
// 掃到 N - 1 - i 為 0 為止
// -> 總共會掃 1 + 2 + 3 + ... + (N -1) = (N - 1)(N)/2，剛好等於右上角三角形的數量
class Solution {
public:
    int maxArea(vector<int>& Boundaries) {
        int MaxArea = 0;
        auto Left = 0, Right = static_cast<int>(Boundaries.size() - 1);
        while (Left < Right) {
            auto ShortBoundary = std::min(Boundaries[Left], Boundaries[Right]);
            MaxArea = std::max(MaxArea, ShortBoundary * (Right - Left));
            ShortBoundary == Boundaries[Left] ? Left++ : Right--;
        }
        return MaxArea;
    }
};
