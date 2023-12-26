#include <bits/stdc++.h>
using namespace std;

double err;

double f(double x){
    return (x*x-4*x-10);
}
void FP(double a,double b,double err){
    if(f(a)*f(b)>=0){
        cout << "No Solution" << endl;
        return;
    }

    else{

    double x0;
    double x1=a;
    double x2=b;
    int i=0;

     while(abs((x2-x1)/(double)(1.0*x2))>=err){
        i++;
        x0=x2-f(x2)*((x1-x2)/(f(x1)-f(x2)));

        if(f(x0)==0){
            break;
        }
        if(f(x0)*f(x1)<0){
            x2=x0;
        }
        else{
            x1=x0;
        }

     }

     cout << "Root: " << x0;
    }

}
int main()
{
    double a,b;
    cout << "Enter range: " << endl;
    cout << "a: ";
    cin >> a;
    cout << endl;
    cout << "b: ";
    cin >> b;

    cout << "Enter error margin: ";
    cin >> err;
    FP(a,b,err);

    return 0;
}
