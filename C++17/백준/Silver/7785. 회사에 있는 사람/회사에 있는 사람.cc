#include <bits/stdc++.h>
using namespace std;

int n;
unordered_set<string> ma;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        string s1, s2;
        cin >> s1 >> s2;
        if (s2 == "enter") ma.insert(s1);
        else ma.erase(s1);
    }

    vector<string> res(ma.begin(), ma.end());
    sort(res.rbegin(), res.rend());

    for (auto i : res) cout << i << '\n';
}