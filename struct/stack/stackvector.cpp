// 采用vector写
#include <iostream>
#include <vector>
#include <string>

bool is_balanced_parentheses(const std::string& expression) {
    std::vector<char> stk;  // 直接用 vector 当栈

    for (char ch : expression) {
        if (ch == '(' || ch == '[' || ch == '{') {
            stk.push_back(ch);      // 入栈（等价于 push）
        } 
        else if (ch == ')' || ch == ']' || ch == '}') {
            if (stk.empty()) {
                return false;
            }
            char top = stk.back();   // 查看栈顶
            stk.pop_back();          // 出栈
            
            if ((ch == ')' && top != '(') ||
                (ch == ']' && top != '[') ||
                (ch == '}' && top != '{')) {
                return false;
            }
        }
    }
    return stk.empty();
}