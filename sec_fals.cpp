#include <iostream>
#include <cmath>
using namespace std;

int a, b, c;

double f(double x) {
    return a * x * x + b * x + c;
}

void secant(double x1, double x2) {
    int cnt = 0;
    double x3;

    while (abs(x2 - x1) > 0.0001) {
        x3 = (x1 * f(x2) - x2 * f(x1)) / (f(x2) - f(x1));
        x1 = x2;
        x2 = x3;
        cnt++;
    }

    cout << "Root (Secant Method): " << x2 << " (found in " << cnt << " iterations)" << endl;
}

void falsePosition(double x1, double x2) {
    int cnt = 0;
    double x3;

    while (abs(x2 - x1) > 0.0001) {
        x3 = (x1 * f(x2) - x2 * f(x1)) / (f(x2) - f(x1));
        if (f(x3) == 0.0) {
            cout << "Root (False Position Method): " << x3 << " (found in " << cnt << " iterations)" << endl;
            return;
        }
        if (f(x1) * f(x3) < 0) {
            x2 = x3;
        }
        else {
            x1 = x3;
        }
        cnt++;
    }

    cout << "Root (False Position Method): " << x2 << " (found in " << cnt << " iterations)" << endl;
}

int main() {
    cout << "Enter the coefficients of the quadratic equation (a b c): ";
    cin >> a >> b >> c;

    double x1, x2;
    cout << "Initial guesses for x1 and x2: ";
    cin >> x1 >> x2;

    int choice;
    cout << "Choose a method (1 for Secant, 2 for False Position): ";
    cin >> choice;

    switch (choice) {
        case 1:
            secant(x1, x2);
            break;
        case 2:
            falsePosition(x1, x2);
            break;
        default:
            cout << "Invalid choice." << endl;
    }

    return 0;
}

