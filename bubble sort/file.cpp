#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>

int main() {
    int n;
    std::cout << "Enter the size of the array (n): ";
    std::cin >> n;

    if (n <= 0) {
        std::cerr << "The size of the array must be a positive number." << std::endl;
        return 1;
    }

    std::vector<int> array(n);

    std::srand(std::time(nullptr));

    for (int i = 0; i < n; ++i) {
        array[i] = std::rand() % 100;
    }

    std::cout << "Initial array: ";
    for (int num : array) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    std::sort(array.begin(), array.end());

    std::cout << "Sorted array: ";
    for (int num : array) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}