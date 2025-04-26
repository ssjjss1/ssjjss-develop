#include<bits/stdc++.h>
using namespace std;
int n, m;
bool visited[1004];
vector<pair<int,int>> v;


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    
    long long ans=1;
    for(int i=1;i<=m;i++){
          int l,r;
          cin>>l>>r;
          
          v.push_back({l,r});
    }
    
    reverse(v.begin(),v.end());
    
    for(auto [l,r]:v){
          bool flag=false;
          for(int i=l;i<=r;i++){
                if(!visited[i]){
                      visited[i]=1;
                      flag=true;
                }
          }
          
          if(flag) ans*=2;
    }
    
    cout<<ans;
   
}