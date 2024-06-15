#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
string s;
int a[51];
void f(int x) {
  cout << "1";
  for (int i = 1; i < x; i++)
    cout << "0";
  cout << "1";
}
void g(int x) {
  while (true) {
    if (a[x] + 1 < 10) {
      a[x] += 1;
      break;
    }
    a[x] = 0;
    x--;
  }
  if (s.size() % 2) {
    string s1 = "", s2 = "";
    for (int i = 0; i < s.size() / 2; i++) {
      s1 += to_string(a[i]);
    }
    s2 = s1;
    reverse(s2.begin(), s2.end());
    s1 += to_string(a[s.size() / 2]) + s2;
    cout << s1;
  } else {
    string s1 = "", s2 = "";
    for (int i = 0; i < s.size() / 2; i++) {
      s1 += to_string(a[i]);
    }
    s2 = s1;
    reverse(s2.begin(), s2.end());
    s1 += s2;
    cout << s1;
  }
}
int main() {
  ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  cin >> s;
  int n = s.size();
  for (int i = 0; i < n; i++) a[i] = s[i] - '0';
  if(s.size()==1&&a[0]<9){
    cout<<a[0]+1;
    return 0;
  }
  if (string(n, '9') == s) {
    f(n);
    return 0;
  }
  if (n % 2) {
    string s1 = "", s2 = "";
    for (int i = 0; i < n / 2; i++)s1 += s[i];
    s2 = s1;
    reverse(s2.begin(), s2.end());
    s1 += s[n / 2] + s2;
    if (s1 > s) cout << s1;
    else g(n / 2);

  } else {
    string s1 = "", s2 = "";
    for (int i = 0; i < n / 2; i++) s1 += s[i];
    s2 = s1;
    reverse(s2.begin(), s2.end());
    s1 += s2;
    if (s1 > s) cout << s1;
    else g(n / 2 - 1);
  }
}