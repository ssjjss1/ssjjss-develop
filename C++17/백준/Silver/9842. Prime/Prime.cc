#include<bits/stdc++.h>
using namespace std;
int n;
int d[200004];
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for (int i = 2; i <= 123456; i++) {
        if (!d[i]) {
            for (int j = i * 2; j <= 123456; j += i) d[j] = 1;
        }
    }
    int cnt = 0;
    for (int i = 2; i <= 123456; i++) {
        if (!d[i]) {
            if (cnt + 1 == n) {
                cout << i;
                return 0;
            }
            cnt += 1;
        }
    }
}