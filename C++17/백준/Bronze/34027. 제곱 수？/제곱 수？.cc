#include<bits/stdc++.h>
using namespace std;
int t;
const int INF=1e9;
vector<bool> v(INF+4,0);
int main(){
      ios_base::sync_with_stdio(0);
      cin.tie(0);
      
      for(int i=1;i*i<=INF;i++){
            v[i*i]=1;
      }
      
      cin>>t;
      while(t--){
            int n;
            cin>>n;
            
            cout<<(v[n]?1:0)<<"\n";
      }
}