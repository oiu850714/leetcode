#include <algorithm>
#include <vector>
#include <string>
#include <map>

using AnagramGroups = std::map<std::vector<int>, std::vector<std::string>>;

class Solution {
public:
    std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string>& Strs) {
        // lowercase -> 26 ascii
        // 如果 utf8，那應該還是乖乖 sort
        AnagramGroups Groups;
        for (const auto &Str : Strs) {
            Groups[countedCategory_(Str)].push_back((Str));
        }

        std::vector<std::vector<std::string>> Ret;
        std::transform(Groups.begin(), Groups.end(), std::back_inserter(Ret), [] (auto E) { return E.second; });

        return Ret;
    }

    std::vector<int> countedCategory_(const std::string &Str) {
        std::vector<int> Count(26);
        for (auto c : Str) {
            ++Count[c - 'a'];
        }

        return Count;
    }
};