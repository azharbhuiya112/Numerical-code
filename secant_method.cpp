#include<bits/stdc++.h>
using namespace std;
const int n=20;
double aug[n];
#define epsilon 0.001
void addCoef(string str){
        int count=0;
        for(int i=0;i<str.size();i++){
                if(('0'<=str[i] && str[i]<='9') ||  str[i]=='+'|| str[i]=='-'){
                        string temp="";
                        int k=i;
                        while(('0'<=str[k] && str[k]<='9') ||  str[k]=='+'|| str[k]=='-'){
                                temp+=str[k];
                                k++;
                        }
                        aug[count]=stoi(temp);
                        count++;
                        i=k;
                }

        }
}

double func(double x){
    return aug[0]*x*x*x+aug[1]*x+aug[2];
}
double compute(double x1,double x2){
    return (func(x2)*x1-func(x1)*x2)/(func(x2)-func(x1));
}

double secant_method(double x1,double x2,int it){
    double x3;
    for(int i =0;i<it;i++){
        x3= compute(x1,x2);
        if(abs((x3-x2)/x3)<=epsilon){
            cout<<"Solution is: "<<x3<<endl;
            return x3;
        }
        x1=x2;
        x2=x3;
            
    }
    cout<<"Solution is: "<<x3<<endl;
    return x3;
}

int main(){
        int it;
        cout<<"Enter the max no of iteration: "<<endl;
        cin>>it;
        cout<<"Enter the equation: "<<endl;
        string eqn;
        cin>>eqn;
        addCoef(eqn);
        cout<<"Enter the initial points: "<<endl;
        double x1,x2;
        cin>>x1>>x2;
        secant_method(x1,x2,it);
}