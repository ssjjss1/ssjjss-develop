#include<iostream>
#include<queue>
#include<vector>
using namespace std;
int t, n, m, h;
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> t;
    while (t--) {
        cin >> n >> m;
        vector<int> cost(n + 4, 0);
        vector<int> in(n + 4, 0);
        vector<int> v[100004];
        vector<int> min_cost(n + 4, 0);
        for (int i = 1, x; i <= n; i++) {
            cin >> x;
            min_cost[i] = cost[i] = x;
        }
        for (int i = 1, x, y; i <= m; i++) {
            cin >> x >> y;
            v[x].push_back(y);
            in[y] += 1;
        }
        cin >> h;
        queue<int> q;
        for (int i = 1; i <= n; i++) if (!in[i]) q.push(i);
        while (!q.empty()) {
            int x = q.front();
            q.pop();
            for (auto j : v[x]) {
                min_cost[j] = max(min_cost[j], min_cost[x] + cost[j]);
                if (!--in[j]) q.push(j);
            }
        }
        cout<<min_cost[h]<<"\n";
    }
}