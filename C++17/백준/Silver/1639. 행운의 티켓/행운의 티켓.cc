#include<bits/stdc++.h>
using namespace std;
string s;
long long sum[11004];

int main(){
      ios_base::sync_with_stdio(0);
      cin.tie(0);
      cin>>s;
      int n=s.size();
      
      for(int i=1;i<=n;i++){
            sum[i]=(s[i-1]-'0')+sum[i-1];
      }

      for(int i=n/2;i>=1;i--){
            for(int j=1;j<=n-2*i+1;j++){
                  if(sum[j+i-1]-sum[j-1]==-sum[j+i-1]+sum[j+2*i-1]){
                        cout<<2*i;
                        return 0;
                  }
            }
      }
      
      cout<<0;
}