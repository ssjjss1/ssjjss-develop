#include<bits/stdc++.h>
using namespace std;
int n;
map<char, int> ma;
int main(){
      ios::sync_with_stdio(0);cin.tie(0);
      cin>>n;
      for(int i=1;i<=n;i++) {
            char c; cin>>c;
            ma[c]+=1;
      }
      int mx=0;
      char ans;
      for(auto [chr, cnt]:ma){
            if(mx<cnt) ans=chr, mx=cnt;
      }
      cout<<ans<<" "<<mx;
}