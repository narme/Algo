#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>

using namespace std;

priority_queue<int> q;
int n, m, maxn;
int cows[9];
bool primes[9000];
void combination(int start, int c, int sum){
    if(c == 0){
        if(maxn < sum)maxn = sum;
        q.push(sum*-1);
        return;
    }
    for(int i = start; i <= n - c; i++){
        combination(i + 1, c - 1, sum+cows[i]);
    }
}
void getPrime(int range){
    primes[1] = true;
    for(int i = 2; i <= range; i++){
        primes[i] = true;
        for(int j = 2; j < i; j++){
            if(i % j == 0){
                //cout << i << " is not primes\n";
                primes[i] = false;
                break;
            }
        }
        
    }
}

void solve(){
    bool noCows = true;
    combination(0, m, 0);
    getPrime(maxn);
    //for(auto i : primes)cout << i << " ";
    while(!q.empty()){
        if(primes[q.top()*-1] == true){
            cout << q.top()*-1 << " ";
            primes[q.top()*-1] = false;
            noCows = false;
        }
        q.pop();
    }
    if(noCows)cout << "-1";
}
void input(){
    cin >> n >> m;
    for(int i = 0; i < n; i++)cin >> cows[i];
}

int main(){
    input();
    solve();
}