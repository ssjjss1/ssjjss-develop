#include<iostream>
#include<queue>
using namespace std;
long long int n;
long long int m;
long long int k=0;
string s;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin>>n;
  queue<long long int> v;
  for(int i=0;i<n;i++){
    cin>>s;
    if(s=="push"){
      cin>>m;
      v.push(m);
    }
    else if(s=="pop"){
      if(v.size()==0){
        k=-1;
        cout<<k<<endl;
      }
      else{
        k=v.front();
        cout<<k<<endl;
        v.pop();
      }
    }
    else if(s=="size"){
      cout<<v.size()<<endl;
    }
    else if(s=="empty"){
      if(v.size()==0){
        k=1;
        cout<<k<<endl;
      }
      else{
        k=0;
        cout<<k<<endl;
      }
    }
    else if(s=="front"){
      if(v.size()==0){
        k=-1;
        cout<<k<<endl;
      }
      else{
        k=v.front();
        cout<<k<<endl;
      }
    }
    else if(s=="back"){
      if(v.size()==0){
        k=-1;
        cout<<k<<endl;
      }
      else{
        k=v.back();
        cout<<k<<endl;
      }
    }
  }
}