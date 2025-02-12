#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> parent, Rank;

void Init() {
    for (int i = 0; i <= n; i++) {
        parent[i] = i;
        Rank[i] = 1;  
    }
}

int Find(int x) {
    if (x != parent[x]) 
        parent[x] = Find(parent[x]);
    return parent[x];
}

void Union_set(int x, int y) {
    x = Find(x);
    y = Find(y);
    
    if (x != y) {
        if (Rank[x] < Rank[y]) swap(x, y);
        parent[y] = x;
        if (Rank[x] == Rank[y]) Rank[x]+=1;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    parent.resize(n + 1);
    Rank.resize(n + 1);
    Init();
    
    for (int i = 1; i <= m; i++) {
        int t, a, b;
        cin >> t >> a >> b;
        if (t == 0) {
            Union_set(a, b);
        } else {
            cout << (Find(a) == Find(b) ? "YES\n" : "NO\n");
        }
    }
}