#include <iostream>
#include <vector>
using namespace std;
int n, k;
int dp[104][100004];
struct P {
    int a, b, c, d;
};
vector<P> v;
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> k;
    v.push_back({0,0,0,0});
    for (int i = 1, x1, y1, x2, y2; i <= n; i++) {
        cin >> x1 >> y1 >> x2 >> y2;
        v.push_back({x1,y1,x2,y2});
    }
    int mx = 0;
    dp[1][v[1].a]=v[1].b;
    dp[1][v[1].c]=max(dp[1][v[1].c],v[1].d);
    for (int i = 2; i <= n; i++) {
        for (int j = 0; j <= k; j++) {
            if (dp[i - 1][j]) {
                if (j + v[i].a <= k) {
                    dp[i][j + v[i].a] = max(dp[i][j + v[i].a], v[i].b + dp[i - 1][j]);
                }
                if (j + v[i].c <= k) {
                    dp[i][j + v[i].c] = max(dp[i][j + v[i].c], v[i].d + dp[i - 1][j]);
                }
            }
        }
    }
    for (int j = 0; j <= k; j++) mx = max(mx, dp[n][j]);
    cout << mx;
}