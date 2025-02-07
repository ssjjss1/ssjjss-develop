#include<bits/stdc++.h>
using namespace std;

int d[2300][2300];
int cnt1, cnt2, cnt3;

void check(int x) {
    if (x == -1) cnt1 += 1;
    if (x == 0) cnt2 += 1;
    if (x == 1) cnt3 += 1;
}

void f(int x, int y, int size) {
    if (size == 1) {
        check(d[x][y]);
        return;
    }
    
    bool flag = false;
    int t = d[x][y];
    for (int i = x; i < x + size; i++) {
        for (int j = y; j < y + size; j++) {
            if (t != d[i][j]) {
                flag = true;
                break;
            }
        }
        if (flag) break;
    }
    
    if (!flag) {
        check(t);
        return;
    }
    
    int t_size = size / 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            f(x + i * t_size, y + j * t_size, t_size);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> d[i][j];
        }
    }
    
    f(0, 0, n);
    
    cout << cnt1 << "\n" << cnt2 << "\n" << cnt3;
}