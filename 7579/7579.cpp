#include <iostream>
#include <queue>
#include <vector>

using namespace std;

vector<int> memory, cost;
int dp[10001];
int n, m, cost_sum;

void input(){
    cin >> n >> m;
    
    int tmp;
    for(int i = 0; i < n; i++){
        cin >> tmp;
        memory.push_back(tmp);
    }
    for(int i = 0; i < n; i++){
        cin >> tmp;
        cost_sum += tmp;
        cost.push_back(tmp);
    }
}

int solve(){
    for(int i = 0; i < n; i++){
        for(int j = cost_sum; j >= 0; j--){
            if(j - cost[i] >= 0)dp[j] = max(dp[j], dp[j-cost[i]] + memory[i]);
        }
    }
    int minimum = 0;
    while(dp[minimum] < m)minimum++;
    return minimum;
}

int main(){
    input();
    cout << solve();
}