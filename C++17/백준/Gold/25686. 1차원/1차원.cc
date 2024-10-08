#include <iostream>
#include <vector>
using namespace std;
int n;
vector<int> f(int x) {
    vector<int> v(x+4);
    if (x == 1) {
        v[0] = 1;
        return v;
    }
    vector<int> l = f((x + 1) / 2), r = f(x / 2);
    for (int i = 0; i < (x + 1) / 2; i++) v[i] = 2 * l[i] - 1;
    for (int i = (x + 1) / 2, j=0 ; i < x; i++, j++) v[i] = 2 * r[j];
    return v;
}
int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n;
    vector<int> ans = f(n);
    for (int i = 0; i < n; i++) cout << ans[i] << " ";
}