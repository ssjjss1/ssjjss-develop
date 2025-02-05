#include<bits/stdc++.h>
using namespace std;
int n;

deque<int> dq;
int main(){
      ios_base::sync_with_stdio(0); cin.tie(0);
      cin>>n;
      while(n--){
            string s;
            cin >> s;
            if(s=="push"){
                  int x;
                  cin>>x;
                  dq.push_back(x);
            }
            if(s=="pop"){
                  if(dq.size()){
                        cout<<dq.front()<<"\n";
                        dq.pop_front();
                  } else{
                        cout<<-1<<"\n";
                  }
            }
            if(s=="size"){
                  cout<<dq.size()<<"\n";
            }
            if(s=="empty"){
                  if(dq.empty()) {
                        cout<<1<<"\n";
                  } else{
                        cout<<0<<"\n";
                  }
            }
            if(s=="front"){
                  if(dq.empty()){
                        cout<<-1<<"\n";
                  } else{
                        cout<<dq.front()<<"\n";
                  }
            }
            if(s=="back"){
                  if(dq.empty()){
                        cout<<-1<<"\n";
                  }else{
                        cout<<dq.back()<<"\n";
                  }
            }
      }
}