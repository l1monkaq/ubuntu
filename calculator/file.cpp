#include <iostream>
#include <cmath>
using namespace std;

// Функція для обчислення факторіалу числа
int factorial(int n) {
    return (n == 0 || n == 1) ? 1 : n * factorial(n - 1);
}

// Функція для застосування оператора до двох операндів
double applyOperator(double a, double b, char op) {
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b;
        default: return 0;
    }
}

// Функція для визначення пріоритету оператора
int getPrecedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    if (op == '!') return 3;
    return 0;
}

// Функція для обчислення математичного виразу
double evaluateExpression(const char* expr) {
    double values[100]; // Стек для збереження чисел
    char operators[100]; // Стек для збереження операторів
    int valTop = -1; // Вершина стека чисел
    int opTop = -1; // Вершина стека операторів

    for (int i = 0; expr[i] != '\0'; i++) {
        // Пропуск пробілів
        if (expr[i] == ' ') continue;

        // Обробка чисел
        if (isdigit(expr[i])) {
            double number = 0;
            while (expr[i] != '\0' && isdigit(expr[i])) {
                number = number * 10 + (expr[i] - '0');
                i++;
            }
            values[++valTop] = number;
            i--; // Зменшуємо індекс, щоб уникнути зайвого інкременту
        }
        // Обробка відкритої дужки
        else if (expr[i] == '(') {
            operators[++opTop] = expr[i];
        }
        // Обробка закритої дужки
        else if (expr[i] == ')') {
            while (opTop != -1 && operators[opTop] != '(') {
                double val2 = values[valTop--];
                double val1 = values[valTop--];
                char op = operators[opTop--];
                values[++valTop] = applyOperator(val1, val2, op);
            }
            opTop--; // Pop the '('
        }
        // Обробка базових операторів
        else if (expr[i] == '+' || expr[i] == '-' || expr[i] == '*' || expr[i] == '/') {
            while (opTop != -1 && getPrecedence(operators[opTop]) >= getPrecedence(expr[i])) {
                double val2 = values[valTop--];
                double val1 = values[valTop--];
                char op = operators[opTop--];
                values[++valTop] = applyOperator(val1, val2, op);
            }
            operators[++opTop] = expr[i];
        }
        // Обробка оператора факторіалу
        else if (expr[i] == '!') {
            int val = values[valTop--];
            values[++valTop] = factorial(val);
        }
    }

    // Обробляємо решту операторів у стеці
    while (opTop != -1) {
        double val2 = values[valTop--];
        double val1 = values[valTop--];
        char op = operators[opTop--];
        values[++valTop] = applyOperator(val1, val2, op);
    }

    return values[valTop];
}

int main() {
    char expression[100];
    cout << "Enter a mathematical expression: ";
    cin.getline(expression, 100);

    cout << "Result: " << evaluateExpression(expression) << endl;
    return 0;
}

