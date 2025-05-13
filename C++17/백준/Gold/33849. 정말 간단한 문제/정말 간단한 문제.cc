#include<bits/stdc++.h>
using namespace std;

long long gcd(long long a, long long b) {
	if(b==0) return a;
	return gcd(b, a%b);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin>>n;

	vector<long long> A(n+4,0), B(n+4,0);

	for(int i=1; i<=n; i++) {
		cin>>A[i];
	}

	for(int i=1; i<=n; i++) {
		cin>>B[i];
	}

	long long g=gcd(A[1], B[1]);
	long long prevA=A[1]/g, prevB=B[1]/g, len=1, mx=-1e9+7;

	for(int i=2; i<=n; i++) {
		long long g=gcd(A[i], B[i]);

		A[i]=A[i]/g;
		B[i]=B[i]/g;

		if(prevA*B[i]==prevB*A[i]) {
			len+=1;
		} else if(prevA*B[i]>prevB*A[i]) {
			len=1;
			mx=0;
			prevA=A[i];
			prevB=B[i];
		} else {
			mx=max(mx, len);
			len=0;
		}
	}
	
	if(prevA*B[n]==prevB*A[n]){
	      mx=max(len, mx);
	}
	
	cout<<prevB<<" "<<prevA<<"\n"<<mx;
}