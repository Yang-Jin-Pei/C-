# 堆栈
标准库为stack
```cpp
#include<stack>
```
# 操作
## 生成
```cpp
#include<stack>
std::stack<char> stk;
```
## push，压入
```cpp
#include<stack>
std::stack<char> stk;
stk.push(ch);
```
## empty，判断是否为空
```cpp
#include<stack>
std::stack<char> stk;
stk.push('ch');
stk.empty();
```
## top，看栈顶
```cpp
#include<stack>
std::stack<char> stk;
stk.push('ch');
stk.empty();
stk.top();
```
## pop，压出
```cpp
#include<stack>
std::stack<char> stk;
stk.push('ch');
stk.empty();
stk.top();
stk.pop();
```
