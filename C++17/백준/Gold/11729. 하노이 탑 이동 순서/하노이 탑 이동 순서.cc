#include<iostream>
using namespace std;
int n;
void f(int x, int y, int z,int cnt){
      if(cnt==1){
            cout<<x<<" "<<z<<"\n";
            return;
      }
      f(x,z,y,cnt-1);
      cout<<x<<" "<<z<<"\n";
      f(y,x,z,cnt-1);
}
int main(){
      ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
      cin>>n;
      cout<<(1<<n)-1<<"\n";
      f(1,2,3,n);
}