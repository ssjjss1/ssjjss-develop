#include<iostream>
using namespace std;
long long int n,m;
long long int cnt=1;
int main(){
  cin>>m>>n;
  for(int i=0;i<n;i++){
    cnt=cnt*double(m-i)/double(i+1);
  }
  cout<<cnt;
}