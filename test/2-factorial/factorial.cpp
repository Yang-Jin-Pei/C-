#include<iostream>

int main()
{
    int n;
    std::cout << "Enter a number: ";
    int factorial = 1;
    std::cin >> n;
    for (int i=1; i <= n; i++) {
        factorial *= i;
    }    
    std::cout << "Factorial of " << n << " is: ";
    std::cout << factorial << std::endl;
    return 0;
}