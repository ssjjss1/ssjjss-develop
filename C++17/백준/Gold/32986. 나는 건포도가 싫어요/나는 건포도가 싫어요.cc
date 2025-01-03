#include<bits/stdc++.h>
using namespace std;
int a,b,c;
int main(){
      ios::sync_with_stdio(0);
      cin.tie(0);
      cin>>a>>b>>c;
      if(a==3&b==3&&c==3) cout<<0;
      else{
            int mn=min({a,b,c});
          cout<<mn/2+mn%2-1;
      }
}