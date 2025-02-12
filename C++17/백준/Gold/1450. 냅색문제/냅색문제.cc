#include <bits/stdc++.h>
using namespace std;
long long n, c;

vector<long long> sub(int c, vector<long long> v) {
      vector<long long> res;
      int limit = v.size();
      for (int i = 0; i < (1 << limit); i++) {
            long long sum = 0;
            for (int j = 0; j < limit; j++) {
                  if ((1 << j) & i) sum += v[j];
            }
            if (sum <= c) res.push_back(sum);
      }
      return res;
}

void MITM(int c, vector<long long> v) {
      int size = v.size();
      vector<long long> v1 = sub(c, vector<long long>(v.begin(), v.begin() + size / 2));
      vector<long long> v2 = sub(c, vector<long long>(v.begin() + size / 2, v.end()));

      sort(v2.begin(), v2.end());
      long long ans = 0;

      for (long long x : v1) {
            ans += upper_bound(v2.begin(), v2.end(), c - x) - v2.begin();
      }

      cout << ans;
}

int main() {
      ios_base::sync_with_stdio(0);
      cin.tie(0);
      cin >> n >> c;

      vector<long long> v(n);
      for (int i = 0; i < n; i++) {
            cin >> v[i];
      }

      MITM(c, v);
}