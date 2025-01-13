#include <iostream>
using namespace std;
int main() {
	int m; cin >> m;
	int arr[4] = {0,1,2,3};  
	for (int i = 0; i < m; i++) {
		int first, second;
		cin >> first >> second;
		swap(arr[first], arr[second]);
	}
	int i = 1;
	while (true) {
		if (arr[i] == 1) { 
			cout << i << '\n';
			break;
		}
		i++;
	}
}