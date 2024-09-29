#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> v[1000004];
int dp[1000004][4];
bool visited[1000004];
int n;
void f(int x) {
    visited[x] = 1;
    dp[x][0] = 0, dp[x][1] = 1;
    for (int i : v[x]) {
        if (!visited[i]) {
            f(i);
            dp[x][0] += dp[i][1];
            dp[x][1] += min(dp[i][0], dp[i][1]);
        }
    }
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1,x,y; i < n; i++) {
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    f(1);
    cout << min(dp[1][0], dp[1][1]);
}