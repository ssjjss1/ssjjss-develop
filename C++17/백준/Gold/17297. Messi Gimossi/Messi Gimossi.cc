#include<iostream>
using namespace std;
long long n;
long long dp[54];
string s = "Messi Gimossi";
void f(int x, int cnt) {
    if (cnt == 1 || cnt == 2) {
        if (x==6) cout << "Messi Messi Gimossi";
        else cout << s[x-1];
        return;
    }
    if (dp[cnt - 1] >= x) f(x, cnt - 1);
    else if (dp[cnt - 1] + 1 == x) {
        cout << "Messi Messi Gimossi";
        return;
    } 
    else f(x - dp[cnt - 1] - 1, cnt - 2);
}
int main() {
    cin >> n;
    dp[1] = 5, dp[2] = 13; 
    for (int i = 3; i < 54; i++) dp[i] = dp[i - 1] + dp[i - 2] + 1; 
    f(n, 53);
}