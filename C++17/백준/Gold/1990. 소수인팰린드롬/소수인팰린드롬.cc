#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<algorithm>
using namespace std;
int n, m;
vector<bool> v;
queue<int> q;
int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  cin >> n >> m;
  v.resize(m+1);
  if(m>=10000000) m=10000000;
  for (int i = 2; i <= m; i++){
    if (!v[i]) {
      if(i>=n) q.push(i);
      for (int j = i * 2; j <= m; j += i) {
        v[j] = 1;
      }
    }
  }
  while(q.size()) {
    int x=q.front();
    q.pop();
    string s = to_string(x);
    string s1 = to_string(x);
    reverse(s.begin(), s.end());
    if (s == s1) cout << s << "\n";
  }
  cout << -1;
}