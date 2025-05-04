#include<bits/stdc++.h>
using namespace std;
int main(){
      ios_base::sync_with_stdio(0);
      cin.tie(0);
      
      long long n,x1,y1,x2,y2;
      cin>>n>>x1>>y1>>x2>>y2;
      
      long long sum=(n*n*(n+1LL)*(n+1LL)/4);

      if(x1==x2){
            if(y1 > y2) swap(y1, y2);
            if(y1 < n && y2 > 0) {
                  if(y1 < 0) y1 = -1;
                  if(y2 > n) y2 = n;
                  sum += (y2 - y1 - 1) * (y2 - y1) / 2 * (n+1);
            }
      } else if(y1==y2){
            if(x1 > x2) swap(x1, x2);
            if(x1 < n && x2 > 0){
                  if(x1 < 0) x1 = -1;
                  if(x2 > n) x2 = n;
                  sum += ( (x2 - x1 - 1) * (x2 - x1) / 2 ) * (n+1);
            }
      }

      cout<<sum;
}