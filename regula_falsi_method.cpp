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


double falsi_method(double x1,double x2,int it){
     if(func(x1)*func(x2)>0){
         cout<<"x1 and x2 do not bracket the root\n";
         return 0.0;
    }

    double x0=0.0;


    for(int i=0;i<it;i++){
        x0=x1-(func(x1)*(x2-x1))/(func(x2)-func(x1));

        if(func(x1)*func(x0)<0){
            x2=x0;
        }else if(func(x2)*func(x0)<0){
            x1=x0;
        }
//
//        double x3=x1-(func(x1)*(x2-x1))/(func(x2)-func(x1));
//        if(abs(x3-x0)<epsilon){
//            cout<<"Root is: "<<x3<<endl;
//            return x3;
//        }
//        x0=x3;
    }


    cout<<"Root is: "<<x0<<endl;
    return x0;
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
        falsi_method(x1,x2,it);
}
