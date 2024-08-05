#include <iostream>
using namespace std;
int n;
char c[14][14];
int d[14];
bool flag;
bool g(int x) {
    for (int i = 0; i <= x; i++) {
        int sum = 0;
        for (int j = i; j <= x; j++) {
            sum += d[j];
            if ((sum > 0 && c[i][j] != '+') ||(sum < 0 && c[i][j] != '-') ||(sum == 0 && c[i][j] != '0')) {
                return 0;
            }
        }
    }
    return 1;
}
void f(int x) {
    if (flag) return;
    if (x == n) {
        for (int i = 0; i < n; i++) {
            cout << d[i] << " ";
        }
        flag = 1; 
        return;
    }
    if (c[x][x] == '0') {
        d[x] = 0;
        if (g(x)) f(x + 1);
    }
    else {
        for (int i = 1; i <= 10; i++) {
            d[x] = (c[x][x] == '+') ? i : -i;
            if (g(x)) f(x + 1);
        }
    }
}
int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            cin >> c[i][j];
        }
    }
    f(0);
}