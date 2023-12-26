#include<bits/stdc++.h>
using namespace std;

int azhar(string s, int i, int j) {
    int a = 0, f = 0;
    if (s[i] == '-') { f = 1; i++; }
    if (s[i] == '+') { f = 0; i++; }
    if (s[i] == '=') {
        i++;
        if (s[i] == '-') { f = 1; i++; }
        if (s[i] == '+') { f = 0; i++; }
    }

    for (; i < j; i++) {
        a *= 10;
        a += (s[i] - '0');
    }
    if (f) return (a * (-1));
    else return a;
}

void azhar1(string s, int &a, int &b, int &c, int &d) {
    int i = s.size() - 1, j;
    a = 0; b = 0; c = 0; d = 0;
    for (j = s.size() - 1; j >= 0; j--) {
        if (s[j] == 'u') { d = azhar(s, j + 1, i + 1); i = j - 1; }
        if (s[j] == 'z') { c = azhar(s, j + 1, i + 1); i = j - 1; }
        if (s[j] == 'y') { b = azhar(s, j + 1, i + 1); i = j - 1; }
        if (s[j] == 'x') { a = azhar(s, j + 1, i + 1); i = j - 1; }
    }
}

int main() {
    string s1, s2, s3;
    cin >> s1 >> s2 >> s3;
    int itr = 0;
    s1.push_back('u');
    s2.push_back('u');
    s3.push_back('u');
    int a1, b1, c1, d1, a2, b2, c2, d2, a3, b3, c3, d3;
    azhar1(s1, a1, b1, c1, d1);
    azhar1(s2, a2, b2, c2, d2);
    azhar1(s3, a3, b3, c3, d3);

    double x = 9, x1 = 0, y = 9, y1 = 0, z = 9, z1 = 0;
    while (abs(x - x1) > 0.0001 || abs(y - y1) > 0.0001 || abs(z - z1) > 0.0001) {
        itr++;
        x = x1; y = y1; z = z1;
        x1 = (d1 - b1 * y - c1 * z) / a1;
        y1 = (d2 - a2 * x - c2 * z) / b2;
        z1 = (d3 - a3 * x - b3 * y) / c3;
    }
    cout << x1 << ' ' << y1 << ' ' << z1 << ' ' << itr << endl;

    return 0;
}

