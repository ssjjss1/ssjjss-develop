#include <bits/stdc++.h>
#define INF 20004
using namespace std;

int n, k, idx, scc_idx;
vector<pair<char, int>> test;
vector<int> d(INF, 0), low(INF, 0), scc_label(INF, -1);
vector<int> v[INF];
vector<bool> finished(INF);
vector<vector<int>> SCC;
stack<int> stk;

void dfs(int x) {
    d[x] = low[x] = ++idx;
    stk.push(x);
    for (int node : v[x]) {
        if (!d[node]) {
            dfs(node);
            low[x] = min(low[x], low[node]);
        } else if (!finished[node]) {
            low[x] = min(low[x], d[node]);
        }
    }
    if (low[x] == d[x]) {
        vector<int> scc;
        while (true) {
            int node = stk.top();
            stk.pop();
            scc_label[node] = scc_idx;
            finished[node] = true;
            scc.push_back(node);
            if (node == x) break;
        }
        scc_idx += 1;
        SCC.push_back(scc);
    }
}

void build_2sat() {
    for (int j = 0; j < 3; j++) {
        int x = test[j].second - 1;  // 1-based index를 0-based로 조정
        int y = test[(j + 1) % 3].second - 1;
        int cx = (test[j].first == 'R');
        int cy = (test[(j + 1) % 3].first == 'R');

        int not_cx = cx ^ 1;
        int not_cy = cy ^ 1;

        v[x * 2 + not_cx].push_back(y * 2 + cy);
        v[y * 2 + not_cy].push_back(x * 2 + cx);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> k >> n;

    for (int i = 0; i < n; i++) {
        test.clear();
        for (int j = 0; j < 3; j++) {
            char c;
            int x;
            cin >> x >> c;
            test.push_back({c, x});
        }
        build_2sat();
    }

    for (int i = 0; i < 2 * k; i++) {
        if (!d[i]) dfs(i);
    }

    for (int i = 0; i < k; i++) {
        if (scc_label[2 * i] == scc_label[2 * i + 1]) {
            cout << -1;
            return 0;
        }
    }

    vector<int> visited(k, 0);
    vector<char> val(k, 'R'); 

    for (auto& scc : SCC) {
        for (auto j : scc) {
            int var = j / 2;
            if (!visited[var]) {
                visited[var] = 1;
                if (j % 2) val[var] = 'R';
                else val[var] = 'B';
            }
        }
    }

    for (int i = 0; i < k; i++) {
        cout << val[i];
    }
}