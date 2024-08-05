#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<int> v, v1;  
void f(int cnt) {
    if (cnt == m) {  
        for (int i = 0; i < m; i++) cout << v1[i] << " ";  
        cout << "\n";
        return;
    }
    for (int i = 0; i < n; i++) {
        v1.push_back(v[i]);
        f(cnt + 1); 
        v1.pop_back();  
    }
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    v.resize(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    sort(v.begin(), v.end()); 
    f(0);
}