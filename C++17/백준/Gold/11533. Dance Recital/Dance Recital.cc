#include <bits/stdc++.h>
using namespace std;

int n, mn = INT_MAX;
vector<string> v;

int check(string a, string b) {
    int res = 0;
    for (auto c : a) {
        if (b.find(c) != string::npos) {
            res+=1;
        }
    }
    return res;
}

void f(vector<bool> &visited, int cnt, int sum, string l) {
    if (sum >= mn) return;
    if (cnt == n) {
        mn = min(mn, sum);
        return;
    }

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            visited[i] = 1;
            int d = (l.empty() ? 0 : check(l, v[i]));
            f(visited, cnt + 1, sum + d, v[i]);
            visited[i] = 0;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    v.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    vector<bool> visited(n, 0);
    f(visited, 0, 0, "");

    cout << mn;
}