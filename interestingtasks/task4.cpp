#include <iostream>
#include <vector>

void primeFactorization(int n) {
    std::cout << n << " = ";
    for (int i = 2; i * i <= n; ++i) {
        while (n % i == 0) {
            std::cout << i << ", ";
            n /= i;
        }
    }
    if (n > 1) std::cout << n;
    std::cout << std::endl;
}

int main() {
    int num;
    std::cout << "Enter a number: ";
    std::cin >> num;
    primeFactorization(num);
    return 0;
}
