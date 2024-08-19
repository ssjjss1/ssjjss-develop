#include<iostream>
#include<vector>
using namespace std;
string s;
int dp[54][54][54][4][4];
vector<int> v(4,0);
vector<char> s1(54);
bool f(int x, int y, int z, int l,int ll){
  if(x==v[0]&&y==v[1]&&z==v[2]) return 1;
  if(dp[x][y][z][l][ll]) return 0;
  dp[x][y][z][l][ll]=1;
  if(x<v[0]){
    s1[x+y+z+1]='A';
    if(f(x+1,y,z,0,l)) return 1;
  }
  if(y<v[1]&&l!=1){
    s1[x+y+z+1]='B';
    if(f(x,y+1,z,1,l)) return 1;
  }
  if(z<v[2]&&l!=2&&ll!=2){
    s1[x+y+z+1]='C';
    if(f(x,y,z+1,2,l)) return 1;
  }
  return 0;
}
int main(){
  ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  cin>>s;
  for(int i=0;i<s.size();i++){
    if(s[i]=='A') v[0]+=1;
    if(s[i]=='B') v[1]+=1;
    if(s[i]=='C') v[2]+=1;
  }
  if(f(0,0,0,0,0)){
    for(int i=1;i<=s.size();i++) cout<<s1[i];
  }
  else cout<<-1;
}