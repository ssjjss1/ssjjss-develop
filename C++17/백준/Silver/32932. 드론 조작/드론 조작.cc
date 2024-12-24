#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int N, K; cin >> N >> K;
    set<pair<int, int>> obs;
    for (int i = 0; i < N; i++) {
        int x, y; cin >> x >> y;
        obs.insert({x, y});
    }
    string s; cin >> s;
    int x = 0, y = 0;
    for (auto i : s) {
        int nx = x, ny = y;
        if (i == 'U') ny++;
        else if (i == 'D') ny--;
        else if (i == 'R') nx++;
        else if (i == 'L') nx--;
        if (obs.find({nx, ny}) == obs.end()) {
            x = nx; y = ny;
        }
    }
    cout << x << " " << y ;
}