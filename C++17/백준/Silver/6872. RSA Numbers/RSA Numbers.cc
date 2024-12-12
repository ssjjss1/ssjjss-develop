#include<iostream>
using namespace std;
int n,m,cnt;
bool f(int x){
      int count=0;
      for(int i=1;i*i<=x;i++){
            if(!(x%i)) {
                  if(i!=x/i) count+=2;
                  else count+=1;
            }
      }
      return count==4;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=n; i<=m; i++) if(f(i)) cnt+=1;
	cout<<"The number of RSA numbers between "<<n<<" and "<<m<<" is "<<cnt;
}