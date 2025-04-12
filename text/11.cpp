#include <iostream>

int main() {
    int num1, num2;

    // 提示用户输入第一个整数
    std::cout << "请输入第一个整数: ";
    std::cin >> num1;

    // 提示用户输入第二个整数
    std::cout << "请输入第二个整数: ";
    std::cin >> num2;

    // 计算两个整数的和
    int sum = num1 + num2;

    // 输出计算结果
    std::cout << "这两个整数的和是: " << sum << std::endl;

    return 0;
}    