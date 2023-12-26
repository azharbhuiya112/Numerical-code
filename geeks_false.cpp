
#include <iostream>
#include <cmath>

using namespace std;

double azhar(double x) {
    return x*x - 4*x - 10;
}

double falsePosition(double a, double b, double tolerance) {
    double c = a;
    int it = 0;

    while (fabs(azhar(c)) > tolerance) {

        c = (a * azhar(b) - b * azhar(a)) / (azhar(b) - azhar(a));

        if (azhar(c) *azhar(a) < 0) {
            b = c;
        } else {
            a = c;
        }

        it++;
        cout << it<<"->";
        // << ": x = " << c << " (f(x) = " << azhar(c) << ")" << endl;
    }

    return c;
}

int main() {
    double a = -2.0;
    double b = 8.0;
    double tolerance = 1e-6;

    cout << "Solving using False Position Method:" << endl;
    double root = falsePosition(a, b, tolerance);
    cout<<"\n\n\n\n\n";
    cout << "Approximate root: " << root << endl;

    return 0;
}

