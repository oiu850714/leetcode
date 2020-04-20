#include <vector>
#include <map>

class Solution {
public:
    // note，這個 member function 的 interface 本質上就是錯的
    // 應該 return std::vector<size_t>
    // 但無法變更 interface，將錯就錯
    std::vector<int> twoSum(std::vector<int>& Nums, int Target) {
        // assume exactly one solution
        // and two numbers are at different position

        std::map<int, int> NumIndexMap; // pair.second should be size_t, not int
        for (auto Idx = 0; Idx < Nums.size(); Idx++) { // Idx should be size_t, not int
            auto FirstNum = Nums[Idx];
            auto SecondNum = Target - FirstNum;
            auto SecondNumQuery = NumIndexMap.find(SecondNum);
            if (SecondNumQuery != NumIndexMap.end()) {
                // 這個在找到的數字 + 當前數字 = Target，return
                return {Idx, SecondNumQuery->second};
            } else {
                NumIndexMap.insert({FirstNum, Idx});
            }
        }

        throw std::exception();
    }
};