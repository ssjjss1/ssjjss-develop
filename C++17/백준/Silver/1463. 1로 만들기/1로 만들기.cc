#include<iostream>
using namespace std;
int n;
int a[1000004];
int main(){
  cin>>n;
  for(int i=2;i<=n;i++){
    a[i]=a[i-1]+1;
    if(i%2==0){
      a[i]=min(a[i],a[i/2]+1);
    }
    if(i%3==0){
      a[i]=min(a[i],a[i/3]+1);
    }
  }
  cout<<a[n];
}