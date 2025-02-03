#include<bits/stdc++.h>
using namespace std;
int n,m;
vector<string> v;
int main(){
      ios_base::sync_with_stdio(0);cin.tie(0);
      cin>>n>>m;
      for(int i=1;i<=n;i++){
            string s;
            cin>>s;
            v.push_back(s);
      }
      
      sort(v.begin(),v.end());
      cout<<v[m-1];
}