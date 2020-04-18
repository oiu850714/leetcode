#include <vector>
#include <set>

using SudokuBoard = std::vector<std::vector<char>>;
class Solution {
public:
    bool isValidSudoku(const SudokuBoard& Board) {
        for (int I = 0; I < 9; I++) {
            if (!checkRow_(Board, I)) {
                return false;
            }
            if (!checkCol_(Board, I)) {
                return false;
            }
            if (!checkBlk_(Board, I)) {
                return false;
            }
        }
        return true;
    }

private:
    bool checkRow_(const SudokuBoard& Board, int Row) {
        std::set<char> CheckRepeat;
        for (int Idx = 0; Idx < 9; Idx++) {
            if (Board[Row][Idx] == '.') {
                continue;
            }

            if (!CheckRepeat.insert(Board[Row][Idx]).second) {
                return false;
            }
        }
        return true;
    }

    bool checkCol_(const SudokuBoard& Board, int Col) {
        std::set<char> CheckRepeat;
        for (int Idx = 0; Idx < 9; Idx++) {
            if (Board[Idx][Col] == '.') {
                continue;
            }

            if (!CheckRepeat.insert(Board[Idx][Col]).second) {
                return false;
            }
        }
        return true;
    }

   bool checkBlk_(const SudokuBoard& Board, int BlockNum) {
        int BlockRow = BlockNum / 3;
        int BlockCol = BlockNum % 3;
        std::set<char> CheckRepeat;
        for (int I = BlockRow * 3; I < BlockRow * 3 + 3; I++) {
            for (int J = BlockCol * 3; J < BlockCol * 3 + 3; J++) {
                if (Board[I][J] == '.') {
                    continue;
                }

                if (!CheckRepeat.insert(Board[I][J]).second) {
                    return false;
                }
            }
        }
        return true;
    }
};

int main() {
    Solution s;
    SudokuBoard Board{{'5','3','.','.','7','.','.','.','.'},{'6','.','.','1','9','5','.','.','.'},{'.','9','8','.','.','.','.','6','.'},{'8','.','.','.','6','.','.','.','3'},{'4','.','.','8','.','3','.','.','1'},{'7','.','.','.','2','.','.','.','6'},{'.','6','.','.','.','.','2','8','.'},{'.','.','.','4','1','9','.','.','5'},{'.','.','.','.','8','.','.','7','9'}};
    s.isValidSudoku(Board);
}