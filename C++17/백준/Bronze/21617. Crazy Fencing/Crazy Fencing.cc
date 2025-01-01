#include<bits/stdc++.h>
using namespace std;
int n;
double d[10004];
int main() {
      ios::sync_with_stdio(0); cin.tie(0);
      cin >> n;
      for (int i = 0; i <= n; i++) cin >> d[i];
      double ans = 0;
      for (int i = 0; i < n; i++) {
            double w; cin >> w;
            ans += w * (d[i] + d[i + 1]) / 2.0;
      }
      cout << fixed << setprecision(8) << ans;
}