#include<bits/stdc++.h>
#define SORT(v) sort((v).begin(), (v).end())
using namespace std;

void getNum(vector<int> &allNum, vector<int> &v, int n){
      for(int i=1;i<=n;i++){
            int x;
            cin>>x;
            v.push_back(x);
            allNum.push_back(x);
      }
}

bool check(const vector<int> &v, int l, int r){
      int itL=lower_bound(v.begin(), v.end(), l)-v.begin();
      int itR=upper_bound(v.begin(), v.end(), r)-v.begin();
      return (itR-itL)>0;
}

int main(){
      ios_base::sync_with_stdio(0);
      cin.tie(0);
      
      int a,b,c;
      cin>>a>>b>>c;
      
      vector<int> A,B,C,allNum;
      
      getNum(allNum, A, a);
      getNum(allNum, B, b);
      getNum(allNum, C, c);
      
      SORT(allNum); SORT(A); SORT(B); SORT(C);
      
      int n=a+b+c;
      int mn=1e9+7;
      for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                  if(check(A, allNum[i], allNum[j])
                  &&check(B, allNum[i], allNum[j])
                  &&check(C, allNum[i], allNum[j])){
                        mn=min(mn, allNum[j]-allNum[i]);
                  }
            }
      }
      cout<<mn;
}