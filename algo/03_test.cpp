#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);

    // TODO 1: read n numbers into a  (use a for loop)
    for (int i=0;i<n;i++) {
        std::cin >> a[i];
    }
    // TODO 2: compute sum  (int)
    int sum=0;
    for (int i=0;i<n;i++) {
        sum = sum + a[i];
    }
    // TODO 3: compute avg  (double! careful: integer division)
    double avg=0;
    avg = double(sum)/n;
    // TODO 4: print sum and avg
    std::cout << "sum: " << sum << std::endl;
    std::cout << "avg: " << avg << std::endl;
    return 0;
}
