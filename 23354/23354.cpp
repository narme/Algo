#include <algorithm>
#include <vector>
#include <queue>
#include <iostream>
#include <fstream>

using namespace std;

vector<int> deserterNodeNumber; //  탈영병 노드 번호
int militaryNodeNumber;
int **result;
int **board;
int INF = 0x7FFFFFFF;
int mINF = 0x70000000;
int directionX[4] = {1, -1, 0, 0};
int directionY[4] = {0, 0, 1, -1};

int n;

bool isOut(int x, int y){
    if(x >= n || x < 0 || y >= n || y < 0)return true;
    else return false;
}

void dijkstra(int ptr){
    int start;
    if(ptr == 0) start = militaryNodeNumber;
    else start = deserterNodeNumber[ptr-1];
    for(int i = 0; i < n*n; i++)result[ptr][i] = INF;
    result[ptr][start] = 0;
    priority_queue<pair<int, int>> pq; // dis , node
    pq.push(make_pair(0, start));
    
    while(!pq.empty())
    {
        int currentNode = pq.top().second;
        int currentDistance = -pq.top().first;
        pq.pop();
        
        if(currentDistance > result[ptr][currentNode])continue;

        for(int i = 0; i < 4; i++){
            int nextX = currentNode % n + directionX[i];
            int nextY = currentNode / n + directionY[i];

            if(isOut(nextX, nextY))continue;

            int next = nextY * n + nextX; // board[y][x]
            int nextDistance = board[nextY][nextX] + currentDistance;

            if(nextDistance < result[ptr][next]){
                result[ptr][next] = nextDistance;
                pq.push(make_pair(-nextDistance, next));
            }
        }
    }
}
void solve(){
    int size = deserterNodeNumber.size();
    if(size == 0){
        cout << 0;
        return;
    }

    result = new int*[size+1];
    for(int i = 0; i < size+1; i++){
        result[i] = new int[n*n];
        dijkstra(i);
    }
    
    int minimum = INF;
    vector<int> permutation;
    for(int i = 0; i < size; i++)permutation.push_back(i);

    do{
        int distance = 0;
        int startNode = permutation[0];

        //시작 지점(군 부대) -> N 탈영병 -> N + 1 탈영병 .... -> 군 부대
        distance += result[0][deserterNodeNumber[startNode]];
        for(int i = 0; i < size; i++){
            if(i == size - 1){
                distance += result[permutation[size-1] + 1][militaryNodeNumber];
                break;
            }
            int nextNode = deserterNodeNumber[permutation[i+1]];
            distance += result[permutation[i] + 1][nextNode];
        }

        
        if(minimum > distance){
            minimum = distance;
        }
    }while(next_permutation(permutation.begin(), permutation.end()));

    cout << minimum;
}



int main(){
    cin >> n;
    board = new int *[n];

    //입력 받기
    for(int y = 0; y < n; y++){
        board[y] = new int[n];
        for(int x = 0; x < n; x++){
            cin >> board[y][x];
            if(board[y][x] == 0)deserterNodeNumber.push_back(y * n + x);
            else if(board[y][x] == -1){
                militaryNodeNumber = y * n + x;
                board[y][x] = 0;
            }
        }
    }
    solve();
}