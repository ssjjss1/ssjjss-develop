#include <iostream>
#include <climits>
using namespace std;
int main(){
    int N = 0;
    long long tmp = 0, sum = 0, overflow = 0;
    for(int i = 0; i < 3; i++){
        sum = 0;
        overflow = 0;
        cin >> N;
        while(N--){
            long long tmp;
            std::cin>>tmp;

            if (sum > 0 && tmp > 0 && tmp > LLONG_MAX - sum) {
                overflow += 1;
            }

            if (sum < 0 && tmp < 0 && tmp < LONG_MIN - sum) {
                overflow -= 1;
            }
            sum += tmp;
        }
        if (overflow < 0){
            cout<<"-\n";
        }
        else if (overflow > 0){
            cout<<"+\n";
        }
        else if (sum==0){
            cout<<"0\n";
        }
        else if (sum < 0){
            cout<<"-\n";
        }
        else if (sum > 0){
            cout<<"+\n";
        }
    }
}