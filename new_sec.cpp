
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
char ch[101];
int a , b , c;
double f(double x){
    double sol=0.0;
    return a * x * x + b * x + c;
}
double diff(double x){
    return 2 * a * x + b;
}
double newton(double x){
    double x1 = x - f(x)/diff(x);
}
void newmethod(){
    double x1 = 0;
    double x2 = x1 - f(x1)/diff(x1);
    while(abs(x2 - x1) > .0001){
        double x3 = x2 - f(x2)/diff(x2);
        cout<<x2<<" "<<x3<<endl;
        x1 = x2;
        x2 = x3;
    }
    cout<<x1<<endl;
}

void secant(double x1, double x2 ){
    int cnt=0;
    double x3, xm;

    while (abs(x2-x1) > 0.0001)
    {

        x3 = (x1*f(x2) - x2*f(x1))/(f(x2)-f(x1));
        cout<< "x1 ="<<x1 << "  f(x1)" << f(x1)<<endl;
        cout<< "x2 ="<<x2 << "->  f(x2)" << f(x2)<<endl;
        x1 = x2;
        x2 = x3;
        cnt++;

    }
    cout << x2 << " " << cnt << endl;
}

int main()
{
    scanf("%s",ch);

    char gar;
    sscanf(ch , "%d%c%c%c%d%c%d" , &a , &gar , &gar , &gar , &b , &gar , &c);
    cout<<a<<" "<<b<<" "<<c<<endl;

    double x1, x2;
    //cout<< "approximation value of x1 and x2 : " <<endl;
    //cin>> x1>>x2;
    //secant(x1,x2);
    newmethod();
    return 0;
}
/*

f(x2)x1 - f(x1)x2
------------------
f(x2) - f(x1)

*/
