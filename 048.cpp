#include <vector>

class Solution {
public:
    void rotate(std::vector<std::vector<int>>& Matrix) {
        auto N = Matrix.size();
        // 建義畫圖觀察 I, J 的 range，以及 Matrix 的 index 計算
        for (size_t I = 0; I < (N + 1) / 2; I++) {
            for (size_t J = I; J < N - I - 1; J++) {
                auto Tmp = Matrix[I][J];
                Matrix[I][J] = Matrix[N - J - 1][I];
                Matrix[N - J - 1][I] = Matrix[N - I - 1][N - J - 1];
                Matrix[N - I - 1][N - J - 1] = Matrix[J][N - I - 1];
                Matrix[J][N - I - 1] = Tmp;
            }
        }
    }
};