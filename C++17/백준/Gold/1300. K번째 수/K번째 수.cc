#include<bits/stdc++.h>
using namespace std;
long long n, k;
int main(){
      ios_base::sync_with_stdio(0); cin.tie(0);
      cin >> n >> k;
      
      long long l = 1, r = n * n, ans;
      while (l <= r) {
            long long middle = (l + r) / 2;
            long long sum = 0;
            for (long long i = 1; i <= n; i++) {
                  sum += min(middle / i, (long long)n);
            }
            if (sum < k) {
                  l = middle + 1;
            } else {
                  ans = middle;
                  r = middle - 1;
            }
      }
      cout << ans;
}