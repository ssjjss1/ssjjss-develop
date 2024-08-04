#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> v[3001];
int visited[3001], d[3001], p[3001];
bool c[3001];
bool flag = 0;
void f(int x, int y) {
    visited[x] = 1;
    p[x] = y;
    for (int i : v[x]) {
        if (!visited[i]) {
            f(i, x);
            if (flag) return;
        }
        else if (i != y && !flag) {  
            flag = true;
            int xx = x;
            c[xx] = 1;
            while (xx != i) {
                xx = p[xx];
                c[xx] = 1;
            }
            return;
        }
    }
}
void g() {
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (c[i]) {
            d[i] = 0;
            q.push(i);
        }
        else d[i] = -1;
    }
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        for (auto i : v[x]) {
            if (d[i] == -1) {
                d[i] = d[x] + 1;
                q.push(i);
            }
        }
    }
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 0, x, y; i < n; i++) {
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    f(1, 0);
    g();
    for (int i = 1; i <= n; i++) cout << d[i] << ' ';
}