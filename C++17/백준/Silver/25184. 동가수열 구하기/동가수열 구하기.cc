#include<iostream>
using namespace std;
int n;
int main() {
    ios::sync_with_stdio(0);cout.tie(0);
    cin >> n;
    if(!(n%2)){
          for(int i=1;i<=n/2;i++) cout<<n/2+i<<" "<<i<<" ";
    }
    else{
          for(int i=1;i<=n/2;i++) cout<<i<<" "<<n/2+n%2+i<<" ";
          cout<<n/2+1;
    }
}