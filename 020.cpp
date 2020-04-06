// https://www.youtube.com/watch?v=QZOLb0xHB_Q
class Solution {
public:
    bool isValid(std::string Input) {
        std::stack<char> Stack;

        for (auto C : Input) {
            if (isOpeningParentheses_(C)) {
                Stack.push(C);
                continue;
            }
            if (!Stack.empty() && isClosingParentheses_(C) && isMatch_(Stack.top(), C)) {
                Stack.pop();
            } else {
                return false;
            }
        }
        return Stack.empty();
    }

    bool isOpeningParentheses_(char C) {
        return C == '(' || C == '[' || C == '{';
    }

    bool isClosingParentheses_(char C) {
        return C == ')' || C == ']' || C == '}';
    }

    bool isMatch_(char Opening, char Closing) {
        return (Opening == '(' && Closing == ')')
            || (Opening == '{' && Closing == '}')
            || (Opening == '[' && Closing == ']');
    }
};
