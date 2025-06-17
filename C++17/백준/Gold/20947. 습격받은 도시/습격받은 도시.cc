#include<bits/stdc++.h>
using namespace std;
int n;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin>>n;

	vector<vector<char>> d(n+4, vector<char>(n+4, '.')), d1(n+4, vector<char>(n+4, '.')), d2(n+4, vector<char>(n+4, '.'));

	for(int i=1; i<=n; i++) {
		for(int j=1; j<=n; j++) {
			cin>>d[i][j];
			d1[i][j]=d[i][j];
			d2[i][j]=d[i][j];
		}
	}

	for(int i=1; i<=n; i++) {
		char prev='.';
		for(int j=1; j<=n; j++) {
			if(prev=='O') {
				if(d1[i][j]=='X') {
					prev='.';
				} else {
					d1[i][j]=prev;
				}
			} 
			if(d1[i][j]=='O'){
			      prev='O';
			}
		}
		for(int j=n; j>=1; j--) {
			if(prev=='O') {
				if(d1[i][j]=='X') {
					prev='.';
				} else {
					d1[i][j]=prev;
				}
			} 
			if(d1[i][j]=='O'){
			      prev='O';
			}
		}
	}
	
	for(int j=1; j<=n; j++) {
		char prev='.';
		for(int i=1; i<=n; i++) {
			if(prev=='O') {
				if(d2[i][j]=='X') {
					prev='.';
				} else {
					d2[i][j]=prev;
				}
			} 
			if(d2[i][j]=='O'){
			      prev='O';
			}
		}
		for(int i=n; i>=1; i--) {
			if(prev=='O') {
				if(d2[i][j]=='X') {
					prev='.';
				} else {
					d2[i][j]=prev;
				}
			} 
			if(d2[i][j]=='O'){
			      prev='O';
			}
		}
	}
	
	for(int i=1;i<=n;i++){
	      for(int j=1;j<=n;j++){
	            if(d1[i][j]=='.'&&d2[i][j]=='.'){
	                  cout<<"B";
	            } else{
	                  cout<<d[i][j];
	            }
	      }
	      cout<<"\n";
	}
}