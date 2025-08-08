#include<bits/stdc++.h>
#define INF 1000000000
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m, a, b;
    cin >> n >> m >> a >> b;

    vector<int> obs(n+4, 0);
    for(int i=1;i<=m;i++){
        int l,r;
        cin>>l>>r;

        obs[l]+=1;
        obs[r+1]+=-1;
    }

    for(int i=1;i<=n;i++){
        obs[i]+=obs[i-1];
    }

    vector<int> dp(n+4, INF);
    dp[0]=0;
    for(int i=1;i<=n;i++){
        if(obs[i]==0){
            if(i-a >= 0 && obs[i-a]==0 && dp[i-a]!=INF){
                dp[i] = min(dp[i], dp[i-a] + 1);
            }
            if(i-b >= 0 && obs[i-b]==0 && dp[i-b]!=INF){
                dp[i] = min(dp[i], dp[i-b] + 1);
            }
        }
    }

    cout << (dp[n]==INF ? -1 : dp[n]);
}