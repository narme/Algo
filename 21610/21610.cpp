#include <iostream>
#include <queue>

using namespace std;

int board[50][50];
bool cloud[50][50];

int n, m;
int dx[9] = {0, -1, -1, 0, 1, 1, 1, 0, -1};
int dy[9] = {0, 0, -1, -1, -1, 0, 1, 1, 1};

int nx[4] = {0, 1, 0, 1};
int ny[4] = {-2, -2, -1, -1};

queue<pair<int, int>> q;
queue<pair<int, int>> cloudxy;

void input(){   
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> board[i][j];

    int d, s;
    for(int i = 0; i < m; i++){
        cin >> d >> s;
        q.push(make_pair(d, s));
    }
}
void init(){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cloud[i][j] = 0;
        }
    }
}
bool isOut(int x, int y){
    if(x >= n || y >= n || x < 0 || y < 0)return true;
    else return false;
}

void move(int d, int s){
    int cx, cy;
    while(!cloudxy.empty()){
        cy = cloudxy.front().first;
        cx = cloudxy.front().second;
        cloudxy.pop();

        cx = cx + dx[d] * s;
        cy = cy + dy[d] * s;
        while(cx < 0)cx += n;
        while(cy < 0)cy += n;
        
        cx = cx % n;
        cy = cy % n; 

        board[cy][cx]++;
        cloud[cy][cx] = true;
    }
}

void copy(){
    queue<int> c;
    int diagonal[4] = {2, 4, 6, 8};
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(!cloud[i][j]){
                c.push(0);
                continue;
            }
            int cnt = 0;
            for(int z = 0; z < 4; z++){
                int cy = i + dy[diagonal[z]];
                int cx = j + dx[diagonal[z]];
                if(!isOut(cy, cx))
                    if(board[cy][cx] > 0)cnt++;
            }
            c.push(cnt);
        }
    }
    int i = 0;
    while(!c.empty()){
        board[i/n][i%n] += c.front();
        c.pop();
        i++;
    }
}
void decrease(){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(board[i][j] >= 2 && !cloud[i][j]){
                board[i][j] -= 2;
                cloudxy.push({i, j});
            }
        }
    }
}

void solve(){
    int d, s;
    for(int i = 0; i < 4; i++){
        cloudxy.push({n+ny[i], nx[i]});
    }
    
    while(!q.empty()){
        d = q.front().first;
        s = q.front().second;
        q.pop();

        init();
        move(d, s);
        copy();
        decrease();
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++)cout << board[i][j] << " ";
            cout << "\n";
        }
        cout << "\n";
    }
    int cnt = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++)cnt += board[i][j];
    }
    cout << cnt;
}

int main(){
    input();
    solve();
}