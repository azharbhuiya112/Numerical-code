#include<bits/stdc++.h>
using namespace std;
const int n=20;
double aug[n][n+1];
#define epsilon 0.001
void addCoef(string str,int p){
        int count=0;
        for(int i=0;i<str.size();i++){
                if(('0'<=str[i] && str[i]<='9') ||  str[i]=='+'|| str[i]=='-'){
                        string temp="";
                        int k=i;
                        while(('0'<=str[k] && str[k]<='9') ||  str[k]=='+'|| str[k]=='-'){
                                temp+=str[k];
                                k++;
                        }
                        aug[p][count]=stoi(temp);
                        count++;
                        i=k;
                }

        }
}


void gauss_seidal(int m,int it,double old_solution[]){
        double new_solution [m]={0};
        for(int i=0;i<it;i++){
                for(int j=0;j<m;j++){
                        double sum=0;
                        for(int k=0;k<m;k++){
                                if(j!=k) sum+=aug[j][k]*new_solution[k];
                        }
                        new_solution[j]=(aug[j][m]-sum)/aug[j][j];
                }
                bool flag=1;
                for(int j=0;j<m;j++){
                        if(abs(old_solution[j]-new_solution[j])<=epsilon) continue;
                        flag=0;
                        break;
                }
                if(flag){
                        for(int j=0;j<m;j++){
                                cout<<"Solution:\n";
                                cout<<j+1<<": "<<new_solution[j]<<endl;
                        }
                        return;
                }
                for(int j=0;j<m;j++){
                        cout<<"Iteration: "<<i+1<<", ["<<j+1<<"]"<<": "<<new_solution[j]<<endl;
                        old_solution[j]=new_solution[j];
                }
        }
        for(int j=0;j<m;j++){
                cout<<"Solution:\n";
                cout<<j+1<<": "<<new_solution[j]<<endl;
        }
}



int main(){
        int m,it;
        cout<<"Enter the no of eqn: "<<endl;
        cin>>m;
        cout<<"Enter the max no of iteration: "<<endl;
        cin>>it;
        for(int i=0;i<m;i++){
                cout<<"Enter equation no: "<<i+1<<endl;
                string eqn;
                cin>>eqn;
                addCoef(eqn,i);
        }

        double solution[m]={0};
        gauss_seidal(m,it,solution);
}
