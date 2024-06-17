#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
ll n, m, cnt;
vector<int> v1;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  vector<bool> v(1e7 + 4, 0);
  for (int i = 2; i <= 1e7 + 1; i++) {
    if (!v[i]) {
      v1.push_back(i);
      for (int j = i * 2; j <= 1e7 + 1; j += i) {
        v[j] = 1;
      }
    }
  }
  cin >> n >> m;
  for (auto i : v1) {
    for (ll j = i; j <= m / i;) {
      j*=i;
      if (j >= n)
        cnt += 1;
    }
  }
  cout << cnt;
}