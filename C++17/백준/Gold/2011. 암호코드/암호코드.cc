#include<iostream>
using namespace std;
const int mod=1000000;
int dp[5001];
string s;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>s;
    int n=s.size();
    if(s[0]=='0'){
        cout<<0<<'\n';
        return 0;
    }
    dp[0]=1;
    dp[1]=1;
    for(int i=2;i<=n;i++){
        int l=s[i-1]-'0';
        int r=(s[i-2]-'0')*10+l;
        if(l>=1&&l<=9)dp[i]=(dp[i]+dp[i-1])%mod;
        if(r>=10&&r<=26)dp[i]=(dp[i]+dp[i-2])%mod;
    }
    cout<<dp[n];
}