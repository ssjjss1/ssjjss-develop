#include <iostream>
#include <vector>
using namespace std;
int n, k, cnt;
bool flag = 0;
void f(int sum, vector<int>& v) {
    if (sum == n) {
        cnt += 1; 
        if (cnt == k) { 
            for (int i = 0; i < v.size(); i++) {
                cout << v[i];
                if (i != v.size() - 1) cout << "+";
            }
            flag = 1; 
        }
        return;
    }
    for (int i = 1; i <= 3; i++) {
        if (sum + i <= n) { 
            v.push_back(i);
            f(sum + i, v);
            v.pop_back(); 
            if (flag) return; 
        }
    }
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> k;
    vector<int> v;
    f(0, v);
    if (!flag) cout << -1;
}