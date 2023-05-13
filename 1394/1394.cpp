#include <iostream>
#include <string>
#include <map>
#include <cmath>

using namespace std;
string word, password;
map<char, int> keys;
int mod = 900528;

void input(){
    cin >> word >> password;
}

void solve(){
    for(int i = 0; i < word.length(); i++)keys.insert({word[i], i+1});
    int system = word.length();

    long long cnt = 0;
    int x = 1;
    for(int i = password.length() - 1; i >= 0; i--){
        cnt = (cnt + keys[password[i]]*x) % mod;
        x = x * system % mod;
    }
    cout << cnt;
}

int main(){
    input();
    solve();
}