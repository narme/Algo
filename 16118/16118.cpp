#include <algorithm>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

vector<pair<int, int>> *node; // <거리 , 노드>
long long *foxResult, **wolfResult;
long long INF = 0x7fffffffffffffff;

int stump, path; // 그루터기 수, 오솔길 수


void foxDijkstra(int start){
    for(int i = 0; i < stump+1; i++)foxResult[i] = INF;
    foxResult[start] = 0;
    priority_queue<pair<long long, int>> pq; // dis , node
    pq.push(make_pair(0, start));
    
    while(!pq.empty())
    {
        int currentNode = pq.top().second;
        long long currentDistance = -pq.top().first;
        pq.pop();
        
        if(currentDistance > foxResult[currentNode])continue;

        for(int i = 0; i < node[currentNode].size(); i++){
            int next = node[currentNode][i].second;
            long long nextDistance = node[currentNode][i].first + currentDistance;

            if(nextDistance < foxResult[next]){
                foxResult[next] = nextDistance;
                pq.push(make_pair(-nextDistance, next));
            }
        }
    }
}

void wolfDijkstra(int start){
    const int fast = 0;
    const int slow = 1;
    priority_queue<pair<pair<long long, int>, int>> pq; // <dis , node>, turn

    for(int i = 0; i < stump+1; i++){
        wolfResult[fast][i] = INF;
        wolfResult[slow][i] = INF;
    }
    
    
    pq.push(make_pair(make_pair(0, start), fast));
    
    while(!pq.empty())
    {
        int currentNode = pq.top().first.second;
        long long currentDistance = -pq.top().first.first;
        int turn = pq.top().second;

        pq.pop();
        
        if(currentDistance > wolfResult[turn][currentNode])continue;
        
        for(int i = 0; i < node[currentNode].size(); i++){
            int next = node[currentNode][i].second;
            long long nextDistance;
            if(turn == fast)nextDistance = node[currentNode][i].first/2 + currentDistance;
            else nextDistance = node[currentNode][i].first*2 + currentDistance;
            
            if(wolfResult[!turn][next] > nextDistance){
                wolfResult[!turn][next] = nextDistance;
                pq.push(make_pair(make_pair(-nextDistance, next), (!turn)));
            }
        }
    }
}


int main(){
    cin >> stump >> path;
    node = new vector<pair<int ,int>>[stump+1];
    foxResult = new long long[stump+1];
    wolfResult = new long long*[stump+1];
    wolfResult[0] = new long long[stump+1];
    wolfResult[1] = new long long[stump+1];

    for(int i = 0; i < path; i++){
        int src, dest, dis;
        cin >> src >> dest >> dis;

        node[src].push_back(make_pair(dis*2, dest));
        node[dest].push_back(make_pair(dis*2, src));
    }

    foxDijkstra(1);
    for(int i = 0; i < stump + 1; i++){
        cout << foxResult[i] << " ";
    }
    cout << "\n";


    wolfDijkstra(1);
    for(int i = 0; i < stump + 1; i++){
        cout << wolfResult[0][i] << " ";
    }
    cout << "\n";
    for(int i = 0; i < stump + 1; i++){
        cout << wolfResult[1][i] << " ";
    }
    cout << "\n";

    int cnt = 0;
    for(int i = 2; i < stump + 1; i++){
        if(min(wolfResult[0][i], wolfResult[1][i]) > foxResult[i])cnt++;
    }
    cout << cnt;
}