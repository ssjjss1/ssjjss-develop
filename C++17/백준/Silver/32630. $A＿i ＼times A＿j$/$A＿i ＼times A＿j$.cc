#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<long long> a(n);
    long long sum = 0;
    bool flag = false;
    for(int i=0;i<n;i++){
        cin >> a[i];
        sum += a[i];
        if(a[i] == 0) flag = true;
    }

    sort(a.begin(), a.end());

    long long ans = sum; 

    int lim = min(n, 3);
    for(int i=0;i<lim;i++){
        for(int j=max(i+1,n-lim); j<n; j++){ 
            long long temp = 2*a[i]*a[j] - (a[i] + a[j]);
            ans = max(ans, sum + temp);
        }
    }
    for(int i=0;i<lim;i++){
        for(int j=i+1;j<lim;j++){
            long long temp = 2*a[i]*a[j] - (a[i] + a[j]);
            ans = max(ans, sum + temp);
        }
    }
    for(int i=n-lim;i<n;i++){
        for(int j=i+1;j<n;j++){
            long long temp = 2*a[i]*a[j] - (a[i] + a[j]);
            ans = max(ans, sum + temp);
        }
    }

    if(flag) ans = max(ans, sum - a[0]);

    cout << ans;
}