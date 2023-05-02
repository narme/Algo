#include <iostream>
#include <queue>
#define down 0
#define right 1

using namespace std;

int H, W, N;
int **board, **dp;

void input()
{
    cin >> H >> W >> N;

    board = new int *[H];
    for (int i = 0; i < H; i++)
    {
        board[i] = new int[W];
        for (int j = 0; j < W; j++)
        {
            cin >> board[i][j];
        }
    }
}
bool isOut(int x, int y)
{
    if (x == W || y == H)
        return true;
    else
        return false;
}

/*
void change(int *road, int cnt){
    *road = *road + cnt % 2;
    *road = *road % 2;
}
void changeBoard(){
    bool **visit;
    int direction[4] = {1,0,0,1};
    queue<pair<pair<int , int>, int>> q; // x , y , cnt

    q.push({{0, 0}, N-1});
    visit = new bool*[H];
    for(int i = 0; i < H; i++){
        visit[i] = new bool[W];
        for(int j = 0; j < W; j++)visit[i][j] = false;
    }

    while(!q.empty()){
        int x = q.front().first.first;
        int y = q.front().first.second;
        int cnt = q.front().second;

        int type = board[y][x] == down ? down : right;
        q.pop();

        //if(visit[y][x])continue;
        //else visit[y][x] = true;
        if(cnt == 0)continue;
        change(&board[y][x], cnt);
        //cout << x << " , " << y << " : " <<  type << " cnt : " << cnt << "\n";
        // i = 0 아래, i = 1 오른쪽
        for(int i = 0; i < 2; i++){
            int nx = x + direction[i*2+1];
            int ny = y + direction[i*2];
            if(isOut(nx, ny))continue;

            int ncnt = cnt / 2;
            //시작 방향이 아래인 경우 아래쪽에 + 1
            if(type == down && i == 0 && cnt % 2 != 0)ncnt++;
            if(type == right && i == 1 && cnt % 2 != 0)ncnt++;

            //cout << "push  x : " << nx << " y : " << ny << " cnt : " << ncnt << "\n";
            q.push({{nx, ny}, ncnt});
        }
    }
}
*/
void printboard()
{
    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < W; j++)
        {
            cout << board[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

void calcVisitCount(){
    int direction[4] = {1,0,0,1};

    dp = new int *[H];
    for (int i = 0; i < H; i++)
    {
        dp[i] = new int[W];
        for (int j = 0; j < W; j++)
        {
            dp[i][j] = 0;
        }
    }

    dp[0][0] = N - 1;
    for (int y = 0; y < H; y++)
    {
        for (int x = 0; x < W; x++)
        {
            for (int i = 0; i < 2; i++)
            {
                int nx = x + direction[i * 2 + 1];
                int ny = y + direction[i * 2];
                int cnt = dp[y][x] / 2;

                if (isOut(nx, ny))
                    continue;

                if (board[y][x] == down && i == 0 && dp[y][x] % 2 != 0)
                    cnt++;
                if (board[y][x] == right && i == 1 && dp[y][x] % 2 != 0)
                    cnt++;

                dp[ny][nx] += cnt;
            }
        }
    }
}

void changeBoard(){
    for(int y = 0; y < H; y++){
        for(int x = 0; x < W; x++){
            board[y][x] += dp[y][x] % 2;
            board[y][x] %= 2;
        }
    }
}

void solve()
{
    calcVisitCount();
    changeBoard();
    printboard();

    int x = 0, y = 0;
    while (!isOut(x, y))
    {
        if (board[y][x] == down)
            y++;
        else if (board[y][x] == right)
            x++;
    }

    cout << y + 1 << " " << x + 1;
}

int main()
{
    input();
    solve();
}