class Solution {
public:
    int maxArea(vector<int>& Boundaries) {
        int MaxArea = 0;
        for (size_t Left = 0; Left < Boundaries.size() - 1; Left++) {
            for (size_t Right = Left + 1; Right < Boundaries.size(); Right++) {
                auto ShortBoundary = std::min(Boundaries[Left], Boundaries[Right]);
                MaxArea = std::max(MaxArea, ShortBoundary * static_cast<int>(Right - Left));
            }
        }
        return MaxArea;
    }
};
