#include<bits/stdc++.h>
using namespace std;
int n;
deque<int> dq;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	while(n--) {
		int t;
		cin>>t;
		if(t==1) {
			int x;
			cin>>x;
			dq.push_front(x);
		}
		if(t==2) {
			int x;
			cin>>x;
			dq.push_back(x);
		}
		if(t==3) {
			if(dq.empty()) cout<<-1<<"\n";
			else {
				cout<<dq.front()<<"\n";
				dq.pop_front();
			}
		}
		if(t==4){
		      if(dq.empty()) cout<<-1<<"\n";
		      else{
		            cout<<dq.back()<<"\n";
		            dq.pop_back();
		      }
		}
		if(t==5){
		      cout<<dq.size()<<"\n";
		}
		if(t==6){
		      cout<<(dq.empty()?1:0)<<"\n";
		}
		if(t==7){
		      if(dq.empty()) cout<<-1<<"\n";
		      else cout<<dq.front()<<"\n";
		}
		if(t==8){
		      if(dq.empty()) cout<<-1<<"\n";
		      else cout<<dq.back()<<"\n";
		}
	}
}