#include <iostream>
// #include <limits>   // 用于输入流清理（可选）

// 函数声明（因为定义在main之后，必须提前声明）
char yun_suan_fu();
double shu_1();
double shu_2();

int main() {
    char c;      // 运算符
    double x1, x2;

    // 1. 获取合法运算符（循环直到输入正确）
    do {
        c = yun_suan_fu();
        // 修正条件：必须同时不是 + - * / 才报错（用 &&）
        if (c != '+' && c != '-' && c != '*' && c != '/') {
            std::cout << "你输入的不是运算符，请重新输入！\n";
        }
    } while (c != '+' && c != '-' && c != '*' && c != '/');

    // 2. 获取两个数字
    x1 = shu_1();
    x2 = shu_2();

    // 3. 计算结果（switch 每个 case 加 break）
    switch (c) {
        case '+':
            std::cout << "结果为: " << x1 + x2 << std::endl;
            break;
        case '-':
            std::cout << "结果为: " << x1 - x2 << std::endl;
            break;
        case '*':
            std::cout << "结果为: " << x1 * x2 << std::endl;
            break;
        case '/':
            // 防止除零
            if (x2 == 0) {
                std::cout << "错误：除数不能为0！" << std::endl;
            } else {
                std::cout << "结果为: " << x1 / x2 << std::endl;
            }
            break;
        default:
            // 理论上不会执行，但做个兜底
            std::cout << "未知运算符" << std::endl;
            break;
    }
    return 0;
}

// 函数定义
char yun_suan_fu() {
    char c;
    std::cout << "输入运算符（+、-、*、/）: ";
    std::cin >> c;
    return c;
}

double shu_1() {
    double x1;   // 补上分号
    std::cout << "输入第一个数: ";
    std::cin >> x1;
    return x1;
}

double shu_2() {
    double x2;   // 补上分号
    std::cout << "输入第二个数: ";
    std::cin >> x2;
    return x2;
}