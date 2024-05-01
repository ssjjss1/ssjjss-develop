#include <iostream>
using namespace std;
int dp[1000001][11];
int n, m, k;
int mx = 0;
bool h(string s){
  int cnt=0;
  int cnt1=0;
  for(int i=0;i<s.size();i++){
    if(s[i]!='0') cnt+=1;
    else cnt1+=1;
  }
  if(cnt<=1&&cnt1<=1) return 1;
  else return 0;
}
bool g(string s) {
  for (int i = 0; i < s.size() - 1; i++) {
    if (s[i] < s[i + 1])
      return false;
  }
  return true;
}
void f(int cnt, string s) {
  if (cnt == m) {
    mx = max(mx, stoi(s));
    return;
  }
  int &ref = dp[stoi(s)][cnt];
  if (ref)
    return;
  ref = 1;
  for (int i = 0; i < k - 1; i++) {
    for (int j = i + 1; j < k; j++) {
      if (i != j || i != 0 && j != 0) {
        if (s[i] <= s[j] || g(s)) {
          swap(s[i], s[j]);
          f(cnt + 1, s);
          swap(s[i], s[j]);
        }
      }
    }
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m;
  string s;
  s = to_string(n), k = s.size();
  if (h(s)) {
    cout << -1;
    return 0;
  }
  f(0, s);
  cout << mx;
}