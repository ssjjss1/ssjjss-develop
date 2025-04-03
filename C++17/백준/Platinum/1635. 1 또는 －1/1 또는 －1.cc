#include<bits/stdc++.h>
using namespace std;
int n,m;
int main(){
      ios_base::sync_with_stdio(0);
      cin.tie(0);
      
      cin>>n>>m;
      for(int i=1;i<=m;i++){
            
            int sum=0;
            vector<int> v(n+4);
            for(int j=1;j<=n;j++){
                  cin>>v[j];
                  sum+=v[j];
            }
            
            if(sum==0){
                  for(int j=1;j<=n;j++) cout<<1<<" ";
                  cout<<"\n";
            } else{
                  int Sum=0;
                  for(int j=1;j<=n;j++){
                        Sum+=v[j];
                        if(Sum*2==sum){
                              for(int k=1;k<=j;k++) cout<<-1<<" ";
                              for(int k=1;k<=n-j;k++) cout<<1<<" ";
                              cout<<"\n";
                              break;
                        }
                  }
            }
      }
}