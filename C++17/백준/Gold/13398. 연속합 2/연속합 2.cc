#include <iostream>
#include <algorithm>
using namespace std;
int n;
int d[100004], dp1[100004], dp2[100004];
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> d[i];
    dp1[1] = d[1];
    dp2[1] = 0;  
    int ans = d[1];
    for (int i = 2; i <= n; i++) {
        dp1[i] = max(dp1[i - 1] + d[i], d[i]);
        dp2[i] = max(dp1[i - 1], dp2[i - 1] + d[i]);
        ans = max({ ans, dp1[i], dp2[i] });
    }
    cout << ans;
}