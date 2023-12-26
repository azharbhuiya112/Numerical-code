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
    return aug[0]*x*x+aug[1]*x+aug[2];
}
double diff(double x){
    return 2*x-5;
}

double newton_raphson(double x0,int it){
    double x1;
    for(int i =0;i<it;i++){
        x1= x0-func(x0)/diff(x0);
        if(abs(x1-x0)<=epsilon){
            cout<<"Solution is: "<<x1<<endl;
            return x1;
        }
        cout<<"iteration is: "<<i+1<<" "<<x1<<endl;
        x0=x1;
    }
    cout<<"Solution is: "<<x1<<endl;
    return x1;
}

int main(){
        int it;
        cout<<"Enter the max no of iteration: "<<endl;
        cin>>it;
        cout<<"Enter the equation: "<<endl;
        string eqn;
        cin>>eqn;
        addCoef(eqn);
        cout<<"Enter the initial point: "<<endl;
        double initial;
        cin>>initial;
        newton_raphson(initial,it);
}