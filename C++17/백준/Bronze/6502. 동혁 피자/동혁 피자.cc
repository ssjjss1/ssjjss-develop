#include<iostream>
using namespace std;
int n,m,k;
int main() {
	for(int i=1;; i++) {
		cin>>n;
		if(n==0) return 0;
		cin>>m>>k;
		if(m*m+k*k>4*n*n) cout<<"Pizza "<<i<<" does not fit on the table."<<"\n";
		else cout<<"Pizza "<<i<<" fits on the table."<<"\n";
		}
}