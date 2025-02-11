#include <iostream>

void printPascalsTriangle(int rows) {
    for (int i = 0; i < rows; ++i) {
        int num = 1;
        for (int j = 0; j <= i; ++j) {
            std::cout << num << " ";
            num = num * (i - j) / (j + 1);
        }
        std::cout << std::endl;
    }
}

int main() {
    int n;
    std::cout << "Enter number of rows: ";
    std::cin >> n;
    printPascalsTriangle(n);
    return 0;
}
