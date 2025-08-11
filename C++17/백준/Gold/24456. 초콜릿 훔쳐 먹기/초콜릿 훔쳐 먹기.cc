#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    long long n, m, k;
    cin >> n >> m >> k;

    long long diff = abs(n - m);
    long long total = n * m;

    for (long long i = total - 1; i >= 2; i--) {
        bool flag = false;

        for (long long j = 1; j * j <= i; j++) {
            if (i % j == 0) {
                long long a = i / j;
                long long nDiff = abs(j - a);
                if (abs(nDiff - diff) <= k) {
                    flag = true;
                    break;
                }
            }
        }

        if (!flag) { 
            cout << (total - i - 1);
            return 0;
        }
    }

    cout << total - 1; 
}