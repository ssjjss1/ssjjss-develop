#include<bits/stdc++.h>
using namespace std;
int n,q;
int main(){
      ios_base::sync_with_stdio(0);
      cin.tie(0);
      
      cin>>n>>q;
      
      for(int i=1;i<=q;i++){
            int x,y;
            cin>>x>>y;
            
            int mn = min(min(x - 1, y - 1), min(n - x, n - y));
            cout <<  mn % 3 + 1 << "\n";
      }
}