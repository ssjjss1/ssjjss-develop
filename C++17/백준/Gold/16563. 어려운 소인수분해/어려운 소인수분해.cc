#include<iostream>

#include<vector>

using namespace std;

int n, m;

const int inf=5000001;

vector<int> v(inf);

vector<bool> visited(inf,true);

int main() {

  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  cin >> n;

  for(int i=2;i<=inf;i++){

     if(visited[i]){

       for(int j=i;j<=inf;j+=i){

        if(visited[j]){

          visited[j]=false;

          v[j]=i;}

    }

  }

  }

  for (int i = 1; i <= n; i++) {

    cin >> m;

    for (;;) {

      if (m <=1) break;

      cout << v[m]<<" ";

      m = m / v[m];

    }

    cout << "\n";

  }

}