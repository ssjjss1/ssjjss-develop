#include<bits/stdc++.h>
using namespace std;
int n;
int d[300004];
int main(){
      ios_base::sync_with_stdio(0);
      cin.tie(0);
      
      cin>>n;
      int cnt=1;
      for(int i=1;i<=n;i++){
            cin>>d[i];
      }
      
      int prev=d[1];
      for(int i=2;i<=n;i++){
            if(prev%2&&d[i]%2==0){
                  prev=d[i];
                  cnt+=1;
            } else if(prev%2==0&&d[i]%2){
                  prev=d[i];
                  cnt+=1;
            }
      }
      cout<<cnt;
}