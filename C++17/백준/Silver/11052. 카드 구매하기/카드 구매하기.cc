#include<iostream>
using namespace std;
int n;
int a[1004];
int dp[1004] = {0};
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        dp[i] = a[i];
    }
    for(int i = 1; i <= n; i++){
        for(int j = i; j <= n; j++){
            dp[j] = max(dp[j], dp[j-i] + a[i]);
        }
    }
    cout << dp[n];
}