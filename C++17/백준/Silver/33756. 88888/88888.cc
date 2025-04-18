#include <bits/stdc++.h>
using namespace std;

vector<long long> v;
bool flag;

void init() {
    long long num = 8;
    while (num <= 1e18) {
        v.push_back(num);
        num = num * 10 + 8;
    }
    sort(v.begin(), v.end(), greater<>());
}

void dfs(int cnt, long long re) {
    if (flag || cnt > 8) return;
    if (re == 0) {
        flag = true;
        return;
    }
    for (auto i : v) {
        if (i <= re)
            dfs(cnt + 1, re - i);
        if (flag) return;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    init();

    int t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        flag = false;
        
        dfs(0, n);
        
        cout << (flag ? "Yes\n" : "No\n");
    }
}