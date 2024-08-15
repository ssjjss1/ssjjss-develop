#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    long long t, a, b;
    cin >> t;
    cin >> a;
    vector<long long> A(a + 4, 0);
    for (int i = 1; i <= a; i++) cin >> A[i], A[i] += A[i - 1];
    cin >> b;
    vector<long long> B(b + 4, 0);
    for (int i = 1; i <= b; i++) cin >> B[i], B[i] += B[i - 1];
    vector<long long> v1, v2;
    for (int i = 1; i <= a; i++) {
        for (int j = i; j <= a; j++) {
            v1.push_back(A[j] - A[i - 1]);
        }
    }
    for (int i = 1; i <= b; i++) {
        for (int j = i; j <= b; j++) {
            v2.push_back(B[j] - B[i - 1]);
        }
    }
    sort(v2.begin(), v2.end());
    long long cnt = 0;
    for (auto i : v1) cnt += upper_bound(v2.begin(), v2.end(), t - i) - lower_bound(v2.begin(), v2.end(), t - i);
    cout << cnt;
}