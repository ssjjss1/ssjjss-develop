#include<bits/stdc++.h>
using namespace std;
int n;
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for (long long i = 0; i <= 200000; i++) {
        long long j = sqrt(i * i + n);
        if (j * j - i * i == n) {
            cout << i << " " << j;
            return 0;
        }
    }
    cout << "impossible";
}