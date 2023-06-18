#include <iostream>
#include <queue>
#include <algorithm>
#include <string.h>
#include <fstream>

using namespace std;

int parent[501];
bool visit[501][501];

int v, e;
int singleNode;
queue<pair<int, int>> q;

int getParent(int i){
    if(parent[i] == i)return parent[i];
    else return getParent(parent[i]);
}

void input(){
    int v1, v2;
    for(int i = 0; i < e; i++){
        cin >> v1 >> v2;
        int s = min(v1, v2);
        int b = max(v1, v2);

        //singleNode 확인
        visit[0][s] = visit[0][b] = true;

        parent[b] = parent[s] = min(getParent(s), getParent(b));
        q.push({s, b});
    }
}

void init(){
    for(int i = 1; i <= v; i++){
        parent[i] = i;
    }
    memset(visit, false, sizeof(visit));
    singleNode = 0;
}
int countTree(){
    vector<int> pass, roots;
    
    //singleNode 개수 확인
    for(int i = 1; i <= v; i++)if(visit[0][i] == false)singleNode++;

    while(!q.empty()){
        int v1 = q.front().first;
        int v2 = q.front().second;
        int parent = getParent(v1);
        q.pop();
        
        //root 목록에 없으면 추가
        if(find(roots.begin(), roots.end(), parent) == roots.end()){
            roots.push_back(parent);
        }
        if(find(pass.begin(), pass.end(), parent) != pass.end()){
            continue;
        }
        //이미 방문
        if(visit[parent][v1]){
            pass.push_back(parent);
        }
        else visit[parent][v1] = true;
    }
    int answer = roots.size() - pass.size() + singleNode;
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
    //freopen("testcase.txt", "r", stdin);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}