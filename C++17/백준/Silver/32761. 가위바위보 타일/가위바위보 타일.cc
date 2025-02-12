#include<bits/stdc++.h>
using namespace std;
int main(){
      ios_base::sync_with_stdio(0); 
      cin.tie(0);
      int n, ans=1e9+7;
      string s;
      cin>>n>>s;
      // SPR반복
      int idx=0;
      for(int i=0;i<n;i++){
            if(idx%3==0&&s[i]=='S') idx+=1;
            else if(idx%3==1&&s[i]=='P') idx+=1;
            else if(idx%3==2&&s[i]=='R') idx+=1;
      }
      ans=min(ans, n-(idx-idx%3));
      // PRS반복
      idx=0;
      for(int i=0;i<n;i++){
            if(idx%3==0&&s[i]=='P') idx+=1;
            else if(idx%3==1&&s[i]=='R') idx+=1;
            else if(idx%3==2&&s[i]=='S') idx+=1;
      }
      ans=min(ans, n-(idx-idx%3));
      // RPS반복
      idx=0;
      for(int i=0;i<n;i++){
            if(idx%3==0&&s[i]=='R') idx+=1;
            else if(idx%3==1&&s[i]=='S') idx+=1;
            else if(idx%3==2&&s[i]=='P') idx+=1;
      }
      ans=min(ans, n-(idx-idx%3));
      cout<<ans;
}