#include <iostream>
#include <queue>
#include <algorithm>
#include <string.h>
#include <fstream>

using namespace std;

bool visit[501];
vector<int> edge[501];

int v, e;

void input(){
    int v1, v2;
    for(int i = 0; i < e; i++){
        cin >> v1 >> v2;

        edge[v1].push_back(v2);
        edge[v2].push_back(v1);
    }
}

void init(){
    for(int i = 1; i <= v; i++)edge[i].clear();
    memset(visit, false, sizeof(visit));
}
bool dfs(int cv, int prev){
    visit[cv] = true;
    for(auto nv : edge[cv]){
        if(nv == prev)continue;
        else if(visit[nv])return false;
        else if(!dfs(nv, cv)) return false;
    }
    return true;
}
int countTree(){
    int answer = 0;
    queue<int> q;

    for(int cv = 1; cv <= v; cv++){
        if(dfs(cv, 0))answer++;
    }

    return answer;
}

void solve(){
    int round = 1;
    while(true){
        cin >> v >> e;
        if(v == 0 && e == 0)break;
        init();
        input();
        int answer = countTree();
        if(answer > 1) printf("Case %d: A forest of %d trees.\n", round, answer);
        else if(answer == 1) printf("Case %d: There is one tree.\n", round);
        else printf("Case %d: No trees.\n", round);
        round++;
    }
}
int main(){
    freopen("testcase.txt", "r", stdin);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}