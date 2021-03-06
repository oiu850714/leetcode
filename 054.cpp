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
        auto Round = std::min(M, N);
        for (size_t I = 0; I < (Round + 1) / 2; I++) {
            std::pair<size_t, size_t> LeftUp = {I, I};
            std::pair<size_t, size_t> RightUp = {I, N - 1 - I};
            std::pair<size_t, size_t> RightDown = {M - 1 - I, N - 1 - I};
            std::pair<size_t, size_t> LeftDown = {M - 1 - I, I};

            if (LeftUp.first == LeftDown.first) {
                // edge case: 1*n 矩陣
                for (auto Idx = I; Idx <= RightUp.second; ++Idx) {
                    Result.push_back(Matrix[I][Idx]);
                }
                break;
            }

            if (LeftUp.second == RightUp.second) {
                // edge case: m*1 矩陣
                for (auto Idx = I; Idx <= LeftDown.first; ++Idx) {
                    Result.push_back(Matrix[Idx][I]);
                }
                break;
            }

            size_t IdxRow, IdxCol;

            for (std::tie(IdxRow, IdxCol) = LeftUp; std::pair<size_t, size_t>{IdxRow, IdxCol} < RightUp; IdxCol++) {
                Result.push_back(Matrix[IdxRow][IdxCol]);
            }

            for (std::tie(IdxRow, IdxCol) = RightUp; std::pair<size_t, size_t>{IdxRow, IdxCol} < RightDown; IdxRow++) {
                Result.push_back(Matrix[IdxRow][IdxCol]);
            }

            for (std::tie(IdxRow, IdxCol) = RightDown; std::pair<size_t, size_t>{IdxRow, IdxCol} > LeftDown; IdxCol--) {
                Result.push_back(Matrix[IdxRow][IdxCol]);
            }

            for (std::tie(IdxRow, IdxCol) = LeftDown; std::pair<size_t, size_t>{IdxRow, IdxCol} > LeftUp; IdxRow--) {
                Result.push_back(Matrix[IdxRow][IdxCol]);
            }
        }
        return Result;
    }
};

int main() {
    std::vector<std::vector<int>> Matrix1{
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    std::vector<std::vector<int>> Matrix2{
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
    };

    std::vector<std::vector<int>> Matrix3{
        {6, 9, 7},
    };
    std::vector<std::vector<int>> Matrix4{
        {7},
        {9},
        {6}
    };

    std::vector<std::vector<int>> Matrix5{
        {1, 2, 3, 4, 5, 6, 7, 8, 9, 10},
        {11, 12, 13, 14, 15, 16, 17, 18, 19, 20}
    };

    std::vector<std::vector<int>> Matrix6{
        {1,11},
        {2,12},
        {3,13},
        {4,14},
        {5,15},
        {6,16},
        {7,17},
        {8,18},
        {9,19},
        {10,20}
    };

    Solution s;
    auto v1 = s.spiralOrder(Matrix1);
    auto v2 = s.spiralOrder(Matrix2);
    auto v3 = s.spiralOrder(Matrix3);
    auto v4 = s.spiralOrder(Matrix4);
    auto v5 = s.spiralOrder(Matrix5);
    auto v6 = s.spiralOrder(Matrix6);
}