#include <vector>

class Solution {
public:
    void setZeroes(std::vector<std::vector<int>>& Matrix) {
        if (Matrix.empty() || Matrix[0].empty()) {
            return;
        }

        int M = Matrix.size();
        int N = Matrix[0].size();

        std::vector<bool> SelectedRow(M);
        std::vector<bool> SelectedCol(N);

        for (int Row = 0; Row < M; Row++) {
            for (int Col = 0; Col < N; Col++) {
                if (Matrix[Row][Col] == 0) {
                    SelectedRow[Row] = true;
                    SelectedCol[Col] = true;
                }
            }
        }

        for (int Row = 0; Row < M; Row++) {
            if (SelectedRow[Row]) {
                // 若這排有 0，
                // 則這排直接 assign 全 0，然後直接跳過
                Matrix[Row] = std::vector<int>(N);
                continue;
            }
            for (int Col = 0; Col < N; Col++) {
                if (SelectedCol[Col]) {
                    Matrix[Row][Col] = 0;
                }
            }
        }
    }
};


int main() {
    std::vector<std::vector<int>> Matrix{
        {1,1,1},
        {1,0,1},
        {1,1,1}
    };

    Solution s;
    s.setZeroes(Matrix);
    Matrix.back();
}