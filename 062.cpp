#include <vector>

class Solution {
public:
    // -----------------
    // |               |
    // |               |
    // |               | M
    // |               |
    // |               |
    // -----------------
    //        N
    //
    int uniquePaths(int N, int M) {
        // edge case 1: 0x0 Matrix
        if (N == 0 || M == 0) {
            return 0;
        }
        // edge case 2: a sequence
        if (N == 1 || M == 1) {
            return 1;
        }

        // initialize DP table
        std::vector<int> Row(N);
        Row.back() = 1;
        std::vector<std::vector<int>> DP(M - 1, Row);
        DP.push_back(std::vector<int>(N, 1));

        for (auto IdxRow = M - 1 - 1; IdxRow >= 0; IdxRow--) {
            for (auto IdxCol = N - 1 - 1; IdxCol >= 0; IdxCol--) {
                DP[IdxRow][IdxCol] = DP[IdxRow + 1][IdxCol] + DP[IdxRow][IdxCol + 1];
            }
        }
        return DP[0][0];
    }
};

int main() {
    Solution s;
    s.uniquePaths(1, 3);
}