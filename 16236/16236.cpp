#include <iostream>
#include <queue>

using namespace std;

struct block
{
    int x, y, cnt;
    block(int _x, int _y, int _cnt) : x(_x), y(_y), cnt(_cnt) {};
    
};
struct comp
{
    bool operator()(block a, block b) const {
        if(a.cnt > b.cnt)return true;
        else if(a.cnt == b.cnt){
            if(a.y > b.y)return true;
            else if(a.y == b.y){
                if(a.x > b.x)return true;
                else return false;
            }
            else return false;
        }else return false;
    }
};

int board[20][20];
bool visit[20][20];

int n, sharkLevel, expp, sharkx, sharky;

int dx[4] = {0, -1, 1, 0};
int dy[4] = {-1, 0, 0, 1};

queue<block> q;
priority_queue<block, vector<block>, comp> eatList;

void input(){
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> board[i][j];
            if(board[i][j] == 9){
                board[i][j] = 0;
                sharkx = j;
                sharky = i;
            }
        }
    }
}
bool isOut(int x, int y){
    if(x >= n || y >= n || x < 0 || y < 0)return true;
    else return false;
}
void bfs(){
    q.push(block(sharkx, sharky, 0));
    cout << "start ! x : " <<  sharkx << " y : " << sharky << "\n";
    while(!q.empty()){
        int cx = q.front().x;
        int cy = q.front().y;
        int ccnt = q.front().cnt;
        //visit[cy][cx] = true;

        q.pop();

        for(int i = 0; i < 4; i++){
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            
            //범위 밖 or 지나갈 수 없는 경우, 이미 방문한 경우
            if(isOut(nx, ny) || board[ny][nx] > sharkLevel || visit[ny][nx])continue;
            //먹을 수 있는 경우
            visit[ny][nx] = true;
            if(board[ny][nx] < sharkLevel && board[ny][nx] != 0){
                eatList.push(block(nx, ny, ccnt+1));
            }else{
                q.push(block(nx, ny, ccnt+1));
            }
        }
    }
}
void init(){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++)visit[i][j] = false;
    }
    while(!eatList.empty())eatList.pop();
}

int eat(){
    block target = eatList.top();
    board[target.y][target.x] = 0;
    board[sharky][sharkx] = 0;

    sharkx = target.x;
    sharky = target.y;

    expp++;
    if(expp == sharkLevel){
        sharkLevel++;
        expp = 0;
    }
    return target.cnt;
}
void solve(){
    int times = 0;
    sharkLevel = 2;
    while(true){
        cout << "0a\n";
        bfs();
        cout << "a\n";
        if(eatList.size() == 0){
            cout << times;
            return;
        }
        cout << "b\n";
        times += eat();
        init();
        cout << "c\n";
    }
}

int main(){
    input();
    solve();
}