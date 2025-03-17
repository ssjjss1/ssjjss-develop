#include<bits/stdc++.h>
using namespace std;
int dx[]= {0,1,-1,0}, dy[]={0,0,1,-1};
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin>>n;

	cout<<"YES\n";
	if(n%2==0) {
		for(int i=1; i<=n; i++) {
			cout<<i+(dy[(i-1)%4])<<" ";
		}
	} else {

		int lim=n/4+(n%4?1:0);
		for(int i=0; i<lim; i++) {

			int num=i*4+1;
			if(i!=lim-1) {
				for(int j=0; j<4; j++) {
					cout<<num+dx[j]+j<<" ";
				}
			} else{
			      
			      int inf=n%4;
			      for(int j=0; j<inf; j++) {
					cout<<num+dx[j]+j<<" ";
				}
			}


		}
	}
}