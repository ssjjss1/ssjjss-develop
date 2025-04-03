#include<bits/stdc++.h>
using namespace std;
int n, d[2004][2004];
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int i,j,t;
	cin>>n;
	if(n%2) {
		i=2, j=1,t=1;
	} else {
		d[2][1]=1;
		d[2][2]=2;
		i=3, j=3,t=4;
	}
	while(i<n) {
		d[i][j]=t;
		d[i][j+1]=1;
		d[i+1][j+1]=t+2;
		t+=4;
		i+=2;
		j+=2;
	}
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=n; j++) {
			cout<<d[i][j]<<" ";
		}
		cout<<"\n";
	}
}