#include <iostream>
#include <vector>

void sieve(int n) {
    std::vector<bool> prime(n + 1, true);
    for (int p = 2; p <= n; ++p) {
        if (prime[p]) {
            std::cout << p << " ";
            for (int i = p * 2; i <= n; i += p) {
                prime[i] = false;
            }
        }
    }
    std::cout << std::endl;
}

int main() {
    sieve(1000);
    return 0;
}
