# C++ 零基础 · 第 2 课：函数与 struct（纸上编程课）

> 2026-08-18。教程第 10–11 章。今天没有编译器，全程"纸上编程"——概念照学、代码照写，只是暂时不能运行。
> 前置：第 1 课（骨架 / 变量 / 运算符 / 输入输出 / if / for / 数组 / vector）。

## 0. 上节课复习（for 循环边界，上次的薄弱点）

```cpp
for (int i = 0; i < n; i++) { ... }
```

- i 的取值是 **0, 1, 2, ..., n-1**，共 n 次，**永远到不了 n**；
- 三个常见错误：
  1. `i <= n` → 多执行一次，最后一次 i == n，**访问 arr[n] 越界**（数组没有下标 n）；
  2. `i = 1` 开头 → 少一次，漏掉下标 0 的元素；
  3. 忘写 `i++` → **死循环**（程序卡死）。
- 自查口诀：**"从 0 开始，小于 n，共 n 次"**。

vector 复习：
```cpp
#include <vector>
std::vector<int> a;      // 空列表
a.push_back(7);           // 末尾追加
int len = a.size();       // 元素个数（类型 size_t，可当 int 用）
std::cout << a[0];        // 下标访问，和数组一样从 0 开始
```

## 1. 函数：把代码变成"可复用零件"

### 1.1 为什么需要函数

一段逻辑（比如"算两点距离"）如果要在 10 个地方用，复制粘贴 10 遍 → 改一处漏一处，必出 bug。
**函数 = 给一段代码起个名字，想用就叫名字。**

### 1.2 语法（两半：定义 + 调用）

```cpp
// 定义：返回类型 函数名(参数列表) { 函数体 }
int add(int x, int y) {     // 接收两个 int，返回一个 int
    return x + y;           // return 把结果"交回去"
}

int main() {
    int r = add(3, 4);      // 调用：add(3,4) 的值是 7，存进 r
    std::cout << r << std::endl;   // 7
    return 0;
}
```

- 函数四要素：**返回类型 / 函数名 / 参数 / 函数体**；
- `return 值;` 执行到就**立刻结束**函数，把值交回去；
- 不需要返回值的函数，返回类型写 `void`，可以没有 return；
- `main` 本身就是一个函数：程序的大门。

### 1.3 EDA 例子：曼哈顿距离（布线问题里的基本量）

芯片上导线走"横平竖直"的网格，所以两点距离不是直线，而是：

```
曼哈顿距离 = |x1 - x2| + |y1 - y2|
```

```cpp
int manhattan(int x1, int y1, int x2, int y2) {
    int dx = x1 - x2;
    if (dx < 0) dx = -dx;      // 取绝对值：负数变正数
    int dy = y1 - y2;
    if (dy < 0) dy = -dy;
    return dx + dy;
}
```

## 2. struct：把相关数据打包成一个

### 2.1 为什么需要 struct

一个引脚有"名字 + x + y"三个数据。分开存三个变量，一多就乱、容易错位。
**struct = 自己定义一种"复合类型"，把相关的数据打包。**

### 2.2 语法

```cpp
struct Pin {          // 定义新类型 Pin
    std::string name; // 成员 1
    int x;            // 成员 2
    int y;            // 成员 3
};

int main() {
    Pin p;            // 造一个 Pin 盒子（三个成员自动一起出现）
    p.name = "A1";    // 用 . 访问成员
    p.x = 10;
    p.y = 20;
    std::cout << p.name << " (" << p.x << "," << p.y << ")" << std::endl;
    return 0;
}
```

- 先 `struct 名字 { 成员... };` 定义（**结尾有分号**，别忘）；
- 用 `盒子.成员` 访问；
- struct 可以直接复制：`Pin q = p;` 是**复制内容**，改 q 不影响 p。

### 2.3 EDA 例子

```cpp
struct Pin  { std::string name; int x; int y; };   // 引脚
struct Net  { std::string name; std::vector<Pin> pins; };  // 线网 = 名字 + 一串引脚
struct Cell { std::string name; int x, y; };       // 单元
```

> 这就是 DEF 文件里 COMPONENTS / NETS 的样子——**mini 项目 1（DEF 解析器）的地基**。

## 3. 今日练习：一个线网的曼哈顿总长（DEF 解析器雏形）

题目：读入一个线网的 n 个引脚（名字 + 坐标），按输入顺序相邻相连，
输出总曼哈顿长度。

```
输入：
3
A1 0 0
B2 3 4
C3 8 1

输出：
total manhattan length = 14
（|0-3|+|0-4| + |3-8|+|4-1| = 7 + 8 = 15？——自己再算一遍，以代码为准）
```

完整代码见 `../代码/lesson02_manhattan.cpp`。设计思路（先想清楚再写）：

1. 需要存什么？→ 每个引脚的名字/坐标 → `struct Pin`；
2. 需要重复算的？→ 两点距离 → 函数 `manhattan`；
3. 输入多少未知 → `std::vector<Pin>` 边读边存；
4. 相邻两两相加 → for 循环从 i=1 到 n-1，`total += manhattan(pins[i-1], pins[i])`；
5. 边界：n==0 或 n==1 时没有相邻对 → total 保持 0，循环自然不执行（for 条件不成立）——**这就是"边界不用特殊处理"的正确写法**。

## 4. 今日自测（第 10–11 章，在聊天里回答）

Q1. 打印什么？
```cpp
int add(int a, int b) { return a + b; }
int main() { std::cout << add(3, 4) + 1 << std::endl; }
```

Q2. 判断对错：`return` 只能写在函数体的最后一行。

Q3. 打印什么？
```cpp
struct Point { int x; int y; };
int main() {
    Point p; p.x = 5; p.y = 3;
    Point q = p;      // 复制
    q.x = 9;
    std::cout << p.x << " " << q.x << std::endl;
}
```

Q4.（for 边界复习）`for (int i = 0; i < 3; i++)` 循环体执行几次？结束后 i 的值是多少？

## 5. 下一课预告

函数和 struct 学完，教程基础篇（第 1–11 章）就全走完了。
下一课进入**文件读写（ifstream/ofstream）**——会读文件，就能真的开始解析 DEF 文件，mini 项目 1 正式开工。
