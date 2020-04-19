#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<std::vector<int>> combinationSum(std::vector<int>& Candidates, int Target) {
        std::sort(Candidates.begin(), Candidates.end());
        if (Candidates.empty()) {
            throw std::exception();
        }
        Target_ = Target;
        for (int SelectIdx = 0; SelectIdx < Candidates.size(); SelectIdx++) {
            Comb_.push_back(Candidates[SelectIdx]);
            backtrack_(Candidates, Candidates[SelectIdx], SelectIdx);
            Comb_.pop_back();
        }
        return CombSet_;
    }
private:
    void backtrack_(const std::vector<int> &Candidates, int Sum, int SelectIdx) {
        if (Sum > Target_) {
            return;
        }

        if (Sum == Target_) {
            CombSet_.push_back(Comb_);
            return;
        }

        if (Sum + Candidates[SelectIdx] <= Target_) {
            Comb_.push_back((Candidates[SelectIdx]));
            backtrack_(Candidates, Sum + Candidates[SelectIdx], SelectIdx);
            Comb_.pop_back();
        }

        for (SelectIdx++; SelectIdx < Candidates.size(); SelectIdx++) {
            Comb_.push_back(Candidates[SelectIdx]);
            backtrack_(Candidates, Sum + Candidates[SelectIdx], SelectIdx);
            Comb_.pop_back();
        }
    }
    std::vector<std::vector<int>> CombSet_;
    std::vector<int> Comb_;
    int Target_;
};

int main() {
    std::vector<int> Candidates{2, 3, 5};
    int Target = 7;
    Solution s;
    auto v = s.combinationSum(Candidates, Target);
    int a = 10;
    a = 20;
}