#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,sum;
priority_queue<ll> q;
int main(){
      ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
      cin>>n>>m;
      int cnt=0;
      for(ll i=1,x;i<=n;i++) {
            cin>>x;
            q.push(x);
            sum+=x;
            while(sum>=m) {
                  sum-=2*q.top();
                  q.pop();
                  cnt+=1;
            }
      }
      cout<<cnt;
}