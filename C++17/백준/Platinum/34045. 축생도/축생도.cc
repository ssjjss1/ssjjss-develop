#include<bits/stdc++.h>
#define INF 300004
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    
    vector<int> a(n), b(n), A(INF, 0), B(INF, 0);
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        A[a[i]] += 1;
    }
    
    for(int i = 1; i <= n; i++){
        cin >> b[i];
        B[b[i]] += 1;
    }
    
    for(int i = 1; i <= INF; i++){
        if(A[i] != B[i]){
            cout << "NO";
            return 0;
        }
    }
    
    for(int i = 1; i <= n; i++){
        if(a[i] == b[i] || b[i] == i) continue;
        
        int cx = a[i], nx = b[i];
        vector<int> visited(n, 0);
        while(cx != nx){
            if(a[cx] == b[cx] || visited[cx]){
                cout << "NO";
                return 0;
            }
            visited[cx] = 1;
            cx = a[cx];
        }
    }
    
    cout << "YES";
}