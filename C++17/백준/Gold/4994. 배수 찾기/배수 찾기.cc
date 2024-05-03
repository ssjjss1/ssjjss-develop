#include<iostream>
#include<queue>
using namespace std;
int n;
typedef unsigned long long int ll;
int main(){
  ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  for(;;){
    cin>>n;
    if(n==0)return 0;
    priority_queue<ll,vector<ll>, greater<ll>> q;
    q.push(1);
    while(!q.empty()){
      ll x=q.top();
      q.pop();
      if(x%n==0){
        cout<<x<<"\n";
        break;
      }
      else{
        q.push(x*10+1);
        q.push(x*10);
      }
    }
    while(!q.empty())q.pop();
  }
}