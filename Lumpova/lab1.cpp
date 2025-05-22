#include <iostream>
#include <cmath>

using namespace std;

int main() {
    double a, b, c;
    double D;
    char again = 'y';

    while (again == 'y' || again == 'Y') {
        cout << "Enter coefficients a, b and c: ";
        cin >> a >> b >> c;

        if (a == 0) {
            cout << "This is not a quadratic equation.\n";
        } else {
            D = b * b - 4 * a * c;
            cout << "Discriminant (D) = " << D << endl;

            if (D > 0) {
                double x1 = (-b + sqrt(D)) / (2 * a);
                double x2 = (-b - sqrt(D)) / (2 * a);
                cout << "Two real roots:\n";
                cout << "x1 = " << x1 << endl;
                cout << "x2 = " << x2 << endl;
            } else if (D == 0) {
                double x = -b / (2 * a);
                cout << "One real root:\n";
                cout << "x = " << x << endl;
            } else {
                cout << "No real roots (D < 0).\n";
            }
        }

        cout << "Do you want to enter another equation? (y/n): ";
        cin >> again;
    }

    return 0;
}
