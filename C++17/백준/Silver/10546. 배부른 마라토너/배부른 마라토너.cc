#include<bits/stdc++.h>
using namespace std;
map<string, int> ma;
int main(){
      ios::sync_with_stdio(0);cin.tie(0);
      int n; cin>>n;
      for(int i=1;i<=2*n-1;i++){
            string s; cin>>s;
            ma[s]+=1;
      }
      for(auto [name, cnt]:ma){
            if(cnt%2) {
                  cout<<name;
                  break;
            }
      }
}