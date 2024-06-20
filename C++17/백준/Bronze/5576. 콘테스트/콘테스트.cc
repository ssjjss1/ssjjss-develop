#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    priority_queue<int, vector<int>, less<int>> q1;
    priority_queue<int, vector<int>, less<int>> q2;
    for (int i = 1, x; i <= 20; i++) {
        cin >> x;
        if (i <= 10)  q1.push(x);
         else q2.push(x);
    }
    int sum1 = 0, sum2 = 0;
    for (int i = 1; i <= 3; i++) {
            sum1 += q1.top();
            q1.pop();
            sum2 += q2.top();
            q2.pop();
    }
    cout << sum1 << " " << sum2;
}