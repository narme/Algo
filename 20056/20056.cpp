#include <iostream>
#include <vector>

using namespace std;

struct fireball
{
    int d, s, m;
    
    fireball(int _d, int _s, int _m) : d(_d), s(_s), m(_m) {};
};

int n,f,k;
vector<fireball> board[50][50];
int dx[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};
int newd[2][4] = {{1, 3, 5, 7}, {0, 2, 4, 6}};

void input(){
    int x, y, d, s, m;
    cin >> n >> f >> k;
    
    for(int i = 0; i < f; i++){
        cin >> x >> y >> m >> s >> d;
        x = x - 1;
        y = y - 1;
        board[x][y].push_back(fireball(d, s, m));
    }
}

void move(){
    vector<fireball> temp[50][50];

    for(int x = 0; x < n; x++){
        for(int y = 0; y < n; y++){
            while(!board[x][y].empty()){
                fireball t = board[x][y].back();
                board[x][y].pop_back();
                int cx = x + dx[t.d] * t.s;
                int cy = y + dy[t.d] * t.s;
                while(!(cx >= 0 && cx < n))cx = (cx + n) % n;
                while(!(cy >= 0 && cy < n))cy = (cy + n) % n;
                temp[cx][cy].push_back(fireball(t.d, t.s, t.m));
            }
        }
    }
    //copy
    for(int x = 0; x < n; x++){
        for(int y = 0; y < n; y++){
            for(fireball e : temp[x][y]){
                board[x][y].push_back(e);
            }
        }
    }
}

void fusion(){
    for(int x = 0; x < n; x++){
        for(int y = 0; y < n; y++){
            int cnt = board[x][y].size();
            int sum_m = 0, sum_s = 0;
            if(cnt >= 2){
                bool same = true;
                int prev = -1;
                while(!board[x][y].empty()){
                    fireball t = board[x][y].back();
                    board[x][y].pop_back();
                    sum_m += t.m;
                    sum_s += t.s;
                    if(prev == -1)prev = t.d;
                    else if(same) same = prev % 2 == t.d % 2;
                }
                int new_m = sum_m / 5;
                int new_s = sum_s / cnt;
                if(new_m == 0)continue;
                else{
                    for(int i = 0; i < 4; i++){
                        board[x][y].push_back(fireball(newd[same][i], new_s, new_m));
                    }
                }
            }
        }
    }
}

int solve(){
    int sum = 0;
    for(int i = 0; i < k; i++){
        move();
        fusion();
    }

    for(int x = 0; x < n; x++){
        for(int y = 0; y < n; y++){
            while(!board[x][y].empty()){
                sum += board[x][y].back().m;
                board[x][y].pop_back();
            }
        }
    }
    return sum;
}

int main(){
    input();
    cout << solve();
}