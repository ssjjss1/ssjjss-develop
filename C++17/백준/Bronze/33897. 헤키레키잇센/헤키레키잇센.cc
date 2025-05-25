#include<bits/stdc++.h>
using namespace std;
int n;
int main(){
      ios_base::sync_with_stdio(0);
      cin.tie(0);
      
      cin>>n;
      int prev=-1, ans=0, mxCnt=0, cnt=0;
      for(int i=1;i<=n;i++){
            int x;
            cin>>x;
            if(prev<=x) {
                  cnt+=1;
                  prev=x;
            } else{
                  mxCnt=max(mxCnt, cnt);
                  ans+=1;
                  cnt=1;
                  prev=x;
            }
      }
      
      mxCnt=max(mxCnt, cnt);
      ans+=1;
      
      cout<<ans<<" "<<mxCnt;
}