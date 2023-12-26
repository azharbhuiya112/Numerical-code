#include <iostream>
#include <cmath>

using namespace std;

double azhar(double x) {
    return x*x - 4*x - 10;
}


double bisection(double a, double b,double tolerance)
{
    if (azhar(a) * azhar(b) >= 0)
    {
        cout << "You have not assumed right a and b\n";

    }

    double c = a;
    while ((b-a) >= tolerance)
    {
        int it;
        c = (a+b)/2;


        if (azhar(c) == 0.0)
            break;


        else if (azhar(c)*azhar(a) < 0)
            b = c;
        else
            a = c;

            it++;
            cout<<it<<"->";
    }
    return c;
}


double falsePosition(double a, double b, double tolerance) {
    double c = a;
    int it=0;

    while (fabs(azhar(c)) > tolerance) {
        c = (a * azhar(b) - b * azhar(a)) / (azhar(b) - azhar(a));

        if (azhar(c) * azhar(a) < 0) {
            b = c;
        } else {
            a = c;
        }

        it++;
         cout<<it<<"->";
                // cout << "Iteration " << iteration << ": x = " << c << " (f(x) = " << azhar(c) << ")" << endl;
    }

    return c;
}

int main() {
    double a;
    double b ;
    cout<<"assume a& b";
    cin>>a;
    cout<<endl;
    cin>>b;

    double tolerance = 1e-6;
    int Choice;
    int c;

    cout << "Choose a method:" << endl;
    cout << "1. Bisection Method" << endl;
    cout << "2. False Position Method" << endl;
    cout << "Enter your choice: ";
    cin >>Choice;

    double root;

    switch (Choice) {
        case 1:
            cout << "Solving using Bisection Method:" << endl;
             root=bisection(a, b, tolerance);
            break;
        case 2:
            cout << "Solving using False Position Method:" << endl;
            root = falsePosition(a, b, tolerance);
            break;
        default:
            cout << "Invalid choice!" << endl;
            return 1;
    }

    cout << "Approximate root: " << root << endl;

    return 0;
}

