#include <iostream>
#include <queue>
using namespace std;

bool dp[40001];
int weight[30];
int marble[7];
int weightNumbers, marbleNumbers;

void input(){
    cin >> weightNumbers;
    for(int i = 0; i < weightNumbers; i++)cin >> weight[i];

    cin >> marbleNumbers;
    for(int i = 0; i < marbleNumbers; i++)cin >> marble[i];
}

void makeDPTable(){
    queue<int> q;
    for(int i = 0; i < weightNumbers; i++){
        int w = weight[i];
        for(int j = 0; j < 40001; j++){
            if(dp[j] || j == 0){
                q.push(w+j);
                q.push(abs(w-j));
            }
        }
        while(!q.empty()){
            dp[q.front()] = true;
            q.pop();
        }
    }
}

void solve(){
    makeDPTable();
    for(int i = 0; i < marbleNumbers; i++){
        if(dp[marble[i]] > 0)cout << "Y " ;
        else cout << "N ";
    }
}

int main(){
    input();
    solve();
}