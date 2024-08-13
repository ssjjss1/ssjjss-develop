#include <iostream>
#include <vector>
using namespace std;
int n, ans;
vector<bool> v1, v2, v3; // 열, 대각선/, 대각선
void f(int x) {
if (x == n) {
  ans += 1;
  return;
}
for (int i = 0; i < n; i++) {
  if (!v1[i] && !v2[x - i + n - 1] && !v3[x + i]) {
    v1[i] = 1;
    v2[x - i + n - 1] = 1;
    v3[x + i] = 1;
    f(x + 1);
    v1[i] = 0;
    v2[x - i + n - 1] = 0;
    v3[x + i] = 0;
  }
}
}
int main() {
  ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  cin >> n;
  v1.resize(n, 0);
  v2.resize(2 * n - 1, 0);
  v3.resize(2 * n - 1, 0);
  f(0);
  cout << ans;
}