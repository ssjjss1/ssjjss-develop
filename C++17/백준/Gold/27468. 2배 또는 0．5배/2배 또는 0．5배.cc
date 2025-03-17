#include<bits/stdc++.h>
using namespace std;
int n;
int dx[]={1,1,2,-1};
int main(){
      ios_base::sync_with_stdio(0);
      cin.tie(0);
      
      cin>>n;
      
      if(n==3) {
            cout<<"YES\n"<<1<<" "<<3<<" "<<2;
      } else{
            if(n%4==3) cout<<"NO";
            else {
                  cout<<"YES\n";
                  int idx=n/4+(n%4?1:0);
                  
                  for(int i=0;i<idx;i++){
                        
                        int num=i*4;
                        
                        if(i!=idx-1){
                              
                              for(int j=0;j<4;j++){
                                    num+=dx[j];
                                    cout<<num<<" ";
                              }
                        } else{
                              int lim=(n%4==0?4:n%4);
                              
                              for(int j=0;j<lim;j++){
                                    num+=dx[j];
                                    cout<<num<<" ";
                              }
                        }
                  }
            }
      }
}