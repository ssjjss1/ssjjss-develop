#include<bits/stdc++.h>
using namespace std;
int n,m;
int main(){
      ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
      cin>>n>>m;
      while(m--){
            int k;cin>>k;
            int prev=1e9+7;
            for(int i=1,x;i<=k;i++){
                  cin>>x;
                  if(prev<x) {
                        cout<<"No";
                        return 0;
                  }
                  prev=x;
            }
      }
      cout<<"Yes";
}