#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int n;
int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  cin >> n;
  vector<int> v(34, 0);
  for (int i = 1; i <= n; i++) {
    string s;
    cin >> s;
    int cnt = 1;
    for (int j = s.size() - 1; j >= 0; j--) {
      v[s[j] - 'A'] += cnt;
      cnt *= 10;
    }
  }
  vector<int> v1;
  for (int i = 0; i < 26; i++) if (v[i] > 0) v1.push_back(v[i]);
  sort(v1.begin(),v1.end(),greater<>());
  int t = 9, sum = 0;
  for (auto i : v1) {
    sum += i * t;
    t -= 1;
  }
  cout << sum;
}