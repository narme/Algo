#include <iostream>
#include <queue>

#define maxsize 5001
using namespace std;

queue<int> q;
vector<pair<int, int>> node[maxsize];
int n, nq;

void input(){
    cin >> n >> nq;

    int src, des, usado;
    for(int i = 0; i < n - 1; i++){
        cin >> src >> des >> usado;
        node[src].push_back({des, usado});
        node[des].push_back({src, usado});
    }
}

bool visit[maxsize];

void solve(){
    int start, usado;
    for(int i = 0; i < nq; i++){
        cin >> usado >> start;
        fill_n(visit, maxsize, false);
        q.push(start);
        int cnt = -1;
        while(!q.empty()){
            int cur = q.front();
            q.pop();
            if(!visit[cur]){
                cnt++;
                visit[cur] = true;
            }else continue;

            for(auto next : node[cur]){
                int nxt = next.first;
                int nusado = next.second;
                if(nusado >= usado && !visit[nxt])q.push(nxt);
            }
        }
        cout << cnt << "\n";
    }
}

int main(){
    cin.tie(0), cout.tie(0);
    input();
    solve();
}
