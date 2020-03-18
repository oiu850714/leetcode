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
