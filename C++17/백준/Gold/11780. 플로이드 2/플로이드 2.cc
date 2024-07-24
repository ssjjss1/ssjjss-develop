#include<iostream>
#include<vector>
using namespace std;
const int inf = 1e9 + 4;
int n, m;
int d[104][104], visited[104][104];
void f(int x, int y) {
    if (d[x][y]==inf||!d[x][y]) {
        cout << 0 << "\n";
        return;
    }
    vector<int> v;
    while (x != y) {
        v.push_back(x);
        x = visited[x][y];
    }
    v.push_back(y);
    cout << v.size() << " ";
    for (int k : v) cout << k << " ";
    cout << "\n";
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    fill(&d[0][0], &d[0][0] + 104 * 104, inf);
    for (int i = 1; i <= n; i++) {
        d[i][i] = 0;
        for (int j = 1; j <= n; j++) {
            if (i != j) visited[i][j] = j;
        }
    }
    for (int i = 1, x, y, z; i <= m; i++) {
        cin >> x >> y >> z;
        if (z < d[x][y]) {
            d[x][y] = z;
            visited[x][y] = y;
        }
    }
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (d[i][k] + d[k][j] < d[i][j]) {
                    d[i][j] = d[i][k] + d[k][j];
                    visited[i][j] = visited[i][k];
                }
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j) cout << 0 << " ";
            else cout << (d[i][j] == inf ? 0 : d[i][j]) << " ";
        }
        cout << "\n";
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            f(i, j);
        }
    }
}