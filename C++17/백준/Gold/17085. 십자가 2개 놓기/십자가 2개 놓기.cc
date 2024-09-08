#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int n, m;
char c[24][24];
int h(int size) {return 4 * size + 1;}
int g(int x, int y) {
    int t = 0;
    while (x - t > 0 && x + t <= n && y - t > 0 && y + t <= m) {
        if (c[x - t][y] == '#' && c[x + t][y] == '#' && c[x][y - t] == '#' && c[x][y + t] == '#') t+=1;
        else break;
    }
    return t - 1;
}
void f(int x, int y, int s, char t) {
    c[x][y] = t;
    for (int i = 1; i <= s; i++) {
        c[x - i][y] = t;
        c[x + i][y] = t;
        c[x][y - i] = t;
        c[x][y + i] = t;
    }
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> c[i][j];
        }
    }
    int mx = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (c[i][j] == '#') {
                int mx1 = g(i, j);
                for (int i1 = 0; i1 <= mx1; i1++) {
                    f(i, j, i1, '*');
                    for (int x = 1; x <= n; x++) {
                        for (int y = 1; y <= m; y++) {
                            if (c[x][y] == '#') {
                                int mx2 = g(x, y);
                                for (int i2 = 0; i2 <= mx2; i2++) {
                                    int k1 = h(i1), k2 = h(i2);
                                    mx = max(mx, k1 * k2);
                                }
                            }
                        }
                    }
                    f(i, j, i1, '#');
                }
            }
        }
    }
    cout << mx;
}