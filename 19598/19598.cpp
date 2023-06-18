#include <iostream>
#include <queue>

using namespace std;

priority_queue<pair<int, int>, vector<pair<int,int>>,greater<pair<int,int>>> q;
vector<int> room;
int n;

void input(){
    cin >> n;
    int start, end;
    for(int i = 0; i < n; i++){
        cin >> start >> end;
        q.push({start, end});
        
    }
    room.push_back(0);
}
int searchRoom(int start){
    for(int i = 0; i < room.size(); i++){
        if(room[i] <= start)return i;
    }
    return -1;
}

void solve(){
    while(!q.empty()){
        int start = q.top().first;
        int end = q.top().second;
        q.pop();

        int index = searchRoom(start);
        if(index == -1)room.push_back(end);
        else room[index] = end;
    }
    cout << room.size();
}

int main(){
    input();
    solve();
}