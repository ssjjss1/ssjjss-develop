#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int f(vector<int>& v, int cnt, int sum, int n) {
    if (cnt == n) return sum;
    if (v[cnt] > sum) return sum;
    return f(v, cnt + 1, sum + v[cnt], n);
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    sort(v.begin(), v.end());
    int ans = f(v, 0, 1, n);
    cout << ans;
}