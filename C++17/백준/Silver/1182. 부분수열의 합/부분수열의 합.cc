#include <iostream>
#include <vector>
using namespace std;
int n, s;
vector<int> v;
int cnt;
void f(int x, int sum) {
    if (x == n) {
        if (sum == s) cnt++;
        return;
    }
    f(x + 1, sum);
    f(x + 1, sum + v[x]);
}
int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> s;
    v.resize(n+1);
    for (int i = 0; i < n; i++) cin >> v[i];
    f(0, 0);
    if (s == 0) cnt-=1;
    cout << cnt;
}