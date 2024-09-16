#include<iostream>
#include<map>
using namespace std;
int n;
map<int,int> ma;
int main(){
      ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
      cin>>n;
      for(int i=1,x,y,z;i<=n;i++){
            cin>>x;
            if(x==1) {
                  cin>>y>>z;
                  ma[z]=y;
            }
            else {
                  cin>>y;
                  cout<<ma[y]<<"\n";
            }
      }
}