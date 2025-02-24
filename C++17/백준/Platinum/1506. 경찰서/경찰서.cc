#include<bits/stdc++.h>
using namespace std;
int n, idx, ans;
vector<int> v[104];
vector<int> low(104, 0), d(104, 0);
vector<bool> finished(104, 0);
stack<int> stk;
vector<int> cost;

void f(int x) {
    d[x] = low[x] = ++idx;
    stk.push(x);
    for (auto node : v[x]) {
        if (!d[node]) {
            f(node);
            low[x] = min(low[x], low[node]);
        } else if (!finished[node]) {
            low[x] = min(low[x], d[node]);
        }
    }
    
    if (low[x] == d[x]) {
        int lowCost = 1e9 + 7;
        while (true) {
            int node = stk.top();
            stk.pop();
            lowCost = min(cost[node], lowCost);
            finished[node] = 1;
            if (x == node) break;
        }
        ans += lowCost;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    cost.resize(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> cost[i];
    }
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            char c;
            cin >> c;
            if (c == '1') v[i].push_back(j);
        }
    }
    
    for (int i = 1; i <= n; i++) {
        if (!d[i]) f(i);
    }
    
    cout << ans;
}