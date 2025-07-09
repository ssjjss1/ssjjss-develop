#include<bits/stdc++.h>
using namespace std;

int d[100004];
vector<int> primes;

void run(int x, int si) {
	x = abs(x); 
	for(auto i : primes) {
		if(1LL * i * i > x) break;
		while(x % i == 0) {
			d[i] += si;
			x /= i;
		}
	}
	if(x > 1) d[x] += si;
}

void initPrimes() {
	vector<int> visited(100004, 0);
	for(int i = 2; i < 100004; i++) {
		if(!visited[i]) {
			primes.push_back(i);
			for(int j = 2*i; j < 100004; j += i) {
				visited[j] = 1;
			}
		}
	}
}

bool check() {
	for(int i = 2; i < 100004; i++) if(d[i] < 0) return false;
	return true;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	initPrimes();

	vector<int> nums(n);
	vector<char> sign(n-1);

	for(int i = 0; i < n; i++) {
		cin >> nums[i];
		if(nums[i]==0) {
			cout<<"mint chocolate";
			return 0;
		}
		if(i < n - 1) cin >> sign[i];
	}

	run(nums[0], +1);
	for(int i = 0; i < n - 1; i++) {
		if(sign[i] == '*') {
			run(nums[i + 1], +1);
		} else {
			run(nums[i + 1], -1);
		}
	}

	cout << (check() ? "mint chocolate" : "toothpaste");
}