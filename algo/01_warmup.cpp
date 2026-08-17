#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }

    if (n == 0) {
        std::cout << "empty input" << std::endl;
        return 0;
    }

    int maxVal = a[0], minVal = a[0];
    int maxIdx = 0, minIdx = 0;
    for (int i = 1; i < n; ++i) {
        if (a[i] > maxVal) { maxVal = a[i]; maxIdx = i; }
        if (a[i] < minVal) { minVal = a[i]; minIdx = i; }
    }

    std::cout << "max=" << maxVal << " at index " << maxIdx << std::endl;
    std::cout << "min=" << minVal << " at index " << minIdx << std::endl;
    return 0;
}
