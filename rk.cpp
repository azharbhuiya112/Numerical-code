#include <iostream>
using namespace std;

// Define the differential equation dy/dx = f(x, y)
float f(float x, float y) {
    return x*x + y * y;
}

// Implement the fourth-order Runge-Kutta method
float rungeKutta(float x0, float y0, float h) {
    float k1, k2, k3, k4, k;
    k1 = h * f(x0, y0);
    k2 = h * f(x0 + h / 2, y0 + k1 / 2);
    k3 = h * f(x0 + h / 2, y0 + k2 / 2);
    k4 = h * f(x0 + h, y0 + k3);
    k = (k1 + 2 * k2 + 2 * k3 + k4) / 6;
    return y0 + k;
}

int main() {
    float x0, y0, xn, h;

    // Input values

    cin >> x0 >> y0 >> h >> xn;

    if (h <= 0) {
        cerr << "Error: Step size (h) should be greater than zero." << endl;
        return 1;
    }


    float x = x0;
    float y = y0;

    while (x <=  xn) {
        y = rungeKutta(x, y, h);
        x += h;
        cout << "when x = " << x << ", y = " << y << endl;
    }

    return 0;
}
