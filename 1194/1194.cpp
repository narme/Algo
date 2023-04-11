#include <iostream>
#include <vector>
#include <time.h>
#include <queue>

using namespace std;

//abcdef
#define A 0b00000001
#define B 0b00000010
#define C 0b00000100
#define D 0b00001000
#define E 0b00010000
#define F 0b00100000

char **board;
int width, height, answer;
int key[6] = {A, B, C, D, E, F};
queue<pair<int, int>> xyQueue;
queue<pair<int, int>> infoQueue;

void print(){
    for(int y = 0; y < height; y++){
        for(int x = 0; x < width; x++)cout << board[y][x] << " ";
        cout << "\n";
    }
}

void printVector(vector<vector<int> >visited){
        for(int y = 0; y < height; y++){
            for(int x = 0; x < width; x++)cout << visited[y][x] << " ";
            cout << "\n";
    }
}
bool outOfrange(int x, int y)
{
    if(y == height || y == -1 || x == width || x == -1)return true;
    else return false;
}


void searchDFS(int x, int y, int keylist, int moveCnt, vector<vector<int> >visited){
    if(outOfrange(x, y) || visited[y][x] != 0)return;
    if(board[y][x] == '#' || moveCnt > answer)return;
    if(board[y][x] == '1'){
        answer = min(moveCnt, answer);
        return;
    }

    visited[y][x] = 1;

    //처음 KEY를 줍는 경우
    if(board[y][x] >= 'a' && board[y][x] <= 'f'){
        if((key[board[y][x]-'a'] & keylist) == 0){
            keylist += key[board[y][x]-'a'];
            visited.assign(height, vector<int> (width, 0));
        }
    }

    //문인 경우
    if(board[y][x] >= 'A' && board[y][x] <= 'F'){
        //열쇄가 없으면
        if((key[board[y][x]-'A'] & keylist) == 0)return;
    }
    
    searchDFS(x + 1, y, keylist, moveCnt + 1, visited);
    searchDFS(x, y + 1, keylist, moveCnt + 1, visited);
    searchDFS(x - 1, y, keylist, moveCnt + 1, visited);
    searchDFS(x, y - 1, keylist, moveCnt + 1, visited);
}
int Xdirection[4] = {0, 0, -1, 1};
int Ydirection[4] = {-1, 1, 0, 0};
bool visited[50][50][64];

int searchBFS(){
    while(xyQueue.empty() == 0 || infoQueue.empty() == 0)
    {
        int x = xyQueue.front().first;
        int y = xyQueue.front().second;
        int keyList = infoQueue.front().first;
        int cnt = infoQueue.front().second;
        
        cout << x << " , " << y << "\n";
        cout << "q size : " << xyQueue.size() << "\n";
        
        if(board[y][x] == '1')return cnt;
        for(int i = 0; i < 4; i++)
        {
            int nx = x + Xdirection[i];
            int ny = y + Ydirection[i];
            int tempKeyList = keyList;

            //방문 or 막다른길
            if(outOfrange(nx, ny))continue;
            if(board[ny][nx] == '#' || visited[ny][nx][keyList])continue;

            visited[ny][nx][keyList] = true;
            //문인 경우
            if(board[ny][nx] >= 'A' && board[ny][nx] <= 'F'){
                //열쇄가 없으면
                if((key[board[ny][nx]-'A'] & keyList) == 0)continue;;
            }

            //키를 처음 줍는경우
            else if(board[ny][nx] >= 'a' && board[ny][nx] <= 'f'){
                if((key[board[ny][nx]-'a'] & keyList) == 0){
                    tempKeyList += key[board[ny][nx]-'a'];
                }
            }
            xyQueue.push(make_pair(nx, ny));
            infoQueue.push(make_pair(tempKeyList, cnt + 1));
        }
        xyQueue.pop();
        infoQueue.pop();
    }
    return -1;
}



int main(){
    int startX, startY;
    vector<vector<int>> visited;
    
    
    cin >> height >> width;
    answer = 0x7fffffff;

    board = new char* [height];
    for(int y = 0; y < height; y++){
        board[y] = new char[width];
        for(int x = 0; x < width; x++){
            cin >> board[y][x];
            if(board[y][x] == '0')startX = x, startY = y;
        }
    }
    /*
    visited.assign(height, vector<int> (width, 0));
    clock_t start = clock();
    searchDFS(startX, startY, 0, 0, visited);
    clock_t end = clock();

    if(answer == 0x7fffffff)cout << "-1";
    else cout << answer;

    cout << "\nDFS time : " << double(end - start) / CLOCKS_PER_SEC << "\n";
    
*/
    clock_t start = clock();
    xyQueue.push(make_pair(startX, startY));
    infoQueue.push(make_pair(0, 0));
    answer = searchBFS();
   
    clock_t end = clock();

    cout << answer;
    cout << "\nBFS time : " << double(end - start) / CLOCKS_PER_SEC << "\n";   
}