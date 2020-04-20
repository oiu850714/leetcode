#include <vector>
#include <tuple>

class Solution {
public:
    std::vector<int> spiralOrder(std::vector<std::vector<int>>& Matrix) {
        if (Matrix.empty()) {
            return {};
        }
        std::vector<int> Result;
        auto N = Matrix.size();
        for (size_t I = 0; I < (N + 1) / 2; I++) {
            std::pair<int, int> LeftUp = {I, I};
            std::pair<int, int> RightUp = {I, N - 1 - I};
            std::pair<int, int> RightDown = {N - 1 - I, N - 1 - I};
            std::pair<int, int> LeftDown = {N - 1 - I, I};

            size_t IdxRow, IdxCol;
            bool PrintFlag = false;
            for (std::tie(IdxRow, IdxCol) = LeftUp; std::pair<int, int>{IdxRow, IdxCol} < RightUp; IdxCol++) {
                Result.push_back(Matrix[IdxRow][IdxCol]);
                PrintFlag = true;
            }

            for (std::tie(IdxRow, IdxCol) = RightUp; std::pair<int, int>{IdxRow, IdxCol} < RightDown; IdxRow++) {
                Result.push_back(Matrix[IdxRow][IdxCol]);
                PrintFlag = true;
            }

            for (std::tie(IdxRow, IdxCol) = RightDown; std::pair<int, int>{IdxRow, IdxCol} > LeftDown; IdxCol--) {
                Result.push_back(Matrix[IdxRow][IdxCol]);
                PrintFlag = true;
            }

            for (std::tie(IdxRow, IdxCol) = LeftDown; std::pair<int, int>{IdxRow, IdxCol} > LeftUp; IdxRow--) {
                Result.push_back(Matrix[IdxRow][IdxCol]);
                PrintFlag = true;
            }

            if (!PrintFlag) { // edge case: 如果當前要印的 Matrix 為 1*1
                Result.push_back(Matrix[IdxRow][IdxCol]);
            }
        }
        return Result;
    }
};

int main() {
    std::vector<std::vector<int>> Matrix{
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    Solution s;
    auto v = s.spiralOrder(Matrix);
}