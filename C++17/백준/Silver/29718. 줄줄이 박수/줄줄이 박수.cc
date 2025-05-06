#include<bits/stdc++.h>
using namespace std;
int n,m,a;
int d[2004];
int main(){
      ios_base::sync_with_stdio(0);
      cin.tie(0);
      cin>>n>>m;
      
      for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                  int x;
                  cin>>x;
                  d[j]+=x;
            }
      }
      
      cin>>a;
      
      int sum=0, mx=0;
      for(int i=1;i<=m;i++){
            if(i<=a) sum+=d[i];
            else{
                  sum+=d[i];
                  sum-=d[i-a];
            }
            mx=max(mx, sum);
      }
      
      cout<<mx;
}