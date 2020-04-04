// 要證明:
// 2n 的括號字串，左括號 {'('} 跟右括號 {')'} 數量都為 n，以及這樣的字串的所有 prefix(前綴)，左括號的數量 >= 右括號的數量
// 符合上述條件的所有字串的集合，要跟長度為 2n 的合法括號字串所形成的集合一樣
// 因為以下的演算法就是生成符合上述條件的所有字串的集合

// 用雙向證明，if A then B && if B then A

// 如果一個長度為 2n 的字串是合法括號字串，那它 1. 各有 n 個 '(' 跟 ')'，並且 2. 所有的 prefix，'(' 的數量都 >= ')' 的數量
// 證明:
//      1. 如果有一個 2n 字串它沒有各 n 個 '(' 跟 ')'，那它不可能是合法括號字串 -> trivial
//      2. 如果有一個 2n 字串它存在 prefix，'(' 的數量 < ')' 的數量，則這個 prefix 內多出來的 ')' 一定找不到 '(' 可以 match，不是合法字串

// 如果一個長度為 2n 的字串 1. 各有 n 個 '(' 跟 ')'，並且 2. 所有的 prefix， '(' 的數量都 >= ')' 的數量，那它就是合法括號字串
// 假設一個 2n 括號字串不合法，那一定找得到括號不 match(trivial)，又分以下情況
//      a. 存在 '(' 不 match，又分 a.1, a.2
//          a.1. '(' 的數量超過 n 個，這樣不符合 1.
//          a.2. '(' 跟 ')' 各為 n 個，但是存在 prefix，'(' 的數量 < ')'
//              這樣不符合 2.，且 prefix 內存在一個 ')' 不 match，而 prefix 之後存在 '(' 不 match
//              e.g. "()))(("，prefix 為 "()))"，裡面有 ')' 不 match，而尾端的兩個 '(' 都不 match

//      b. 存在 ')' 不 match，又分 b.1, b.2
//          b.1. ')' 的數量超過 n 個，這樣不符合 1.
//          b.2. 跟 a.2 一樣，這樣不符合 2

// some reference:
//  https://cs.stackexchange.com/questions/14557/language-of-balanced-parentheses-biconditional-proof-about-parentheses
//  https://sahandsaba.com/interview-question-generating-all-balanced-parentheses.html
//  Accurately defined, a balanced string of length 2n contains n instances of '('
//  and n instances of ')', and every prefix of the string must contain at least
//  as many open parentheses as closed ones.

#include <string>
#include <vector>
#include <iostream>

class Solution {
public:
    std::vector<std::string> generateParenthesis(int N) {
        std::vector<std::string> Combinations;
        backtrack_(Combinations, "(", N, 1, 0);
        return Combinations;
    }

private:
    void backtrack_(std::vector<std::string> &Combinations, std::string Current, const int N, const int Open, const int Close) {
        if (Current.size() == 2 * N) {
            Combinations.push_back(Current);
            return;
        }
        
        if (Open < N) {
            backtrack_(Combinations, Current + '(', N, Open + 1, Close);
        }
        if (Close < Open) {
            backtrack_(Combinations, Current + ')', N, Open, Close + 1);
        }
    }
};

int main() {
    Solution s;
    auto ret = s.generateParenthesis(10);
    for (auto &e : ret) {
        std::cout << e << std::endl;
    }
}