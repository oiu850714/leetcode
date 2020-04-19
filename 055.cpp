#include <vector>

class Solution {
public:
    bool canJump(std::vector<int>& Nums) {
        if (Nums.size() <= 1) {
            return true;
        }

        std::vector<bool> DP(Nums.size());
        DP.back() = true; // 最後一格就是 true

        int Idx = Nums.size();
        Idx -= 1; // 最後一格不用檢查
        while (Idx-- > 0) {

            int MaxStep = Nums[Idx]; // 從 Idx 可以跳的格數
            // 如果當前的下一格無法跳到終點:
            //     1. 這代表 [下一格, 下一格+下一格可以走到的地方] 一定都無法到終點
            //         * trivial... 如果下一格可以到的地方存在一個點可以到終點，則下一格就可以走到這個點，
            //         * 然後再走到終點，跟下一格無法到終點的敘述矛盾
            //     2. 如果當前格無法跳得比下一格可以走的位置還遠，則當前格不可能到終點，continue
            if (DP[Idx + 1] == false && Idx + MaxStep <= Idx + 1 + Nums[Idx + 1]) {
                continue;
            }

            // 從當前格可以跳得最遠的地方開始檢查，可否從這些地方到達終點
            int AttemptStep = (Idx + MaxStep >= Nums.size()) ? (Nums.size() - 1) : (Idx + MaxStep);
            for (; AttemptStep >= Idx; AttemptStep--) {
                if(DP[AttemptStep] == true) {
                    DP[Idx] = true;
                    break;
                }
            }
        }

        return DP[0];
    }
};

int main() {
    std::vector<int> Vec{5,3,3,3,2,1,0,0};
    Solution s;
    s.canJump(Vec);
}