#include<bits/stdc++.h>
using namespace std;
int n, m;
vector<int> v[100004];
int ans[100004];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int x, y; cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    for (int i = 1; i <= n; i++) {
        set<int> visited;
        for (auto x : v[i]) visited.insert(ans[x]);
        int c = 1;
        while (visited.count(c)) c += 1; 
        ans[i] = c;
        cout << ans[i] << " ";
    }
}
