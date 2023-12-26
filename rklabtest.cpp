#include <iostream>
#include <fstream>
using namespace std;



float f(float x, float y) {
    return 2*x + 3*y*y;
}


float rungeKutta(float x0, float y0, float h) {
    float k1, k2, k3, k4, k;
    k1 = h * f(x0, y0);
    k2 = h * f(x0 + h / 2, y0 + k1 / 2);
    k3 = h * f(x0 + h / 2, y0 + k2 / 2);

    k = (k1 + 2 * k2 + 2 * k3) / 6;
    return y0 + k;
}

int main() {
    float x0 = 0.1, y0 = 1.1165, xn = 0.2, h = 0.01;


    ofstream outputFile("output.txt");

    if (!outputFile.is_open()) {
        cerr << "Error: Could not open the file." << endl;
        return 1;
    }

    float x = x0;
    float y = y0;

    while (x <= xn) {
        y = rungeKutta(x, y, h);
        x += h;
        outputFile << "when x = " << x << ", y = " << y << endl;
    }

    outputFile.close(); // Close the file
    cout << "Output written to output.txt." << endl;

    return 0;
}


