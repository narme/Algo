#include <iostream>
#include <queue>
#include <memory.h>

using namespace std;

vector<pair<int, int>> *island; // to, weight
int *jewelryIslandList;
int islandNumber, bridgeNumber, jewelryNumber;
bool **visit;

bool isJewelryIsland(int island){
    for(int i = 0; i < jewelryNumber; i++){
        if(jewelryIslandList[i] == island)return true;
    }
    return false;
}
int getJewelryIndex(int island){
    for(int i = 0; i < jewelryNumber; i++){
        if(jewelryIslandList[i] == island)return i;
    }
    return -1;
}

int BFS(int start){
    int answer = 0;
    queue<pair<int, pair<int, int>>> q; // 섬 , 보석 수, 보석 종류

    q.push(make_pair(start, make_pair(0, 0)));
    while(!q.empty()){
        int current = q.front().first;
        int getJewelryNumber = q.front().second.first;
        int jewelryKey = q.front().second.second;

        q.pop();

        //탐색 다하고 돌아온 경우
        if(current == start && answer < getJewelryNumber){
            answer = getJewelryNumber;
        }
        
        if(visit[current][jewelryKey])continue;
        visit[current][jewelryKey] = true;

        for(auto next : island[current]){
            int nextIsland = next.first;
            int nextIslandWeight = next.second;
            // 줍지 않고 이동, 방문하지 않고 가진보석이 가중치보다 작음.
            if(!visit[nextIsland][jewelryKey] && nextIslandWeight >= getJewelryNumber){   
                q.push(make_pair(nextIsland, make_pair(getJewelryNumber, jewelryKey)));
            }
            // 다음 섬에 보석이 있어서 줍는 경우
            if(isJewelryIsland(nextIsland)){
                int jewelryIndex = getJewelryIndex(nextIsland);
                int newkey = jewelryKey + (1 << jewelryIndex);
                if((jewelryKey & (1 << jewelryIndex)) || visit[nextIsland][newkey] || (nextIslandWeight < getJewelryNumber+1 && nextIsland != start))continue;
                q.push(make_pair(nextIsland, make_pair(getJewelryNumber+1, newkey)));                
            }
        }
    }
    return answer;
}



int main(){
    cin >> islandNumber >> bridgeNumber >> jewelryNumber;

    island = new vector<pair<int ,int>>[islandNumber+1];
    visit = new bool *[islandNumber + 1];
    
    int visitSize = (1 << jewelryNumber) + 1;
    for(int i = 0; i < islandNumber + 1; i++){
        visit[i] = new bool[visitSize];
        memset(visit[i], false, sizeof(bool)*visitSize);
    }
    jewelryIslandList = new int[jewelryNumber];
    //보석 입력
    for(int i = 0; i < jewelryNumber; i++)cin >> jewelryIslandList[i];
    
    //다리 입력
    for(int i = 0; i < bridgeNumber; i++){
        int i1, i2, w;
        cin >> i1 >> i2 >> w;

        island[i1].push_back(make_pair(i2, w));
        island[i2].push_back(make_pair(i1, w));
    }


    
    cout << BFS(1);

}