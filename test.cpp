#include <iostream>
#include <cmath>

using namespace std;



double azhar(double x) {
    return x*x - 4*x - 10;
}

double azharDerivative(double x) {
    return 2*x - 4;
}

double bisection(double a, double b, double tolerance) {
    if (azhar(a) * azhar(b) >= 0) {
        cout << "You have not assumed right a and b\n";
        return NAN;
    }

    double c = a;
    int it = 0;

    while ((b - a) >= tolerance) {
        c = (a + b) / 2;

        if (azhar(c) == 0.0)
            break;
        else if (azhar(c) * azhar(a) < 0)
            b = c;
        else
            a = c;

        it++;
        cout << it << "->";
    }
    return c;
}
double newtonRaphson(double x0, double tolerance) {
    int it = 0;
    double x = x0;

    while (fabs(azhar(x)) > tolerance) {
        x = x - azhar(x) / azharDerivative(x);
        it++;
        cout << it << "->";
    }

    return x;
}
double combinedMethod(double a, double b, double tolerance) {
    double bisectionRoot = bisection(a, b, tolerance);
    double newtonRaphsonRoot = newtonRaphson((a + b) / 2, tolerance);

    cout << "Bisection root: " << bisectionRoot << endl;
    cout << "Newton-Raphson root: " << newtonRaphsonRoot << endl;
    return (bisectionRoot + newtonRaphsonRoot) / 2;
}
void determinerange(int x1,int x2)
{
    int t;


    while(f(x1)*f(x2)>0)
    {
        f(x1)=x1*x2-4*x1-10;
        x1=x2;
        break;
    }
    a=x1;
    b=x2;
}


int main() {
    double a, b,x1,x2;



    double a1=sqrt((a0/a1)^2)-2(a2/a1)^2);
    void rangedetermine(a1,-a1);



    cout<<"Enter the tolerance"<<endl;
    double tolerance;
    cin>>tolerance;
    cout<<endl<<endl;
    cout << "\t\t\t\t Choose a method:\n" << endl;
    cout << "\t\t\t\t 1. Bisection Method" << endl;
    cout << "\t\t\t\t 2. Newton-Raphson" << endl;
    cout << "Enter your choice: ";
    int choice;
    cin >> choice;

    double root;

    switch (choice) {
        case 1:
            cout << "Solving using Bisection Method:" << endl;
            cout<<"my interval is :";
             cout<<"f(x1)*f(x2)<0"<<endl;
             cout<<"x1->"<<a<<endl;
            cout<<"x2->"<<b<<endl;
            rangedetermine(a1,-a1);
            root = bisection(a, b, tolerance);
            break;
        case 2:
            cout << "Solving using Combined Method:" << endl;
            root = combinedMethod(a, b, tolerance);
            rangedetermine(a1,-a1);
            break;
        default:
            cout << "Invalid choice!" << endl;
            return 1;
    }

    cout << "Approximate root: " << root << endl;

    return 0;
}

