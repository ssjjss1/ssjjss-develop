#include<bits/stdc++.h>
using namespace std;
int main(){
      ios_base::sync_with_stdio(0);cin.tie(0);
      while(true){
            int n,m;
            cin>>n>>m;
            if(n==0&&m==0) break;
            
            if(m/n&&!(m%n)) cout<<"factor"<<'\n';
            else if(n/m&&!(n%m)) cout<<"multiple"<<'\n';
            else cout<<"neither"<<"\n";
      }
}