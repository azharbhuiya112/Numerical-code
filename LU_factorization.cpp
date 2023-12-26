#include <bits/stdc++.h>
using namespace std;
const int n = 20;
double aug[n][n + 1];
#define epsilon 0.001
#define N 3
double l[N][N], u[N][N], solution[N];
void addCoef(string str, int p)
{
    int count = 0;
    for (int i = 0; i < str.size(); i++)
    {
        if (('0' <= str[i] && str[i] <= '9') || str[i] == '+' || str[i] == '-')
        {
            string temp = "";
            int k = i;
            while (('0' <= str[k] && str[k] <= '9') || str[k] == '+' || str[k] == '-')
            {
                temp += str[k];
                k++;
            }
            aug[p][count] = stoi(temp);
            count++;

            i = k;
        }
    }
}
void urow(int i)
{
    float s;
    int j, k;

    for (j = i; j < N; j++)
    {
        s = 0;

        for (k = 0; k < N - 1; k++)
            s += u[k][j] * l[i][k];

        u[i][j] = aug[i][j] - s;
    }
}

void lcol(int j)
{
    float s;
    int i, k;

    for (i = j + 1; i < N; i++)
    {
        s = 0;
        for (k = 0; k <= j - 1; k++)
            s += u[k][j] * l[i][k];

        l[i][j] = (aug[i][j] - s) / u[j][j];
    }
}

void find_LU(void)
{
    for (int i = 0; i < N; i++)
        l[i][i] = 1.0;

    for (int m = 0; m < N; m++)
    {
        urow(m);
        if (m < N - 1)
            lcol(m);
    }
}

void find_solution(void)
{
    double s;
    int i, j;
    double v[N] = {0};
    for (i = 0; i < N; i++)
    {
        s = 0;

        for (j = 0; j <= i - 1; j++)
            s += l[i][j] * v[j];

        v[i] = aug[i][N] - s;
    }

    for (i = N - 1; i >= 0; i--)
    {
        s = 0;

        for (j = i + 1; j < N; j++)
            s += u[i][j] * solution[j];

        solution[i] = (v[i] - s) / u[i][i];
    }

    cout << "Solution is:-" << endl;

    for (i = 0; i < N; i++)
    {
        cout << "x[" << setw(3) << i + 1 << "]=";
        cout << setw(6) << setprecision(4);
        cout << solution[i] << endl;
    }
}

void printmat(double x[N][N])
{
    int i, j;

    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
            cout << setw(8) << setprecision(4) << x[i][j];
        cout << endl;
    }
}

int main()
{
    int m, it;
    cout << "Enter the no of eqn: " << endl;
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        cout << "Enter equation no: " << i + 1 << endl;
        string eqn;
        cin >> eqn;
        addCoef(eqn, i);
    }
    find_LU();
    printmat(u);
    printmat(l);
    find_solution();
}
