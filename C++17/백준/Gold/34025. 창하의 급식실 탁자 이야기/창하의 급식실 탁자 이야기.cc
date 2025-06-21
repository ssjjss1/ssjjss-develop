#include<bits/stdc++.h>
using namespace std;
int n;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin>>n;
	long long cnt1=0;
	vector<long long> even, odd;
	for(int i=1; i<=n; i++) {
		long long x;
		cin>>x;
		if(x==1) cnt1+=1;
		else if(x%2) odd.push_back(x);
		else even.push_back(x);
	}
	
	long long sum=0;
	if((odd.size()>0||cnt1>0)&&(even.size()>0||cnt1>0)){
	      if(odd.size()>0) sum+=odd[0]/2+1;
	      sum+=cnt1;
	      for(int i=0;i<even.size();i++){
	            sum+=even[i]/2+1;
	      }
	      if(odd.size()>1) sum+=odd[1]/2+1;
	      
	      for(int i=2;i<odd.size();i++){
	            if(i%2) sum+=odd[i]/2+1;
	            else sum+=odd[i]/2+2;
	      }
	} else if(even.size()==0){
	      for(int i=0;i<odd.size();i++){
	            if(i!=odd.size()-1&&i%2) sum+=1;
	            sum+=odd[i]/2+1;
	      }
	} else{
	      for(int i=0;i<even.size();i++){
	            if(i==even.size()-1) sum-=1;
	            sum+=even[i]/2+1;
	      }
	}
	cout<<sum;
}