#include <iostream>
#include <vector>
#include <string.h>
#include <queue>

#define MAX 3001
using namespace std;


vector<int> subway[MAX];
int visitedSubway[MAX];
int answer[MAX];
bool isCycle[MAX];
int n, idx, to;


void input(){
    cin >> n;
    int a, b;
    for(int i = 0; i < n; i++){
        cin >> a >> b;
        subway[a].push_back(b);
        subway[b].push_back(a);
    }
}
int searchCycle(int cv, int prev){
    visitedSubway[idx++] = cv;
    answer[cv] = true;
    int thisIdx = idx;
    for(auto nv : subway[cv]){
        if(nv == prev)continue;
        //사이클 발견, 사이클 시작 지점의 지하철역 반환
        if(answer[nv] != -1){
            return nv;
        }
        int from = searchCycle(nv, cv);
        if(from == -1)continue;
        else {
            //to : 탐색한 지하철역들 중 사이클의 끝 기록
            if(to == 0)to = thisIdx + 1;
            return from;
        }
    }
    //끝일시 idx 감소 = 삭제 효과
    idx--;
    return -1;
}
void addCycleList(int fromNumber){
    bool check = false;
    //사이클 시작 지점 : from 부터 사이클의 끝 to까지 true
    for(int i = 0; i < to; i++){
        if(visitedSubway[i] == fromNumber)check = true;
        isCycle[visitedSubway[i]] = check;
    }
}
void bfs(){
    memset(answer, -1, sizeof(answer));
    queue<int> q; // subwayNumber

    //사이클에 포함된 지하철역들을 q에 추가
    for(int i = 1; i <= n; i++){
        if(isCycle[i]){
            answer[i] = 0;
            q.push(i);
        }
    }
    while(!q.empty()){
        int now = q.front();
        q.pop();

        for(auto i : subway[now]){
            if(answer[i] != -1)continue;
            else answer[i] = answer[now] + 1;
            //현재 지하철역이 사이클에 포함된 경우 거리를 0으로 초기화하고 push
            q.push(i);
        }
    }
    
}

void solve(){
    input();
    memset(answer, -1, sizeof(answer));
    int fromNumber = searchCycle(1, -1);
    cout << "from number : " << fromNumber << " to : " << to << "\n";
    addCycleList(fromNumber);
    cout << "cycle : ";
    for(int i = 1; i <= n; i++)if(isCycle[i])cout << i << " ";
    cout << "\n";
    bfs();
    for(int i = 1; i <= n; i++)cout << answer[i] << " ";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}