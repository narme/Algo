#include <iostream>
#include <queue>

using namespace std;

queue<int> seq;
int n;
int favorite[401][4];
int board[21][21];
int directionX[4] = {-1, 1, 0, 0};
int directionY[4] = {0, 0, -1, 1};

struct seat {
    int f;  //favorite score
    int e;  //empty score
    int x, y;

    seat(int _f, int _e, int _x, int _y) : f(_f), e(_e), x(_x), y(_y) {}
};
struct comp{
    bool operator()(seat A, seat B)
    {
        if (A.f < B.f)return true;
        else if (A.f == B.f){
            if(A.e < B.e)return true;
            else if (A.e == B.e){
                if(A.y > B.y)return true;
                else if (A.y == B.y){
                    if(A.x > B.x)return true;
                    else return false;
                }else return false;
            }else return false;
        }
        else return false;
    }
    
};

void input(){
    int studentN;
    cin >> n;
    for(int i = 0; i < n*n; i++){
        cin >> studentN;
        seq.push(studentN);
        for(int j = 0; j < 4; j++){
            cin >> favorite[studentN][j];
        }
    }
}
bool isSeat(int x, int y){
    if(x >= n || x < 0 || y >= n || y < 0)return false;
    else return true;
}
bool isEmpty(int x, int y){
    if(board[y][x] == 0)return true;
    else return false;
}

void setup(){
    int sn, sx, sy;
    

    while(!seq.empty()){
        priority_queue<seat, vector<seat>, comp> pq;
        sn = seq.front();
        //cout << "sn : " << sn << "\n";
        seq.pop();

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                int f = 0, e = 0;
                if(!isEmpty(j, i))continue;
                for(int z = 0; z < 4; z++){
                    sx = j + directionX[z];
                    sy = i + directionY[z];
                    if(isSeat(sx, sy)){
                        if(isEmpty(sx, sy))e++;

                        for(auto k : favorite[sn]){
                            if(board[sy][sx] == k)f++;
                        }
                    }
                }
                //cout << i << " " << j << " " << f << " " << e << "\n";
                pq.push(seat(f, e, j, i));
            }
        }
        sx = pq.top().x;
        sy = pq.top().y;
        board[sy][sx] = sn;
        /*
        cout << "select : " << sx << " " << sy << "\n";
        cout << "--------------------------\n";
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++)
                cout << board[i][j] << " ";
            cout << "\n";
        }
        cout << "--------------------------\n";
        */
    }
}
int score(){
    int score = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            int cnt = 0;
            for(int z = 0; z < 4; z++){
                int sx = j + directionX[z];
                int sy = i + directionY[z];
                if(isSeat(sx, sy)){
                    for(auto f : favorite[board[i][j]]){
                        if(f == board[sy][sx])cnt++;
                    }
                }
            }
            if(cnt == 2)score+=10;
            else if(cnt == 3)score+=100;
            else if(cnt == 4)score+=1000;
            else score+=cnt;
        }
        
    }
    return score;
}

int main(){
    input();
    setup();
    cout << score();
}


