#include <bits/stdc++.h>
using namespace std;

void backTracking(map<char, int> &alpha, string cx, int cnt, int lim, set<string> &result) {
    if (cnt == lim) {
        result.insert(cx); 
        return;
    }
    for (auto &[a, c] : alpha) {
        if (c > 0) {
            alpha[a] -= 1;
            backTracking(alpha, cx + a, cnt + 1, lim, result);
            alpha[a] += 1;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;

        map<char, int> alpha;
        for (char ch : s) alpha[ch]++;

        set<string> res;
        backTracking(alpha, "", 0, s.size(), res);

        for (const string &i : res) cout << i << '\n';
    }
}