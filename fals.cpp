#include <iostream>
#include <cmath>

using namespace std;

// Function to calculate the value of the equation at a given point x
double equation(double x) {
    return x*x - 4*x - 10;
}

// False position method
double falsePosition(double a, double b, double tolerance) {
    double c = a; // Initialize c with 'a' initially
    int iteration = 0;

    while (fabs(equation(c)) > tolerance) {
        // Calculate the new point 'c'
        c = (a * equation(b) - b * equation(a)) / (equation(b) - equation(a));

        // Check the sign of the equation at the new point 'c'
        if (equation(c) * equation(a) < 0) {
            b = c;
        } else {
            a = c;
        }

        iteration++;
        cout << "Iteration " << iteration << ": x = " << c << " (f(x) = " << equation(c) << ")" << endl;
    }

    return c;
}

int main() {
    double a = -2.0; // Initial interval [a, b]
    double b = 8.0;
    double tolerance = 1e-6; // Desired tolerance for the root

    cout << "Solving using False Position Method:" << endl;
    double root = falsePosition(a, b, tolerance);
    cout << "Approximate root: " << root << endl;

    return 0;
}

