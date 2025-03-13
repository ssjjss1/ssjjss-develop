#include<bits/stdc++.h>
using namespace std;
int t;
int main(){
      ios_base::sync_with_stdio(0);
      cin.tie(0);
      cin>>t;
      while(t--){
            int n;
            cin>>n;
            long long mn=0;
            for(int i=1;i<=n;i++){
                  int x;
                  cin>>x;
                  if(x-mn==1) mn=x+1;
                  else mn+=1;
            }
            cout<<mn<<"\n";
      }
}