#include <vector>
#include <algorithm>

// 這題要先知道一個事實：對於水庫任何一個位置，可以蒐集的水高
// 等於該位置右邊最高的牆，跟該位置左邊最高的牆
// 兩個裡面較矮的牆，減掉該位置本身的高度
// 可以畫出各種情境驗證這個陳述

// 再來就是找出每個位置的左邊跟右邊最高的牆
// 即可算出每個位置可以收集的水高並加總

class Solution {
public:
    int trap(const std::vector<int> &Heights) {
        if (Heights.empty()) {
            return 0;
        }

        auto LeftHighestWalls = calculateLeftHighestWallForEveryIdx_(Heights);
        auto RightHighestWalls = calculateRightHighestWallForEveryIdx_(Heights);

        int TrapWater = 0;
        for (size_t Idx = 0; Idx < Heights.size(); Idx++) {
            auto HeightDiff = std::min(LeftHighestWalls[Idx], RightHighestWalls[Idx]) - Heights[Idx];

            // 如果左右的牆都比較矮，則可收集水高為 0
            TrapWater += std::max(0, HeightDiff);
        }

        return TrapWater;
    }

private:
    std::vector<int> calculateLeftHighestWallForEveryIdx_(const std::vector<int> &Heights) {
        std::vector<int> LeftHighestWalls(Heights.size());
        int LeftMax = 0;
        for (size_t Idx = 1; Idx < Heights.size(); ++Idx) {
            LeftMax = std::max(Heights[Idx - 1], LeftMax);
            LeftHighestWalls[Idx] = LeftMax;
        }

        return LeftHighestWalls;
    }

    std::vector<int> calculateRightHighestWallForEveryIdx_(const std::vector<int> &Heights) {
        std::vector<int> RightHighestWalls(Heights.size());
        int RightMax = 0;
        for (int Idx = Heights.size() - 2; Idx >= 0; --Idx) {
            RightMax = std::max(Heights[Idx + 1], RightMax);
            RightHighestWalls[Idx] = RightMax;
        }

        return RightHighestWalls;
    }
};

int main() {
    std::vector<int> Heights{0,1,0,2,1,0,1,3,2,1,2,1};
    Solution s;
    auto water = s.trap(Heights);
}