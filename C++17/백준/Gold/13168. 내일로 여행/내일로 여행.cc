#include<bits/stdc++.h>
using namespace std;
int n, m, t, c;
int d[204][204];
const int inf = 1e9 + 4;
struct P {
    string s1;  // 열차 이름
    int to, cost;  // to, cost
};
vector<int> v;
vector<P> v1[10004];
map<string, int> ma;
int min(int x, int y) { return x > y ? y : x; }
int f() {
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < v.size() - 1; i++) ans += d[v[i]][v[i + 1]];
    return ans;
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> c;
    for (int i = 1; i <= n; i++) {
        string s;
        cin >> s;
        ma[s] = i;
    }
    cin >> m;
    v.resize(m + 4);
    for (int i = 1; i <= m; i++) {
        string s;
        cin >> s;
        v.push_back(ma[s]);
    }
    cin >> t;
    for (int i = 1; i <= t; i++) {
        string s1, s2, s3;
        int x;
        cin >> s1 >> s2 >> s3 >> x;
        v1[ma[s2]].push_back({ s1, ma[s3], x });
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j) d[i][j] = 0;
            else d[i][j] = inf;
        }
    }
    for (int i = 1; i <= n; i++) {
        for (auto j : v1[i]) {
            int x = j.to, y = j.cost;
            string s = j.s1;
            if (s == "ITX-Saemaeul" || s == "ITX-Cheongchun" || s == "Mugunghwa") d[i][x] = 0, d[x][i] = 0;
            else if (s == "S-Train" || s == "V-Train") d[i][x] = min(d[i][x], y), d[x][i] = min(d[x][i], y);
            else d[i][x] = min(d[i][x], y * 2), d[x][i] = min(d[x][i], y * 2);
        }
    }
    int ans1 = f();
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j) d[i][j] = 0;
            else d[i][j] = inf;
        }
    }
    for (int i = 1; i <= n; i++) {
        for (auto j : v1[i]) {
            int x = j.to, y = j.cost;
            string s = j.s1;
            d[i][x] = min(d[i][x], y * 2), d[x][i] = min(d[x][i], y * 2);
        }
    }
    int ans2 = f();
    if (ans1 + c*2 >= ans2) cout << "No";
    else cout << "Yes";
}