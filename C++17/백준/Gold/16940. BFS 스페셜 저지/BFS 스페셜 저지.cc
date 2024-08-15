#include <iostream>
#include <vector>
#include <queue>
#include<algorithm>
using namespace std;
vector<int> v[100004];
vector<int> v1;
int d[100004];
bool visited[100004];
bool f(int n) {
    queue<int> q;
    q.push(1);
    visited[1] = 1;
    int cnt = 0;
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        if (v1[cnt] != x) return 0;
        cnt+=1;
        for (int i : v[x]) {
            if (!visited[i]) {
                visited[i] = 1;
                q.push(i);
            }
        }
    }
    return 1;
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int x, y;
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    v1.resize(n+4);
    for (int i = 0; i < n; i++) {
        cin >> v1[i];
        d[v1[i]] = i;
    }
    for (int i = 1; i <= n; i++) sort(v[i].begin(), v[i].end(), [](int a, int b) {return d[a] < d[b];});
    if (f(n)) cout << 1;
    else cout << 0;
}