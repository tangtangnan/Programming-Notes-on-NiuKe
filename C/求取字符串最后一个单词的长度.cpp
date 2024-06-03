#include<iostream>
#include<string>

using namespace std;

int main11() {
    string s;
    getline(cin, s);
    int ans = 0, i = s.length() - 1;
    while (i >= 0 && s[i] != ' ') {
        i--;
        ans++;
    }
    cout << ans;
    return 0;
}
