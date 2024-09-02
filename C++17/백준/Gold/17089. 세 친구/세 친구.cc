#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int n, m;
vector<int> v[4004];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    int mn = 1e9;
    for (int i = 1; i <= n; i++) {
        for (auto j : v[i]) {
            if (j <= i) continue;
            for (auto k : v[j]) {
                if (k <= j || k == i) continue;
                if (find(v[i].begin(), v[i].end(), k) != v[i].end()) {
                    int sum = (v[i].size() - 2) + (v[j].size() - 2) + (v[k].size() - 2);
                    mn = min(mn, sum);
                }
            }
        }
    }
    if (mn == 1e9) cout << -1;
    else cout << mn;
}