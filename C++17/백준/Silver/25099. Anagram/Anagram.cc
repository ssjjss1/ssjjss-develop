#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n;
    cin >> n;

    vector<string> ans;
    unordered_set<string> used;

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;

        string sorted_s = s;
        sort(sorted_s.begin(), sorted_s.end());

        if (used.find(sorted_s) == used.end()) {
            used.insert(sorted_s);
            ans.push_back(s);
        }
    }

    for (auto i : ans) cout << i << '\n';
}