#include<bits/stdc++.h>
using namespace std;

unordered_map<string,bool> ma;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin>>n;

	bool flag=false;
	while(n--) {
		string s1,s2;
		cin>>s1>>s2;
		if(s1=="ChongChong"||s2=="ChongChong") {
			ma[s1]=1;
			ma[s2]=1;
			if(s1!=s2) flag=true;
		}
		else if(flag) {
			if(ma[s1]==1||ma[s2]==1) {
				ma[s1]=1;
				ma[s2]=1;
			}
		}
	}
	int ans=0;
	for(auto [name, cnt]:ma){
	      if(cnt==1) ans+=1;
	}
	cout<<ans;
}