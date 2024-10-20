#include<iostream>
using namespace std;
string s;
int main(){
      while(true){
            int sum=0;
            cin>>s;
            if(s=="0") return 0;
            for(auto i:s){
                  if(i=='1') sum+=2;
                  else if(i=='0') sum+=4;
                  else sum+=3;
            }
            cout<<sum+s.size()+1<<"\n";
      }
}