// 采用STL标准库
#include <iostream>      // std::cout, std::endl
#include <stack>         // std::stack
#include <string>        // std::string
#include <unordered_map> // std::unordered_map

// 括号匹配函数
bool is_balanced_parentheses(const std::string& expression) {
    // 标准库栈，默认底层容器为 std::deque（你也可以指定 std::vector）
    std::stack<char> stk;

    // 括号映射：右括号 -> 左括号
    std::unordered_map<char, char> matching_bracket = {
        {')', '('},
        {']', '['},
        {'}', '{'}
    };

    for (char ch : expression) {
        // 1. 左括号：入栈
        if (ch == '(' || ch == '[' || ch == '{') {
            stk.push(ch);
        }
        // 2. 右括号：检查匹配
        else if (ch == ')' || ch == ']' || ch == '}') {
            if (stk.empty()) {
                return false;          // 右括号多了
            }
            char top = stk.top();
            stk.pop();
            if (matching_bracket[ch] != top) {
                return false;          // 括号不匹配（如 "(]"）
            }
        }
        // 3. 其他字符（字母、数字、空格等）忽略
    }
    return stk.empty();  // 栈空 => 全部匹配，否则左括号多了
}

int main() {
    // 测试用例
    std::string tests[] = {
        "{[()]}",          // 匹配
        "{[(])}",          // 不匹配（顺序错）
        "((()))",          // 匹配
        "({}",             // 不匹配（左括号多）
        "})",              // 不匹配（右括号多）
        "a + (b - c)",     // 匹配（忽略其他字符）
        ""                 // 空字符串 -> 匹配（栈空）
    };

    for (const auto& expr : tests) {
        bool balanced = is_balanced_parentheses(expr);
        std::cout << "\"" << expr << "\" -> " 
                  << (balanced ? "Balanced" : "Not Balanced") 
                  << std::endl;
    }
    return 0;
}