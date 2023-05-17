#include <iostream>
#include <vector>
#define MAXSIZE 300
using namespace std;

int board[MAXSIZE+1][MAXSIZE+1];
int dp[11][MAXSIZE+1][MAXSIZE+1];
int n, q, maxn;

bool isOut(int x, int y){
    if(x == 0 || y == 0)return true;
    else return false;
}

int calc(int n, int x, int y){    
    int dx[3] = {-1, 0, -1};
    int dy[3] = {0, -1, -1};
    int result = 0;
    for(int i = 0; i < 2; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        //if(isOut(nx, ny))continue;
        //else result = max(result, dp[n][ny][nx]);
        result += dp[n][ny][nx];
    }
    result -= dp[n][y+dy[2]][x+dx[2]];
    return result;
}

void input(){
    cin >> n;
    
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> board[i][j];
            maxn = max(board[i][j], maxn);
        }
    }
}
void printdp(){
    for(int number = 1; number <= maxn; number++){
        cout << "-------" << number << "-------\n";
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                cout << dp[number][i][j] << " ";
            }
            cout << "\n";
        }
    }
}

void solve(){
    //set dp
    for(int i = 1; i <= maxn; i++){
        for(int y = 1; y <= n; y++){
            for(int x = 1; x <= n; x++){
                dp[i][y][x] = calc(i, x, y);
                dp[i][y][x] += board[y][x] == i;
            }
        }
    }
    //printdp();
    int x1, y1, x2, y2;
    cin >> q;
    vector<int> answer;
    for(int i = 0; i < q; i++){
        cin >> x1 >> y1 >> x2 >> y2;
        int sum = 0;
        for(int number = 1; number <= maxn; number++){
            sum += (dp[number][x2][y2] - dp[number][x2][y1-1] - dp[number][x1-1][y2] + dp[number][x1-1][y1-1]) > 0;
        }
        answer.push_back(sum);
    }

    for(auto i : answer){
        cout << i << "\n";
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    input();
    solve();
}