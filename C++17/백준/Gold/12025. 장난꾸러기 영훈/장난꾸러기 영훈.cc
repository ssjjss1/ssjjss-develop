#include<iostream>
using namespace std;
string s;
long long n;
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> s >> n;
    int k = 0;
    for (auto& i : s) {
        if (i == '1' || i == '2' || i == '6' || i == '7') {
            if (i == '6') i = '1';
            else if (i == '7') i = '2';
            k += 1;
        }
    }
    if ((1LL << k) < n) {
        cout << -1;
        return 0;
    }
    n -= 1;
    for (int i = s.size() - 1; i >= 0; i--) {
        if (s[i] == '1' || s[i] == '2' || s[i] == '6' || s[i] == '7') {
            if (n % 2 == 1) {
                if (s[i] == '1') s[i] = '6';
                else if (s[i] == '2') s[i] = '7';
                else if (s[i] == '6') s[i] = '1';
                else if (s[i] == '7') s[i] = '2';
            }
            n /= 2;
        }
    }
    cout << s;
}