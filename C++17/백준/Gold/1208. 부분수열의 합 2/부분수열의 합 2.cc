#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, s;
long long a[41];
vector<long long> v1, v2;
void f(int s, int e, vector<long long>& ss) {
    int size = e - s;
    for (int i = 0; i < (1 << size); i++) {
        long long sum = 0;
        for (int j = 0; j < size; j++) {
            if (i & (1 << j)) {
                sum += a[s + j];
            }
        }
        ss.push_back(sum);
    }
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> s;
    for (int i = 0; i < n; i++) cin >> a[i];
    f(0, n / 2, v1);
    f(n / 2, n, v2);
    sort(v2.begin(), v2.end());
    long long cnt = 0;
    for (auto i : v1) cnt += upper_bound(v2.begin(), v2.end(), s - i) - lower_bound(v2.begin(), v2.end(), s - i);
    if (s == 0) cnt -= 1;
    cout << cnt;
}