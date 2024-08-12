#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, mx;
void f(vector<int> &v, int sum) {
    if (v.size() == 3) {
        mx = max(mx, sum+v[0]*v[2]);
        return;
    }
    vector<int> v1 = v;
    for (int i = 1; i < v.size() - 1; i++) {
        int k = v[i - 1] * v[i + 1];
        v.erase(v.begin() + i);
        f(v, sum + k); 
        v=v1;
    }
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    vector<int> v;
    for (int i = 0, x; i < n; i++) cin >> x, v.push_back(x);
    f(v, 0);
    cout << mx;
}