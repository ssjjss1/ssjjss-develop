#include <iostream>
using namespace std;
const int inf = 1000000;
int d[inf + 1];
int n;
int main() {
  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  for (int i = 2; i * i <= inf; i++) {
    if (d[i] == 0) {
      for (int j = i * i; j <= inf; j += i) {
        d[j] = 1;
      }
    }
  }
  while (1) {
    cin >> n;
    if (n == 0) break;
    bool flag = false;
    for (int i = 3; i <= n; i += 2) {
      if (d[i] == 0 && d[n - i] == 0) {
        cout << n << " = " << i << " + " << n - i << "\n";
        flag = true;
        break;
      }
    }
    if (!flag) cout << "Goldbach's conjecture is wrong.\n";
  }
}