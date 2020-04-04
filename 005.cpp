#include <vector>
#include <string>

class Solution {
public:
    std::string longestPalindrome(const std::string &TestString) {
        // 測試字串長度為 0~2，直接判斷
        if (TestString.size() <= 1) {
            return s;
        }
        if (TestString.size() == 2) {
            return TestString[0] == TestString[1] ? TestString : std::string(TestString, 0, 1);
        }

        // boundary case: 最長回文為 1，所以要初始化成長度為 1 的子字串
        std::string MaxStr = std::string(s, 0, 1);

        // 建立 DP table
        vector<vector<bool>> DP(TestString.size(), vector<bool>(TestString.size()));
        for (size_t i = 0; i < TestString.size(); i++) {
            DP[i][i] = true;
            if (i + 1 < TestString.size()) {
                DP[i][i+1] = s[i] == s[i+1];
            }

            // boundary case: 最長回文為 2
            if (DP[i][i+1]) {
                MaxStr = std::string(s, i, 2);
            }
        }

        // 從長度為 3 的子字串開始檢查
        // StartRow, StartColumn 指向的 range 為閉區間，[StartRow, StartColumn]
        // 而不是 [StartRow, StartColumn)
        for (size_t StartColumn = 2; StartColumn < TestString.size(); StartColumn++) {
            for (size_t StartRow = 0; StartRow <= StartColumn - 2; StartRow++) {
                 if (DP[StartRow + 1][StartColumn - 1] && s[StartRow] == s[StartColumn]) {
                     DP[StartRow][StartColumn] = true;
                     if (StartColumn - StartRow + 1 > MaxStr.size()) {
                         MaxStr = std::string(MaxStr, StartRow, StartColumn - StartRow + 1);
                     }
                 } else {
                     DP[StartRow][StartColumn] = false;
                 }
            }
        }
        return MaxStr;
    }
};

int main() {
    Solution s;
    std::cout << s.longestPalindrome("babad");
}
