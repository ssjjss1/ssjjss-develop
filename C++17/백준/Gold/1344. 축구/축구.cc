#include<bits/stdc++.h>
using namespace std;
double n,m;
double dp[24][24][24];
bool check(int x){
    if(x<2) return 0;
    for(int i=2;i*i<=x;i++)if(!(x%i)) return 0;
    return 1;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m;
    dp[0][0][0]=1;
    n/=100, m/=100;
    for(int i=1;i<=18;i++){
        for(int j=0;j<=i;j++){
            for(int k=0;k<=i;k++){
                if(j!=0) dp[i][j][k]+=dp[i-1][j-1][k]*n*(1-m);
                if(k!=0) dp[i][j][k]+=dp[i-1][j][k-1]*(1-n)*m;
                if(j!=0&&k!=0) dp[i][j][k]+=dp[i-1][j-1][k-1]*n*m;
                dp[i][j][k]+=dp[i-1][j][k]*(1-n)*(1-m);
            }
        }
    }
    double sum=0;
    for(int i=0;i<=18;i++){
        for(int j=0;j<=18;j++){
            if(check(i)||check(j)) sum+=dp[18][i][j];
        }
    }
    cout<<fixed<<setprecision(20)<<sum;
}
//n: 확률1, m: 확률2
//