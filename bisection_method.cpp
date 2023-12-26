#include<bits/stdc++.h>
using namespace std;
const int n=20;
double aug[n];
#define epsilon 0.0001
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
    return aug[0]*x*x+aug[1]*x+aug[2];
}

double bisection_method(double x1,double x2,int it){
     if(func(x1)*func(x2)>0){
         cout<<"x1 and x2 do not bracket the root\n";
         return 0.0;
    }

    for(int i=0;i<it;i++){
        double x0=(x1+x2)/2;
        if(func(x1)*func(x0)<0){
            x2=x0;
        }else if(func(x2)*func(x0)<0){
            x1=x0;
        }

        if(abs((x2-x1)/x2)<epsilon){
            cout<<"Root is: "<<(x1+x2)/2<<endl;
            return (x1+x2)/2;
        }
    }
    cout<<"Root is: "<<(x1+x2)/2<<endl;
    return (x1+x2)/2;
}

int main(){
        int it;
        cout<<"Enter the max no of iteration: "<<endl;
        cin>>it;
        cout<<"Enter the equation: "<<endl;
        string eqn;
        cin>>eqn;
        addCoef(eqn);
        cout<<"Enter the initial bound: "<<endl;
        double x1,x2;
        cin>>x1>>x2;
        bisection_method(x1,x2,it);
}