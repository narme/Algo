#include <iostream>
#include <queue>
#include <vector>

using namespace std;
int n;

vector<int> relation[500];
queue<int> q;
int degree[500], cost[500], answer[500];
void input(){
    cin >> n;

    int input;
    for(int i = 0; i < n; i++){
        int cnt = 0;
        cin >> input;
        cost[i] = input;

        cin >> input;
        while(input != -1){
            relation[input-1].push_back(i);
            cnt++;
            cin >> input;
        }
        degree[i] = cnt;
        if(degree[i] == 0)q.push(i);
    }
}
void solve(){
    queue<int> calc;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        //cost 계산
        if(!answer[node]) answer[node] = cost[node];
        for(int i = 0; i < relation[node].size(); i++){
            int next = relation[node][i];
            answer[next] = max(answer[next], answer[node] + cost[next]);
            if(--degree[next] == 0)q.push(next);
        }
    }
    for(int i = 0; i < n; i++){
        cout << answer[i] << "\n";
    }
}

int main(){
    input();
    solve();
}