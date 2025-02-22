#include<bits/stdc++.h>
using namespace std;
string s;

int check(int idx, int n){
      
      int res=0;
      for(int i=0;i<n;i++){
            if(idx%3==1&&s[i]=='K') res+=1, idx+=1;
            else if(idx%3==2&&s[i]=='S') res+=1, idx+=1;
            else if(idx%3==0&&s[i]=='A') res+=1, idx+=1;
      }
      return res;
}

int main(){
      ios_base::sync_with_stdio(0);
      cin.tie(0);
      cin>>s;
      
      int ans=1e9+7, n=s.size();
      int idx=1;
      int ksa=check(idx,n);
      ans=min(ans, 2*(n-ksa));
      
      idx=2;
      int sak=check(idx,n);
      if(sak<n) ans=min(ans, 2*(n-sak));
      
      idx=0;
      int aks=check(idx,n);
      if(aks<n-1) ans=min(ans, 2*(n-aks));
      
      cout<<ans;
}