#include<iostream>
using namespace std;
long long n,idx=1,cnt=1;
int main(){
      ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
      cin>>n;
      if(n==0){
            cout<<0;
            return 0;
      }
      if(n==1){
            cout<<1;
            return 0;
      }
      while(true){
            if(idx*2<n){
                  idx*=2;
                  cnt+=1;
            }
            else {
                  cnt+=1;
                  break;
            }
      }
      cout<<cnt;
}