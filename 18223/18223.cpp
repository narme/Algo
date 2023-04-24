#include <algorithm>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

vector<pair<int, int>> *node; // <거리 , 노드>
int *result;
int INF = 50000000;

int v, e, p; // 정점, 간선, 건우


void dijkstra(int start){
    for(int i = 0; i < v+1; i++)result[i] = INF;
    result[start] = 0;
    priority_queue<pair<int, int>> pq; // dis , node
    pq.push(make_pair(0, start));
    
    while(!pq.empty())
    {
        int currentNode = pq.top().second;
        int currentDistance = -pq.top().first;
        pq.pop();
        
        if(currentDistance > result[currentNode])continue;

        for(int i = 0; i < node[currentNode].size(); i++){
            int next = node[currentNode][i].second;
            int nextDistance = node[currentNode][i].first + currentDistance;

            if(nextDistance < result[next]){
                result[next] = nextDistance;
                pq.push(make_pair(-nextDistance, next));
            }
        }
    }
}


int main(){
    cin >> v >> e >> p;
    node = new vector<pair<int ,int>>[v+1];
    result = new int[v+1];

    for(int i = 0; i < e; i++){
        int src, dest, dis;
        cin >> src >> dest >> dis;

        node[src].push_back(make_pair(dis, dest));
        node[dest].push_back(make_pair(dis, src));
    }

    dijkstra(1);
    int minimumDistance = result[v]; // 마산까지 최소거리
    int startToGunwoo = result[p]; // 시작지점부터 건우까지최소거리

    for(int i = 0; i < v+1; i++)cout << " " << result[i];
    cout << "\n";

    dijkstra(4);
    int GunwooToGoal = result[v]; //건우부터 마산까지 최소거리

    for(int i = 0; i < v+1; i++)cout << " " << result[i];
    cout << "\n";

    if(minimumDistance == startToGunwoo + GunwooToGoal && GunwooToGoal != 0)cout << "SAVE HIM";
    else cout << "GOOD BYE";

}