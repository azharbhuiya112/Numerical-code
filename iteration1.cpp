#include<bits/stdc++.h>
using namespace std;

int parsing_f(string az, int i, int j) {

    int parsed_v = 0;
    int flag = 0;

    if(az[i] == '-')
        { flag = 1;
           i++;
        }

    if(az[i] == '+')
        { flag = 0;
          i++;
        }

    if(az[i] == '=')
        {
        i++;
        if(az[i] == '-')
        { flag = 1; i++; }

        if(az[i] == '+')
         { flag = 0; i++; }
    }

    for(i=0; i < j; i++) {
        parsed_v *= 10;
        parsed_v+= (az[i] - '0');
    }

    if(flag) return (parsed_v* (-1));
    else return parsed_v;
}

void azhar(string az, int &cse1, int &cse2, int &cse3, int &cse4) {

    int i = 0, j;

    cse1 = 0; cse2 = 0; cse3 = 0; cse4 = 0;

    for(j = 0; j < az.size(); j++)
    {
        if(az[j] == 'x')
            { cse1 = parsing_f(az, i, j); i = j + 1; j++; break; }
    }

    for(; j < az.size(); j++)
    {
        if(az[j] == 'y')
            { cse2 = parsing_f(az, i, j); i = j + 1; j++; break; }
    }

    for(; j < az.size(); j++)
    {
        if(az[j] == 'z')
            { cse3 = parsing_f(az, i, j); i = j + 1; j++; break; }
    }

    for(; j < az.size(); j++)
    {
        if(az[j] == 'u') { cse4 = parsing_f(az, i, j); i = j + 1; j++; break; }
    }

}

int main() {

    string az1, az2, az3;
    cin >> az1 >> az2 >> az3;

    int itr = 0;

    az1.push_back('u');
    az2.push_back('u');
    az3.push_back('u');

    int cse1, cse2, cse3, cse4, cse5, cse6, cse7, cse8, cse9, cse10, cse11, cse12;

    azhar(az1, cse1, cse2, cse3, cse4);
    azhar(az2, cse5, cse6, cse7, cse8);
    azhar(az3, cse9, cse10, cse11, cse12);

    double x = 9, x1 = 0, y = 9, y1 = 0, z = 9, z1 = 0;

    while(abs(x - x1) > 0.0001 || abs(y - y1) > 0.0001 || abs(z - z1) > 0.0001) {
        itr++;
        x = x1; y = y1; z = z1;
        x1 = (cse4 - cse2 * y - cse3 * z) / cse1;
        y1 = (cse8 - cse5 * x - cse7 * z) / cse6;
        z1 = (cse12 - cse9 * x - cse10 * y) / cse11;
    }

     cout << x1 <<endl;
     cout<<y1 <<endl;
     cout<<z1<<endl;
     cout<<itr<<endl;

    return 0;
}
