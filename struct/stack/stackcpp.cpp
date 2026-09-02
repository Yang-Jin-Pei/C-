// 胡乱搓
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

class Stack {
private:
    std::vector<char> items;   // 列表（向量）模拟栈，末尾为栈顶

public:
    void push(char item) {
        items.push_back(item); // 入栈，追加到末尾
    }

    char pop() {
        if (is_empty()) {
            return '\0';       // 栈空返回空字符（类似 Python 的 None）
        }
        char top = items.back();
        items.pop_back();
        return top;
    }

    char peek() {
        if (is_empty()) {
            return '\0';
        }
        return items.back();
    }

    bool is_empty() const {
        return items.empty();
    }

    size_t size() const {
        return items.size();
    }
};

bool is_balanced_parentheses(const std::string& expression) {
    Stack stack;
    std::unordered_map<char, char> matching_bracket = {
        {')', '('},
        {']', '['},
        {'}', '{'}
    };

    for (char ch : expression) {
        // 如果是左括号，入栈
        if (ch == '(' || ch == '[' || ch == '{') {
            stack.push(ch);
        }
        // 如果是右括号
        else if (ch == ')' || ch == ']' || ch == '}') {
            if (stack.is_empty()) {
                return false;           // 栈空，右括号多了
            }
            char top = stack.pop();
            if (matching_bracket[ch] != top) {
                return false;           // 不匹配
            }
        }
        // 其他字符（字母、数字、空格等）自动忽略
    }
    return stack.is_empty();  // 检查是否所有左括号都被匹配
}

int main() {
    // 栈测试
    Stack plate_stack;
    plate_stack.push('1');
    plate_stack.push('2');
    plate_stack.push('3');
    std::cout << "取出最上面的盘子: " << plate_stack.pop() << std::endl;    // 3
    std::cout << "现在最上面的盘子是: " << plate_stack.peek() << std::endl; // 2

    // 括号匹配测试
    std::string test_cases[] = {"((1+2)*3)", "({[ ]})", "((())", ")( )"};
    for (const std::string& test : test_cases) {
        bool result = is_balanced_parentheses(test);
        std::cout << "表达式 '" << test << "' 的括号是 " 
                  << (result ? "平衡" : "不平衡") << " 的。" << std::endl;
    }

    return 0;
}