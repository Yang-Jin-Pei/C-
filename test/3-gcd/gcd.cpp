#include<iostream>
#include<vector>

int gcd(int num) {
    std::vector<int> n;
    int n_next = 0;
    int i = 0;
    do {
        n.push_back(num % 10);
        n_next += n[i];
	    std::cout << i << ": " << n[i] << std::endl;
        num /= 10;
        ++i;
    } while (num);
	std::cout << n_next << std::endl;
    if (n_next<10){
        return n_next;
    }
    else {
        return gcd(n_next);
    }
}

int main() {
	int num;
	std::cin >> num;
    int res;
    res = gcd(num);
    std::cout << "result: " << res << std::endl;
    return 0;
}