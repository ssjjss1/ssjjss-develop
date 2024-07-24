#include<bits/stdc++.h>
using namespace std;
const int inf = 1e9 + 4;
int n, m, t;
vector<int> v;
int d[204][204];
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    fill(&d[0][0], &d[0][0] + 204 * 204, inf);
    for (int i = 1; i <= n; i++) {
        d[i][i] = 0;
    }
    for (int i = 1, x, y, z; i <= m; i++) {
        cin >> x >> y >> z;
        d[x][y] = z;
    }
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }
    cin >> t;
    for (int i = 1, x; i <= t; i++) {
        cin >> x;
        v.push_back(x);
    }
    int mn = inf;
    vector<int> v1;
    for (int i = 1; i <= n; i++) {
        int mx = 0;
        bool flag = true;
        for (auto j : v) {
            if (d[j][i] == inf || d[i][j] == inf) {
                flag = false;
                break;
            }
            mx = max(mx, d[j][i] + d[i][j]);
        }
        if (flag) {
            if (mx < mn) {
                mn = mx;
                v1.clear();
                v1.push_back(i);
            } 
            else if (mx == mn) {
                v1.push_back(i);
            }
        }
    }
    sort(v1.begin(), v1.end());
    for (auto i : v1) cout << i << " ";
}