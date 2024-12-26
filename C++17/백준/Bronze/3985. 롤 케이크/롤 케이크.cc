#include<bits/stdc++.h>
using namespace std;
int mx,mx1,idx,idx1;
int main(){
      ios::sync_with_stdio(0);cin.tie(0);
      int l,n; cin>>l>>n;
      vector<int> visited(l+4,0);
      for(int i=1;i<=n;i++){
            int pi, ki;
            cin>>pi>>ki;
            int cnt=0;
            for(int j=pi;j<=ki;j++){
                  if(!visited[j]){
                        cnt+=1;
                        visited[j]=1;
                  }
            }
            if(mx1<ki-pi) mx1=ki-pi, idx1=i;
            if(mx<cnt) mx=cnt, idx=i;
      }
      cout<<idx1<<"\n"<<idx;
}