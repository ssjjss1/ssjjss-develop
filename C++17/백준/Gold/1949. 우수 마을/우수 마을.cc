#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n;
int a[10001];
int dp[10001][2];
vector<int> v[10001];
bool visited[10001];
void f(int x) {
    visited[x] = true;
    dp[x][1] = a[x];
    for (int i : v[x]) {
        if (!visited[i]) {
            f(i);
            dp[x][0] += max(dp[i][0], dp[i][1]);
            dp[x][1] += dp[i][0];
        }
    }
}
int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1, x, y; i < n; ++i) {
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    f(1);
    cout << max(dp[1][0], dp[1][1]);
}