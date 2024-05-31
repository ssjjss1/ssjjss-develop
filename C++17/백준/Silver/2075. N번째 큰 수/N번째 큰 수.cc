#include<iostream>
#include<queue>
using namespace std;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    priority_queue<int, vector<int>, greater<int>> q;
    for (int i = 1, x; i <= n * n; i++) {
        cin >> x;
        if (q.size() < n) {
            q.push(x);
        }
        else if (q.size() >= n && q.top() < x) {
            q.pop();
            q.push(x);
        }
    }
    cout << q.top();
}