#include<bits/stdc++.h>
using namespace std;

int n, m, k;
int parent[51];
vector<int> know;
vector<vector<int>> v(51);

int find(int x) {
    if (parent[x] == x) return x;
    return parent[x] = find(parent[x]);
}

void unite(int x, int y) {
    x = find(x), y = find(y);
    if (x != y) parent[y] = x;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) parent[i] = i;

    for (int i = 1; i <= k; i++) {
        int x; 
        cin >> x;
        know.push_back(x);
    }
    
    for (int i = 1; i < know.size(); i++) {
        unite(know[0], know[i]);
    }
    
    for (int i = 1; i <= m; i++) {
        int t; 
        cin >> t;
        for (int j = 1; j <= t; j++) {
            int x; 
            cin >> x;
            v[i].push_back(x);
        }
        for (int j = 1; j < t; j++) {
            unite(v[i][0], v[i][j]);
        }
    }

    int truthParent = k > 0 ? find(know[0]) : -1;
    int cnt = 0;

    for (int i = 1; i <= m; i++) {
        bool flag = true;
        for (auto j : v[i]) {
            if (find(j) == truthParent) {
                flag = false;
                break;
            }
        }
        if (flag) cnt+=1;
    }

    cout << cnt;
}