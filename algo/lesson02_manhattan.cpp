// lesson02_manhattan.cpp
// 第 2 课练习：读入一个线网的 n 个引脚，按输入顺序相邻相连，输出曼哈顿总长
// 知识点：vector / struct / 函数 / for 循环（全部第 1-11 章内容）
//
// 输入格式：
//   n                （引脚个数）
//   name x y         （每行一个引脚的名字和坐标，共 n 行）
// 输出：
//   total manhattan length = <总长>
//
// 示例输入：
//   3
//   A1 0 0
//   B2 3 4
//   C3 8 1
// 示例输出：
//   total manhattan length = 15
//
// 注意：本文件于 2026-08-18 纸上完成，尚未编译运行（环境无编译器）。
//       恢复编译环境后第一件事：g++ lesson02_manhattan.cpp -o manhattan && ./manhattan

#include <iostream>
#include <string>
#include <vector>

// 引脚：名字 + 坐标（EDA 里最常用的复合类型之一）
struct Pin {
    std::string name;
    int x;
    int y;
};

// 曼哈顿距离：|x1-x2| + |y1-y2|
// 返回类型 int，参数按值传入（拷贝一份，函数里怎么改都不影响外面）
int manhattan(Pin a, Pin b) {
    int dx = a.x - b.x;
    if (dx < 0) dx = -dx;   // 取绝对值
    int dy = a.y - b.y;
    if (dy < 0) dy = -dy;
    return dx + dy;
}

int main() {
    int n = 0;
    std::cin >> n;

    std::vector<Pin> pins;   // 边读边存，个数未知 → 用 vector

    for (int i = 0; i < n; i++) {   // i 取 0 ~ n-1，共 n 次
        Pin p;                       // 临时引脚
        std::cin >> p.name >> p.x >> p.y;
        pins.push_back(p);           // 塞进列表
    }

    int total = 0;
    // 相邻两两相加：pins[0]-pins[1], pins[1]-pins[2], ...
    // 边界：n<=1 时循环条件 i<n 直接不成立，total 保持 0，无需特判
    for (int i = 1; i < n; i++) {
        total += manhattan(pins[i - 1], pins[i]);
    }

    std::cout << "total manhattan length = " << total << std::endl;
    return 0;
}
