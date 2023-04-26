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
    int n = 1000;

    vector<pair<int, int>> *node;
    node = new vector<pair<int ,int>>[n*n];
    result = new int*[n*n];
    result = new int[n*n];

    //노드 구성
    for(int y = 0; y < n; y++){
        for(int x = 0; x < n; x++){
            int nodeNumber = n * y + x;
            for(int i = 0; i < 4; i++){
                int nextX = directionX[i] + x;
                int nextY = directionY[i] + y;
                int nextNodeNumber = n * nextY + nextX;
                
                if(isOut(nextX, nextY))continue;
                else {
                    node[nodeNumber].push_back(make_pair(board[nextY][nextX], nextNodeNumber));     
                }
            }
        }
    }
}