#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int n;
vector<string> v;
bool compare(string x, string y) {
	return x + y > y + x;
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	while (n--) {
		string s;
		cin >> s;
		v.push_back(s);
	}
	sort(v.begin(), v.end(),compare);
	string s;
	for (auto& i : v) {
		s += i;
	}
	if (s[0] == '0') cout << 0;
	else cout << s;
}