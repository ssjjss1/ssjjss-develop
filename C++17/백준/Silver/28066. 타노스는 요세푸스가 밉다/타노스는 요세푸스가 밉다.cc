#include <bits/stdc++.h>
using namespace std;
int n, k;
deque<int> dq;
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> k;
    for (int i = 1; i <= n; i++) dq.push_back(i);
    while (dq.size() > 1) {
        int x = dq.front();
        dq.pop_front();
        for (int i = 1; i < k && !dq.empty(); i++) {
            dq.pop_front();
        }
        dq.push_back(x);
    }
    cout << dq.front();
}