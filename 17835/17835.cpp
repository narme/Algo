#include <algorithm>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

vector<pair<int, int>> *node; // <거리 , 노드>
long long *result;
int *room;
long long INF = 0x7fffffffffffffff;
int v, e, p; // 도시수, 도로수, 면접장

int answerNode;
long long answerDistance = 0;

bool dijkstra(){
    int currentNode, next;
    long long currentDistance, nextDistance;

    for(int i = 0; i < v+1; i++)result[i] = INF;
    
    priority_queue<pair<long long, int>> pq; // dis , node
    for(int i = 0; i < p; i++){
        pq.push(make_pair(0, room[i]));
        result[room[i]] = 0;
    }
    
    
    while(!pq.empty())
    {
        currentNode = pq.top().second;
        currentDistance = -pq.top().first;
        pq.pop();
        
        if(currentDistance > result[currentNode])continue;

        for(int i = 0; i < node[currentNode].size(); i++){
            next = node[currentNode][i].second;
            nextDistance = node[currentNode][i].first + currentDistance;

            if(nextDistance < result[next]){
                result[next] = nextDistance;
                pq.push(make_pair(-nextDistance, next));
            }
        }
    }
    return true;
}

int main(){
    cin.tie(NULL), cout.tie(NULL);
    cin >> v >> e >> p;
    node = new vector<pair<int ,int>>[v+1];
    result = new long long[v+1];
    room = new int[p];

    for(int i = 0; i < e; i++){
        int src, dest, dis;
        cin >> src >> dest >> dis;
        node[dest].push_back(make_pair(dis, src));
    }
    for(int i = 0; i < p; i++){
        cin >> room[i];
    }

    dijkstra();

    for(int i = 0; i < v+1; i++){
        //cout << " " << result[i];
        if(answerDistance < result[i] && result[i] != INF){
            answerNode = i;
            answerDistance = result[i];
        }
    }

    cout << "\n" << answerNode << "\n" << answerDistance;
}