#include<bits/stdc++.h>
using namespace std;
int cnt1, cnt2;
vector<int> dp2(54, 0);

int f1(int n) {
      if (n == 1 || n == 2) {
            cnt1+=1;
            return 1;
      }
      return f1(n - 1) + f1(n - 2);
}

void f2(int n) {
      dp2[1] = dp2[2] = 1;
      for (int i = 3; i <= n; i++) {
            dp2[i] = dp2[i - 1] + dp2[i - 2];
            cnt2 += 1;
      }
}

int main() {
      ios_base::sync_with_stdio(0); cin.tie(0);
      int n;
      cin >> n;
      f1(n);
      f2(n);
      cout << cnt1 << " " << cnt2;
}