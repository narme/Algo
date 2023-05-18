#include <iostream>
#include <queue>
#include <memory.h>

#define maxsize 15

using namespace std;

int board[maxsize][maxsize];
bool dead[maxsize][maxsize];
bool visit[maxsize][maxsize];
int n, m, d;

void input(){
    cin >> n >> m >> d;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> board[i][j];
        }
    }
}
bool isOut(int x, int y){
    if(x < 0 || x == m || y < 0 || y >= n)return true;
    else return false;
}

int archer[3];
int answer;
int dx[3] = {-1, 0, 1};
int dy[3] = {0, -1, 0};

void simulation(){
    int count = 0;
    //적들이 밀려온다
    cout << "archer list : ";
    for(int i = 0; i < 3; i++)cout << archer[i] << " ";
    cout << "\n";
    for(int i = n; i > 0; i--){
        //궁수가 활을 쏜다
        vector<pair<int,int>> attack;
        for(int arh = 0; arh < 3; arh++){
            //공격 대상 탐색
            queue<pair<int, int>> q; // range , x, y;
            memset(visit, false, sizeof(bool)*maxsize*maxsize);
            q.push({archer[arh], i});
            int startx = archer[arh];
            int starty = i;
            while(!q.empty()){
                int cx = q.front().first;
                int cy = q.front().second;
                q.pop();
                //공격 대상 선택
                if(!isOut(cx, cy))visit[cy][cx] = true;
                if(!isOut(cx, cy + n - i) && board[cy][cx] == 1){
                    if(!dead[cy][cx]){
                        cout << n - i << "round  archer" << arh << " attack  x : " << cx << " y : " << cy << "\n";
                        attack.push_back({cx, cy});
                        break;
                    }
                    
                }
                for(int dir = 0; dir < 3; dir++){
                    int nx = cx + dx[dir];
                    int ny = cy + dy[dir];
                    int range = abs(nx - startx) + abs(ny - starty);
                    if(isOut(nx, ny) || range > d || visit[ny][nx])continue;
                    else q.push({nx, ny});
                }
            }
        }
        //일제히 공격
        for(auto i : attack){
            if(!dead[i.second][i.first]){
                count++;
                dead[i.second][i.first] = true;
            }
        }
    }
    
    cout << count << "\n";
    answer = max(answer, count);
}

void solve(){
    for(int i = 0; i < m - 2; i++){
        archer[0] = i;
        for(int j = i+1; j < m - 1; j++){
            archer[1] = j;
            for(int z = j+1; z < m; z++){
                archer[2] = z;
                //fill_n(&dead, maxsize*maxsize, false);
                memset(dead, false, sizeof(bool)*maxsize*maxsize);
                simulation();
            }
        }
    }
    cout << answer;
}

int main(){
    input();
    solve();
}