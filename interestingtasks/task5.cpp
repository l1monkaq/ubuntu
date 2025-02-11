#include <iostream>

bool isPalindrome(int num) {
    int reversed = 0, original = num;
    while (num > 0) {
        reversed = reversed * 10 + num % 10;
        num /= 10;
    }
    return original == reversed;
}

int main() {
    std::cout << "Palindromes up to 100 whose squares are also palindromes:\n";
    for (int i = 1; i < 100; ++i) {
        if (isPalindrome(i) && isPalindrome(i * i)) {
            std::cout << i << " ";
        }
    }
    std::cout << std::endl;
    return 0;
}
