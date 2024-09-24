#include<iostream>
using namespace std;
int main() {
    ios::sync_with_stdio(0);cin.tie(0);
    string s;
    cin >> s;
    int n = s.size();
    bool flag = 1;
    for (int i = 0; i < n / 2; i++) {
        if (s[i] != s[n - i - 1]) {
            flag = 0;
            break;
        }
    }
    if (!flag) cout << n;
    else {
        bool flag2 = 1;
        for (int i = 1; i < n; i++) {
            if (s[i] != s[0]) {
                flag2 = 0;
                break;
            }
        }
        if (flag2) cout << -1;
        else cout << n - 1;
    }
}