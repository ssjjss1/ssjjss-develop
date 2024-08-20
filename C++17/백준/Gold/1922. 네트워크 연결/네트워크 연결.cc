#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int n, m;
int d[1004];
int f(int x) {
    if (x == d[x]) return x;
    return d[x] = f(d[x]);
}
void g(int a, int b) {
    a = f(a), b = f(b);
    if (a != b) d[b] = a;
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)  d[i] = i;
    vector<pair<int, pair<int, int>>> v;
    for (int i = 1; i <= m; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        v.push_back({ z, {x, y} });
    }
    sort(v.begin(), v.end());
    int w = 0;
    for (int i = 0; i < m; i++) {
        int c = v[i].first, x = v[i].second.first, y = v[i].second.second;
        if (f(x) != f(y)) {
            g(x, y);
            w += c;
        }
    }
    cout << w;
}