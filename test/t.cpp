#include<iostream>
#include<queue>
#include<string>
#include<vector>
#include<cmath>
 
#define endl "\n"
#define MAX 50
using namespace std;
 
int N, M;
char MAP[MAX][MAX];
bool Visit[MAX][MAX][1 << 6];
 
pair<int, int> Start;
vector<pair<int, int>> End;
 
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };
 
void Input()
{
    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        string Inp; cin >> Inp;
        for (int j = 0; j < M; j++)
        {
            MAP[i][j] = Inp[j];
            if (MAP[i][j] == '0')
            {
                Start.first = i;
                Start.second = j;
                MAP[i][j] = '.';
            }
            else if (MAP[i][j] == '1')
            {
                End.push_back(make_pair(i, j));
            }
        }
    }
}
 
bool HaveThisKey(int Cur_Key, char Door)
{
    int R_Value = Cur_Key & (1 << (int(Door) - 'A'));
 
    if (R_Value != 0) return true;
    return false;
}
 
int BFS(int a, int b)
{
    queue<pair<pair<int, int>, pair<int, int>>> Q;
    queue<pair<int, int>> Door[26];
    Q.push(make_pair(make_pair(a, b), make_pair(0, 0)));
    Visit[a][b][0] = true;
 
    while (Q.empty() == 0)
    {
        int x = Q.front().first.first;
        int y = Q.front().first.second;
        int Cnt = Q.front().second.first;
        int Key = Q.front().second.second;
        Q.pop();

        cout << "q size : " << Q.size() << " , ";
        if (MAP[x][y] == '1') return Cnt;
 
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
 
            if(nx >= 0 && ny >= 0 && nx < N && ny< M)
            {
                if (Visit[nx][ny][Key] == false)
                {
                    if (MAP[nx][ny] == '.' || MAP[nx][ny] == '1')
                    {
                        Visit[nx][ny][Key] = true;
                        Q.push(make_pair(make_pair(nx, ny), make_pair(Cnt + 1, Key)));
                    }
                    else if ('a' <= MAP[nx][ny] && MAP[nx][ny] <= 'f')
                    {
                        int Tmp_Key = Key | (1 << (int(MAP[nx][ny] - 'a')));
                        Visit[nx][ny][Tmp_Key] = true;
                        Q.push(make_pair(make_pair(nx, ny), make_pair(Cnt + 1, Tmp_Key)));
                    }
                    else if ('A' <= MAP[nx][ny] && MAP[nx][ny] <= 'F')
                    {
                        if (HaveThisKey(Key, MAP[nx][ny]) == true)
                        {
                            Visit[nx][ny][Key] = true;
                            Q.push(make_pair(make_pair(nx, ny), make_pair(Cnt + 1, Key)));
                        }
                    }
                }
            }
        }
    }
    return -1;
}
 
void Solution()
{
    int R = BFS(Start.first, Start.second);
    cout << R << endl;
}
 
void Solve()
{
    Input();
    Solution();
}
 
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 
    //freopen("Input.txt", "r", stdin);
    Solve();
 
    return 0;
}
