
#include<bits/stdc++.h>
using namespace std;
#define error 0.01


double azhar(double x)
{
    return x*x - 4*x - 10;
}


void bisection(double a, double b)
{
    if (azhar(a) * azhar(b) >= 0)
    {
        cout << "You have not assumed right a and b\n";
        return;
    }

    double c = a;
    while ((b-a) >= error)
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
    cout << "The value of root is : " << c;
}


int main()
{

    double a =5, b = 6;
    bisection(a, b);
    return 0;
}
