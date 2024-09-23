#include<iostream>
using namespace std;
typedef long long ll;
ll dp[54];
ll n,u,v,idx;
string s1, s2;
string f(int cnt, int x){
      if(x==1||x==0) return "";
      else if(dp[cnt-2]+1>=x) return "L"+f(cnt-2, x-1);
      else return "R"+f(cnt-1,x-dp[cnt-2]-1);
}
int main(){
      ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
      cin>>n>>u>>v;
      if(u==v) return 0;
      dp[0]=dp[1]=1;
      for(int i=2;i<=n;i++) dp[i]=dp[i-1]+dp[i-2]+1;
      s1=f(n,u), s2=f(n,v);
      // cout<<s1<<" "<<s2<<"\n";
      int mn=min(s1.size(),s2.size());
      for(int i=0;i<mn;i++){
            if(s1[i]!=s2[i]){
                  idx=i;
                  break;
            }
            if(i==mn-1) idx=i+1;
      }
      for(int i=idx;i<s1.size();i++) cout<<"U";
      for(int i=idx;i<s2.size();i++) cout<<s2[i];
}