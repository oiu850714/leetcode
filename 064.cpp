#include <vector>
#include <algorithm>

class Solution {
public:
    int minPathSum(std::vector<std::vector<int>>& Grid) {
        if (Grid.empty() || Grid[0].empty()) {
            return 0;
        }

        auto DP = getInitialDP(Grid);
        int M = Grid.size();
        int N = Grid[0].size();

        for (int IdxRow = M - 1 - 1; IdxRow >= 0; IdxRow--) {
            for (int IdxCol = N - 1- 1; IdxCol >= 0; IdxCol--) {
                DP[IdxRow][IdxCol] = Grid[IdxRow][IdxCol]
                    + std::min(DP[IdxRow][IdxCol + 1], DP[IdxRow + 1][IdxCol]);
            }
        }

        return DP[0][0];
    }

private:
    std::vector<std::vector<int>> getInitialDP(const std::vector<std::vector<int>> &Grid) {
        int M = Grid.size();
        int N = Grid[0].size();

        std::vector<std::vector<int>> DP(M, std::vector<int>(N));

        // initialize the destination
        DP[M - 1][N - 1] = Grid[M - 1][N - 1];
        // initialize DP's last row and last col
        for (int Idx = N - 1 - 1; Idx >= 0; Idx--) {
            DP[M - 1][Idx] = Grid[M - 1][Idx] + DP[M - 1][Idx + 1];
        }
        for (int Idx = M - 1 - 1; Idx >= 0; Idx--) {
            DP[Idx][N - 1] = Grid[Idx][N - 1] + DP[Idx + 1][N - 1];
        }

        return DP;
    }
};

int main() {
    std::vector<std::vector<int>> Grid{
        {1, 2, 5},
        {3, 2, 1}
    };

    Solution s;
    s.minPathSum(Grid);
}