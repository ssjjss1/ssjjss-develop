#include <iostream>
#include<deque>
using namespace std;
long long int n;
long long int x;
string s;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin>>n;
  deque<long long int> v;
  for(int i=1;i<=n;i++){
    cin>>s;
    if(s=="push_front"){
      cin>>x;
      v.push_front(x);
    }
    else if(s=="push_back"){
      cin>>x;
      v.push_back(x);
    }
    else if(s=="pop_front"){
      if(v.empty()){
        cout<<-1<<"\n";
      }
      else{
        cout<<v.front()<<"\n";
        v.pop_front();
      }
    }
    else if(s=="pop_back"){
      if(v.empty()){
        cout<<-1<<"\n";
      }
      else{
        cout<<v.back()<<"\n";
        v.pop_back();
      }
    }
    else if(s=="size"){
      cout<<v.size()<<"\n";
    }
    else if(s=="empty"){
      if(v.empty()){
        cout<<1<<"\n";
      }
      else{
        cout<<0<<"\n";
      }
    }
    else if(s=="front"){
      if(v.empty()){
        cout<<-1<<"\n";
      }
      else {
        cout<<v.front()<<"\n";
      }
    }
    else if(s=="back"){
      if(v.empty()){
        cout<<-1<<"\n";
      }
      else{
        cout<<v.back()<<"\n";
      }
    }
  }
}