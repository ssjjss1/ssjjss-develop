#include<iostream>
using namespace std;
int n,cnt;
int isPalindrome(string &s,int l, int r) {
	cnt += 1;
	if (l >= r) return 1;
	else if (s[l] != s[r]) return 0;
	return isPalindrome(s, l + 1, r - 1);
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	while (n--) {
		cnt = 0;
		string s;
		cin >> s;
		cout << isPalindrome(s,0,s.size()-1)<< " " << cnt<<"\n";
	}
}