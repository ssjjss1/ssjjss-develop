#include<iostream>
using namespace std;
int n,m,cnt;
char c[104][104];
void f(int x, int y){
      for(int i=1;i<=x;i++){
            for(int j=1;j<=y;j++){
                  c[i][j]=='1' ?c[i][j]='0':c[i][j]='1';
            }
      }
}
// void PRINT(){
//       for(int i=1;i<=n;i++){
//             for(int j=1;j<=m;j++){
//                   cout<<c[i][j]<<" ";
//             }
//             cout<<"\n";
//       }
// }
int main(){
      ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
      cin>>n>>m;
      for(int i=1;i<=n;i++){
            string s;
            cin>>s;
            for(int j=0;j<m;j++){
                  c[i][j+1]=s[j];
            }
      }
      for(int i=n;i>=1;i--){
            for(int j=m;j>=1;j--){
                  if(c[i][j]=='1') f(i,j),cnt+=1;
            }
      }
      cout<<cnt;
}