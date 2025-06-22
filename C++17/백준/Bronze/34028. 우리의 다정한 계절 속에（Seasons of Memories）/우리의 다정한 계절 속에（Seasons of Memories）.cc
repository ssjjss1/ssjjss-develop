#include<bits/stdc++.h>
using namespace std;
int t;

int main(){
      ios_base::sync_with_stdio(0);
      cin.tie(0);
      
      int a,b,c;
      cin>>a>>b>>c;
      
      int cnt = 0;

      for(int y=2015; y<=a; y++){
            if(y==a){
                  if(b>=1) cnt+=1; 
                  if(b>=3) cnt+=1;
                  if(b>=6) cnt+=1;
                  if(b>=9) cnt+=1;
                  if(b==12) cnt+=1;
            }
            else cnt += 4;
      }

      cout << cnt;
}