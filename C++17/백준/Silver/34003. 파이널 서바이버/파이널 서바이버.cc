#include<bits/stdc++.h>
using namespace std;

double Combination(int n, int k){
      int res=1;
      for(int i=1;i<=k;i++){
            res=res*(n-k+i)/i;
      }
      return (double) res;
}

int main(){
      ios_base::sync_with_stdio(0);
      cin.tie(0);
      
      vector<vector<char>> v(14, vector<char>(14));
      
      int cntO=0;
      for(int i=1;i<=8;i++){
            for(int j=1;j<=8;j++){
                  cin>>v[i][j];
                  if(v[i][j]=='O') cntO+=1;
            }
      }
      
      int mx=0, nx=0, ny=0;
      for(int i=1;i<8;i++){
            for(int j=1;j<8;j++){
                  int cnt=0;
                  if(v[i][j]=='O') cnt+=1;
                  if(v[i][j+1]=='O') cnt+=1;
                  if(v[i+1][j]=='O') cnt+=1;
                  if(v[i+1][j+1]=='O') cnt+=1;

                  if(mx<cnt){
                        mx=cnt;
                        nx=i;
                        ny=j;
                        if(mx==4) break;
                  }
            }
      }
      
      cout<<nx<<" "<<ny<<"\n";
      cout<<fixed<<setprecision(20)<<1.0-Combination(cntO-mx,4)/Combination(cntO,4);
}