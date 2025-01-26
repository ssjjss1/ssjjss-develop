#include<bits/stdc++.h>
using namespace std;

int n, q;
int parent[200004];
int node_size[200004];

int find(int x) {
    if (parent[x] == x) return x;
    return parent[x] = find(parent[x]);
}

void Union(int x, int y) {
    x = find(x);
    y = find(y);
    if (x != y) {
        if (node_size[x] < node_size[y]) swap(x, y);
        parent[y] = x;
        node_size[x] += node_size[y];
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> n >> q;
    vector<int> v(n);
    vector<vector<int>> d(400004, vector<int>(3));
    stack<bool> res;

    for (int i = 1; i <= n; i++) {
        parent[i] = i;
        node_size[i] = 1;
    }

    for (int i = 1; i < n; i++) cin >> v[i], v[i]-=1;
    
    q+=(n-1);

    for (int i = 1; i <= q; i++) {
        cin >> d[i][0] >> d[i][1];
        if (d[i][0] == 0) {
            d[i][1]-=1;
        } else {
            cin >> d[i][2];
            d[i][1]-=1;
            d[i][2]-=1;
        }
    }

    for (int i = q; i >= 1; i--) {
        if (d[i][0] == 0) {
            Union(d[i][1], v[d[i][1]]);
        } else {
            int u = find(d[i][1]);
            int v = find(d[i][2]);
            res.push(u == v);
        }
    }

    while (!res.empty()) {
        if (res.top()) cout << "YES\n";
        else cout << "NO\n";
        res.pop();
    }
}