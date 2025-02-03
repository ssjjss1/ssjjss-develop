#include<bits/stdc++.h>
using namespace std;
string s;
int n;

int main(){
      ios_base::sync_with_stdio(0); cin.tie(0);
      cin >> s >> n;
      int ans = 0, idx = 1;
      for (int i = s.size() - 1; i >= 0; i--) {
            if ('A' <= s[i] && s[i] <= 'Z') {
                  ans += ((s[i] - 'A') + 10) * idx;
            } else {
                  ans += (s[i] - '0') * idx;
            }
            idx *= n;
      }
      cout << ans;
}