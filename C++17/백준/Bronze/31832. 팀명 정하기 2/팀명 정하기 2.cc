#include <iostream>
#include <string>
using namespace std;
bool f(string s) {
    int lowerCount = 0, upperCount = 0, charCount = 0;
    for (auto c : s) {
        if (islower(c)) lowerCount++; 
        else if (isupper(c)) upperCount++; 
        if (isalpha(c)||c=='-') charCount++;
    }
    if (upperCount > lowerCount) return 0;
    if (s.size() > 10) return 0;
    if (charCount == 0) return 0;
    return 1;
}
int main() {
    int n;
    cin >> n;
    string s;
    while(n--) {
        cin >> s;
        if (f(s)) {
            cout << s;
            break; 
        }
    }
}