#include<bits/stdc++.h>
using namespace std;
int n;
int main(){
      ios_base::sync_with_stdio(0);
      cin.tie(0);
      
      cin>>n;
      for(int i=0;i<2*n-1;i++){
            int x;
            if(i%2){
                  for(int j=0;j<n;j++){
                        cin>>x;
                  }
            } else{
                  for(int j=0;j<n-1;j++){
                        cin>>x;
                  }
            }
      }
      
      cout<<2*(n-1)<<" "<<1+2*(n-2);
}