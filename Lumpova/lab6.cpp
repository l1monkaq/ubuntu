#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
    int taskNumber;
    cout << "Enter task number (1, 2, 3 or 0 to exit): ";
    cin >> taskNumber;

    if (taskNumber == 0) return 0;

    if (taskNumber == 1) {
        int N;
        double sum = 0.0;
        double epsilon = 0.001;
        cout << "Enter N (number of terms): ";
        cin >> N;

        for (int i = 1; i <= N; ++i) {
            double term = pow(i, 3) / (pow(i, 3) + 9);
            sum += term;
            cout << "i = " << i << ", term = " << fixed << setprecision(5) << term << ", sum = " << sum << endl;
            if (term < epsilon) break;
        }

    } else if (taskNumber == 2) {
        double a = 0.8 * M_PI;
        for (double x = -1.2; x <= 2.0; x += 0.2) {
            double y;
            if (x > 1.4) {
                y = pow(x, 2) + 1;
            } else if (x >= -2.1 && x <= 1.4) {
                y = cos(a * x);
            } else {
                y = 0;
            }
            cout << "x = " << fixed << setprecision(2) << x << ", y = " << setprecision(5) << y << endl;
        }

    } else if (taskNumber == 3) {
        double a = 0.2;
        for (double x = -2.0; x <= 2.0; x += 0.5) {
            double Z;
            if (x <= 0.5) {
                Z = (x * x - 5 * x + 6) / (x * x + 1);
            } else {
                Z = (2.0 / 3.0) * pow(x, 3) - pow((x - 1.0 / 3.0), 0.25) * exp(a);
            }
            cout << "x = " << fixed << setprecision(2) << x << ", Z = " << setprecision(5) << Z << endl;
        }

    } else {
        cout << "Invalid task number!" << endl;
    }

    return 0;
}
