#include<bits/stdc++.h>
using namespace std;
const int MOD=1000000007;
vector<long long> d1(1000004,0),d2(1000004,0);
int main(){
      ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
      d1[1]=7, d2[1]=3;
      for(int i=2;i<=1000000;i++) {
            d1[i]=(d1[i-1]*3+d2[i-1]*4)%MOD;
            d2[i]=(d1[i-1]+d2[i-1]*2)%MOD; 
      }
      int t; cin>>t;
      while(t--){
            int x; cin>>x;
            cout<<d1[x]<<"\n";
      }
}