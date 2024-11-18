#include <bits/stdc++.h>
using namespace std;
struct P {int a, sum, mx;};
int n, a, b;
int visited[100004];
vector<pair<int, int>> v[100004];
int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> a >> b;
    for (int i = 1; i <= n; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        v[x].push_back({y, z});
        v[y].push_back({x, z});
    }
    queue<P> q;
    q.push({a, 0, 0}); 
    visited[a] = 1;
    while (!q.empty()) {
        int x = q.front().a;    
        int sum = q.front().sum;
        int mx = q.front().mx;  
        q.pop();
        if (x == b) { 
            cout << sum - mx; 
            return 0;
        }
        for (auto [y, d] : v[x]) {
            if (!visited[y]) {
                visited[y] = 1;
                q.push({y, sum + d, max(mx, d)});
            }
        }
    }
}