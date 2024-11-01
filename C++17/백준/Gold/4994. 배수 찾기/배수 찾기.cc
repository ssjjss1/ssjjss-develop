#include<iostream>
#include<queue>
using namespace std;
typedef unsigned long long ll;
int n;
int main(){
      ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
      while(true){
            cin>>n;
            if(n==0) return 0;
            priority_queue<ll,vector<ll>,greater<ll>> q;
            q.push(1);
            while(!q.empty()){
                  ll x=q.top();
                  q.pop();
                  if(!(x%n)) {
                        cout<<x<<"\n";
                        break;
                  }
                  q.push(10*x+1);q.push(10*x);
            }
      }
}