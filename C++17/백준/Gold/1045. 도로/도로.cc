#include<bits/stdc++.h>
using namespace std;

vector<int> parent;
priority_queue<pair<int, pair<int, int>>> pq;

int find(int x) {
    if (x == parent[x]) return x;
    return parent[x] = find(parent[x]);
}

void union_set(int x, int y) {
    x = find(x);
    y = find(y);
    if (x != y) parent[x] = y;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n, m; 
    cin >> n >> m;

    vector<string> d(n);
    for (int i = 0; i < n; i++) cin >> d[i];

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (d[i][j] == 'Y') {
                pq.push({ -(i * n + j), {i, j} });
            }
        }
    }

    if ((int)pq.size() < m) {
        cout << -1 << "\n";
        return 0;
    }

    parent.resize(n);
    iota(parent.begin(), parent.end(), 0);
    vector<int> ans(n, 0);

    vector<pair<int, int>> v;
    int cnt = 0;

    while (!pq.empty()) {
        auto [i, j] = pq.top(); pq.pop();
        int x = j.first, y = j.second;

        if (find(x) != find(y)) {
            union_set(x, y);
            ans[x]+=1;
            ans[y]+=1;
            cnt+=1;
        }
        else v.push_back(j);
    }

    if (cnt < n - 1) {
        cout << -1 << "\n";
        return 0;
    }

    for (int i = 0; i < m - cnt; i++) {
        int x = v[i].first, y = v[i].second;
        ans[x]+=1;
        ans[y]+=1;
    }

    for (int i = 0; i < n; i++) cout << ans[i] << " ";
}