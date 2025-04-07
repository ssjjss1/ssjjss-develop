#include<bits/stdc++.h>
#define INF 2000004
using namespace std;
int n;
vector<bool> visited(INF+4);
vector<long long> num(INF+4);
int main(){
      ios_base::sync_with_stdio(0);
      cin.tie(0);
      
      cin>>n;
      for(int i=1;i<=n;i++){
            int x;
            cin>>x;
            num[x]+=1;
            for(int j=1;j*j<=x;j++){
                  if(!(x%j)) {
                        visited[j]=1;
                        visited[x/j]=1;
                  }
            }
      }
      
      long long mx=n;
      
      for(long long i=2;i<=INF;i++){
            if(visited[i]){
                  long long cnt=0;
                  for(int j=i;j<=INF;j+=i){
                      if(num[j]) cnt+=num[j];  
                  }
                  if(cnt>=2) mx=max(mx, cnt*i);
            }
      }
      
      cout<<mx;
}