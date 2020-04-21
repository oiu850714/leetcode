#include <vector>

class Solution {
public:
    bool searchMatrix(std::vector<std::vector<int>>& Matrix, int Target) {
        if (Matrix.empty() || Matrix[0].empty()) {
            return false;
        }

        int M = Matrix.size();
        int N = Matrix[0].size();
        int OneDimLength = M * N;

        int Left = 0, Right = OneDimLength - 1;
        while (Left <= Right) {
            auto Mid = (Left + Right) / 2;
            auto Select = Matrix[Mid/ N][Mid % N];
            if (Select == Target) {
                return true;
            } else if (Select < Target) {
                Left = Mid + 1;
            } else {
                Right = Mid - 1;
            }
        }
        return false;
    }
};

int main() {
    std::vector<std::vector<int>> Matrix1{
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };

    std::vector<std::vector<int>> Matrix2{
        {1, 3, 5, 7},
        {10, 11, 16, 20},
        {23, 30, 34, 50}
    };
    Solution s;
    s.searchMatrix(Matrix1, 3);
    s.searchMatrix(Matrix2, 13);
}