#include<iostream>
using namespace std;
int a[100];
int gcd(int a, int b){
    if (b == 0) return a;
    else return gcd(b, a % b);
}
int main(){
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n;
        cin >> n; 
        for (int j = 0; j < n; j++) cin >> a[j]; 
        long long sum = 0; 
        for (int k = 0; k < n-1; k++) {
            for (int m = k+1; m < n; m++) {
                sum += gcd(a[k], a[m]);
            }
        }
        cout << sum <<"\n";
    }
}