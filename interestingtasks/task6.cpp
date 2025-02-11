#include <iostream>
#include <vector>
using namespace std;

vector<string> ones = {"", "один", "два", "три", "чотири", "п'ять", "шість", "сім", "вісім", "дев'ять"};
vector<string> teens = {"десять", "одинадцять", "дванадцять", "тринадцять", "чотирнадцять", "п'ятнадцять", "шістнадцять", "сімнадцять", "вісімнадцять", "дев'ятнадцять"};
vector<string> tens = {"", "", "двадцять", "тридцять", "сорок", "п'ятдесят", "шістдесят", "сімдесят", "вісімдесят", "дев'яносто"};
vector<string> hundreds = {"", "сто", "двісті", "триста", "чотириста", "п'ятсот", "шістсот", "сімсот", "вісімсот", "дев'ятсот"};

string numberToWords(int n) {
    if (n == 1000) return "тисяча";
    string result = "";
    
    result += hundreds[n / 100] + " ";
    n %= 100;
    
    if (n >= 10 && n < 20) {
        result += teens[n - 10];
    } else {
        result += tens[n / 10] + " ";
        result += ones[n % 10];
    }
    
    while (!result.empty() && result.back() == ' ') {
        result.pop_back(); // Видаляємо зайві пробіли
    }
    
    return result;
}

int main() {
    int n;
    cout << "Введіть число (1-1000): ";
    cin >> n;
    if (n < 1 || n > 1000) {
        cout << "Число поза допустимим діапазоном!" << endl;
    } else {
        cout << numberToWords(n) << endl;
    }
    return 0;
}
