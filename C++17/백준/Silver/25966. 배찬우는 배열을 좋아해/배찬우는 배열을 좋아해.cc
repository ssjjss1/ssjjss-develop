#include <bits/stdc++.h>
using namespace std;

int n, m, q;
int d[3004][3004];
int pl[3004];

void Init() {
    for (int i = 0; i < n; i++) {
        pl[i] = i;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> q;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> d[i][j];
        }
    }

    Init();

    while (q--) {
        int p;
        cin >> p;
        if (p == 0) {
            int i, j, k;
            cin >> i >> j >> k;
            d[pl[i]][j] = k;
        } else {
            int i, j;
            cin >> i >> j;
            swap(pl[i], pl[j]);
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << d[pl[i]][j] << " ";
        }
        cout << "\n";
    }
}