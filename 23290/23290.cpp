#include <iostream>
#include <vector>

#define MAXSIZE 5

using namespace std;

typedef struct fish{
    int x, y;
    int dir;
}fish;

vector<fish> map[MAXSIZE][MAXSIZE], cmap[MAXSIZE][MAXSIZE];
pair<int, int> shark;

int M, S;

void printMap(vector<fish> m[][MAXSIZE]){
    for(int i = 1; i < MAXSIZE; i++){
        for(int j = 1; j < MAXSIZE; j++)cout << m[i][j].size() << " ";
        cout << "\n";
    }
}

void input(){
    cin >> M >> S;
    int x, y, dir;
    for(int i = 0; i < M; i++){
        cin >> y >> x >> dir;
        fish t = {x, y, dir};
        map[y][x].push_back(t);
    }
    cin >> y >> x;
    shark = {x, y};
}

void copy(vector<fish> src[][MAXSIZE], vector<fish> dis[][MAXSIZE]){
    for(int i = 1; i < MAXSIZE; i++){
        for(int j = 1; j < MAXSIZE; j++)dis[i][j] = src[i][j];
    }
}
// 1 2 3 4 5 6 7 8 방향
int dirx[] = { 0, -1, -1, 0, 1, 1, 1, 0, -1 };
int diry[] = { 0, 0, -1, -1, -1, 0, 1, 1, 1 };

int smell[MAXSIZE][MAXSIZE];

bool isOut(int x, int y){
    if(x > 4 || y > 4 || x < 1 || y < 1)return true;
    else return false;
}
int changeDir(int dir){
    switch (dir)
    {
    case 1:
        return 8;
    case 2:
        return 1;
    case 3:
        return 2;
    case 4:
        return 3;
    case 5:
        return 4;
    case 6:
        return 5;        
    case 7:
        return 6;
    case 8:
        return 7;
    default:
        break;
    }
    return 0;
}

void moveFish(){
    vector<fish> tmp[MAXSIZE][MAXSIZE];
    //cout << "shark : x " << shark.first << " y : " << shark.second << "\n";
    for(int i = 1; i < MAXSIZE; i++){
        for(int j = 1; j < MAXSIZE; j++){
            for(fish cfish : map[i][j]){
                int x = cfish.x;
                int y = cfish.y;
                int dir = cfish.dir;
                //cout << "fish : x " << cfish.x << " y : " << cfish.y << " dir : " << cfish.dir << "\n";
                int nx, ny;
                bool canMove = false;
                for(int i = 0; i < 8; i++){
                    nx = x + dirx[dir];
                    ny = y + diry[dir];
                    //상어가 없고 냄새가 없어야됨

                    if((shark.first != nx || shark.second != ny) && smell[ny][nx] == 0 && !isOut(nx, ny)){
                        fish t = {nx, ny, dir};
                        tmp[ny][nx].push_back(t);
                        canMove = true;
                        //cout << "moveedfish : x " << nx << " y : " << ny << " dir : " << dir << "\n";
                        break;
                    //그렇지않으면 방향 전환    
                    }else{
                        dir = changeDir(dir);
                    }
                }
                if(!canMove){
                    fish t = {x, y, dir};
                    tmp[i][j].push_back(t);
                }
            }
        }
    }
    //printMap(map);
    //cout << "----------------\n";
    copy(tmp, map);
    //printMap(map);
}

int sdirx[] = {0, -1, 0, 1};
int sdiry[] = {-1, 0, 1, 0};

int sharkRoute[3], sharkTempRoute[3];

int howManyEat(){
    int x = shark.first;
    int y = shark.second;
    int cnt = 0;
    vector<fish> tmp[MAXSIZE][MAXSIZE];
    copy(map, tmp);
    for (int i = 0; i < 3; i++) {
        int dir = sharkTempRoute[i];
        int nx = x + sdirx[dir];
        int ny = y + sdiry[dir];
        
        if(isOut(nx, ny))return -1;
        cnt += tmp[ny][nx].size();
        tmp[ny][nx].clear();
        x = nx;
        y = ny;
    }
    return cnt;
}
void findRoute(){
    int eat, maxeat = -1;
    for(int i = 0; i < 4; i++){
        sharkTempRoute[0] = i;
        for(int j = 0; j < 4; j++){
            sharkTempRoute[1] = j;
            for(int z = 0; z < 4; z++){
                sharkTempRoute[2] = z;
                eat = howManyEat();
                if(eat > maxeat){
                    maxeat = eat;
                    for(int r = 0; r < 3; r++)sharkRoute[r] = sharkTempRoute[r];
                }
            }
        }
    }
}

void moveShark(int time){
    findRoute();
    //cout << sharkRoute[0] << " " << sharkRoute[1] << " " << sharkRoute[2] << "\n";
    vector<fish> tmp[MAXSIZE][MAXSIZE];
    copy(map, tmp);

    int x = shark.first;
    int y = shark.second;

    for(int i = 0; i < 3; i++){
        int dir = sharkRoute[i];
        int nx = x + sdirx[dir];
        int ny = y + sdiry[dir];

        //물고기가 있으면 먹기
        //cout << "fish : " << tmp[ny][nx].size() << "\n";
        if(tmp[ny][nx].size() != 0){
            smell[ny][nx] = time;
            tmp[ny][nx].clear();
        }
        x = nx, y = ny;
        shark = {x, y};
    }
    copy(tmp, map);
}

void deleteSmell(int t){
    for (int i = 1; i < MAXSIZE; i++) {
        for (int j = 1; j < MAXSIZE; j++) {
            if(isOut(j, i))continue;
            if (t - smell[i][j] == 2 && smell[i][j] != 0) {
                smell[i][j] = 0; 
            }
        }
    }
}

void reproduction(){
    for(int i = 1; i < MAXSIZE; i++){
        for(int j = 1; j < MAXSIZE; j++){
            for(int z = 0; z < cmap[i][j].size(); z++){
                map[i][j].push_back(cmap[i][j][z]);
            }
        }
    }
}
//현재 상태 복사 -> 물고기 이동 -> 상어이동(냠냠) -> 냄새제거 -> 복제 완료

int countFish(){
    int cnt = 0;
    for(int i = 1; i < MAXSIZE; i++){
        for(int j = 1; j < MAXSIZE; j++){
            cnt += map[i][j].size();
        }
    }
    return cnt;
}
void solve(){
    for(int i = 1; i <= S; i++){
        copy(map, cmap);
        moveFish();
        moveShark(i);
        deleteSmell(i);
        reproduction();
    }
    cout << countFish();
}

int main(){
    input();
    solve();
}