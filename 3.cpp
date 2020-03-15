#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <map>
#include <algorithm>

using std::cout;
using std::endl;
using std::vector;
using std::unordered_set;
using std::unordered_map;
using std::set;
using std::map;
using std::string;

/*
 *
 * [i, j] 如果是 unique，就檢查 [i, j+1];
 * 如果 [i, j+1] 不為 unique，則 [i, j+1], [i, j+2],... [i, n] 都不可能為 unique，所以可以跳過，
 * 直接看 [i+1, j]
 * 注意，一個字串若為 unique，則子字串也為 unique
 * 所以不需要從 [i+1, (i+1)+1] 重新開始看，直接繼續看 [i+1, j] 即可
 * 注意 j 一定 >= i，因為 j - i 的距離就是當前 set 的大小，至少 >= 0
 *
 */

class Solution {
public:
    int lengthOfLongestSubstring(const string &s) {
        if (s.size() <= 1) {
            return s.size();
        }

        size_t max_size = 0;
        unordered_set<char> keep;
        for (size_t i = 0, j = 0; i < s.size() && j < s.size();) {
            if (keep.find(s[j]) != keep.end()) {
                keep.erase(s[i++]);
                continue;
            }
            max_size = std::max(j - i + 1, max_size);
            keep.insert(s[j++]);
        }
        return max_size;
    }
};

int main() {
    cout << Solution().lengthOfLongestSubstring("bbbbb") << endl;
}
