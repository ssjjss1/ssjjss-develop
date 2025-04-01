#include<bits/stdc++.h>
using namespace std;
int n;
int main(){
      ios_base::sync_with_stdio(0);
      cin.tie(0);
      cin>>n;
      int mx=0, cnt=1;
      
      for(int i=1;i<=n;i++){
            int x;
            cin>>x;
            if(x>cnt){
                  cnt+=1;
                  if(mx<cnt) mx=cnt;
            } else cnt=x;
      }
      cout<<mx;
}