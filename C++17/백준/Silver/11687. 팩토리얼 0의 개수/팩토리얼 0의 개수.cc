#include<bits/stdc++.h>
using namespace std;
long long m,ans=-1;
int main(){
      ios_base::sync_with_stdio(0); cin.tie(0);
      cin>>m;
      long long l=5, r=1e10+7;
      while(l<=r){
            long long middle=(l+r)/2;
            long long cnt=5,sum=0;
            for(int i=1;cnt<=middle;i++){ 
                  sum+=middle/cnt;
                  cnt*=5;
            }
            if(sum<m) l=middle+1;
            else {
                if(sum==m) ans=middle;
                r=middle-1;
            }
      }
      cout<<ans;
}