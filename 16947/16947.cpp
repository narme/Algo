#include <iostream>
#include <vector>
#include <string.h>
#include <queue>

#define MAX 3001
using namespace std;


vector<int> subway[MAX];
int visitedSubway[MAX];
int answer[MAX];
bool visit[MAX];
bool isCycle[MAX];
int n, idx;


void input(){
    cin >> n;
    int a, b;
    for(int i = 0; i < n; i++){
        cin >> a >> b;
        subway[a].push_back(b);
        subway[b].push_back(a);
    }
}
pair<int,int> searchCycle(int cv, int prev, int to){
    visitedSubway[idx++] = cv;
    visit[cv] = true;
    for(auto nv : subway[cv]){
        
        if(nv == prev)continue;
        //사이클 발견
        if(visit[nv]){
            return {nv, to};
        }
        pair<int,int> tmp = searchCycle(nv, cv, idx);
        if(tmp.first == -1)continue;
        else {
            return {tmp.first, tmp.second};
        }
    }
    return {-1, -1};
}
void addCycleList(int from){
    bool check = false;
    for(int i = 0; i <= idx; i++){
        if(visitedSubway[i] == from)check = true;
        isCycle[visitedSubway[i]] = check;
    }
}
void bfs(int from){
    memset(visitedSubway, false, sizeof(visitedSubway));
    queue<pair<int, int>> q; // subwayNumber, distance

    q.push({from , 0});
    while(!q.empty()){
        int now = q.front().first;
        int dis = q.front().second;
        q.pop();
        if(visitedSubway[now])continue;

        visitedSubway[now] = true;
        answer[now] = dis;
        for(auto i : subway[now]){
            if(visitedSubway[i])continue;
            if(isCycle[i])q.push({i, 0});
            else q.push({i, dis + 1});
        }
    }
    
}

void solve(){
    input();
    pair<int,int> result = searchCycle(1, -1, 0);
    int from = result.first;
    idx = result.second;
    addCycleList(from);
    bfs(from);
    for(int i = 1; i <= n; i++)cout << answer[i] << " ";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}