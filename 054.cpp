#include <vector>
#include <tuple>

class Solution {
public:
    std::vector<int> spiralOrder(std::vector<std::vector<int>>& Matrix) {
        if (Matrix.empty()) {
            return {};
        }
        std::vector<int> Result;
        auto M = Matrix.size();
        auto N = Matrix[0].size();
        for (size_t I = 0; I < (N + 1) / 2; I++) {
            std::pair<size_t, size_t> LeftUp = {I, I};
            std::pair<size_t, size_t> RightUp = {I, N - 1 - I};
            std::pair<size_t, size_t> RightDown = {M - 1 - I, N - 1 - I};
            std::pair<size_t, size_t> LeftDown = {M - 1 - I, I};

            size_t IdxRow, IdxCol;
            bool PrintFlag = false;
            for (std::tie(IdxRow, IdxCol) = LeftUp; std::pair<size_t, size_t>{IdxRow, IdxCol} < RightUp; IdxCol++) {
                Result.push_back(Matrix[IdxRow][IdxCol]);
                PrintFlag = true;
            }


            for (std::tie(IdxRow, IdxCol) = LeftUp; std::pair<size_t, size_t>{IdxRow, IdxCol} < RightUp; IdxCol++) {
                Result.push_back(Matrix[IdxRow][IdxCol]);
                PrintFlag = true;
            }

            for (std::tie(IdxRow, IdxCol) = RightUp; std::pair<size_t, size_t>{IdxRow, IdxCol} < RightDown; IdxRow++) {
                Result.push_back(Matrix[IdxRow][IdxCol]);
                PrintFlag = true;
            }

            for (std::tie(IdxRow, IdxCol) = RightDown; std::pair<size_t, size_t>{IdxRow, IdxCol} > LeftDown; IdxCol--) {
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