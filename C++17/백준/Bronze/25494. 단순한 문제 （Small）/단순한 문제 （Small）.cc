#include<bits/stdc++.h>
using namespace std;
int n;
int main(){
      ios_base::sync_with_stdio(0);cin.tie(0);
      cin>>n;
      while(n--){
            int a,b,c;
            int cnt=0;
            cin>>a>>b>>c;
            for(int i=1;i<=a;i++){
                  for(int j=1;j<=b;j++){
                        for(int k=1;k<=c;k++){
                              if(((i%j)==(j%k))&&((j%k)==(k%i))){
                                    cnt+=1;
                              }
                        }
                  }
            }
            cout<<cnt<<'\n';
      }
}