#include <iostream>
#include <cmath>

using namespace std;

int factorial(int n) {
    if (n == 0 || n == 1)
        return 1;
    return n * factorial(n - 1);
}

double applyOp(double a, double b, char op) {
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b;
        default: return 0;
    }
}

int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    if (op == '!') return 3;
    return 0;
}

double evaluate(const char* expr) {
    double values[100];
    char ops[100];    
    int valTop = -1;
    int opsTop = -1;

    for (int i = 0; expr[i] != '\0'; i++) {
      
        if (expr[i] == ' ') continue;

        if (isdigit(expr[i])) {
            double val = 0;
            while (expr[i] != '\0' && isdigit(expr[i])) {
                val = val * 10 + (expr[i] - '0');
                i++;
            }
            values[++valTop] = val;
            i--; 
        }
         else if (expr[i] == '(') {
            ops[++opsTop] = expr[i];
        }
        else if (expr[i] == ')') {
            while (opsTop != -1 && ops[opsTop] != '(') {
                double val2 = values[valTop--];
                double val1 = values[valTop--];
                char op = ops[opsTop--];
                values[++valTop] = applyOp(val1, val2, op);
            }
            opsTop--;
        }
        else if (expr[i] == '+' || expr[i] == '-' || expr[i] == '*' || expr[i] == '/') {
            while (opsTop != -1 && precedence(ops[opsTop]) >= precedence(expr[i])) {
                double val2 = values[valTop--];
                double val1 = values[valTop--];
                char op = ops[opsTop--];
                values[++valTop] = applyOp(val1, val2, op);
            }
            ops[++opsTop] = expr[i];
        }
        else if (expr[i] == '!') {
            int val = values[valTop--];
            values[++valTop] = factorial(val);
        }
    }

    while (opsTop != -1) {
        double val2 = values[valTop--];
        double val1 = values[valTop--];
        char op = ops[opsTop--];
        values[++valTop] = applyOp(val1, val2, op);
    }

    return values[valTop];
}

int main() {
    char expr[100];
    cout << "Enter a mathematical expression: ";
    cin.getline(expr, 100);

    cout << "Result: " << evaluate(expr) << endl;

    return 0;
}
