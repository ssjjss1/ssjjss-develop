#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int n;
int dp[2004][2004];
vector<int> v;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 0, x; i < n; i++) cin >> x, v.push_back(x);
    sort(v.begin(), v.end()); 
    int ans = 1; 
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            int l = v[i] - v[j];  
            dp[i][j] = 2; 
            for (int k = 0; k < j; k++) {
                if (v[j] - v[k] == l) { 
                    dp[i][j] = dp[j][k] + 1;  
                }
            }
            ans = max(ans, dp[i][j]);  
        }
    }
    cout << ans; 
}