#include <iostream>
#include <queue>

using namespace std;

queue<pair<int, int>> q;
int N, L, R, SUM;

struct node{
    int population;
    int visit;
};

void search(node ** board, int x, int y, int count)
{
    //방문했거나 좌표 벗어나면 끝
    if(x == -1 || y == -1 || x == N || y == N || board[y][x].visit == count)return;
    q.push(make_pair(x, y));
    board[y][x].visit = count;
    SUM += board[y][x].population;

    if(x + 1 != N && abs(board[y][x].population - board[y][x+1].population) >= L && 
    abs(board[y][x].population - board[y][x+1].population) <= R){
        search(board, x + 1, y, count);
    }
    if(x - 1 != -1 && abs(board[y][x].population - board[y][x-1].population) >= L && 
    abs(board[y][x].population - board[y][x-1].population) <= R){
        search(board, x - 1, y, count);
    }
    if(y + 1 != N && abs(board[y][x].population - board[y+1][x].population) >= L && 
    abs(board[y][x].population - board[y+1][x].population) <= R){
        search(board, x, y + 1, count);
    }
    if(y - 1 != -1 && abs(board[y][x].population - board[y-1][x].population) >= L && 
    abs(board[y][x].population - board[y-1][x].population) <= R){
        search(board, x, y - 1, count);
    }
}

int main()
{
    node ** board;
    int count = 0;

    cin >> N >> L >> R;
    
    board = new node*[N];
    for(int i = 0; i < N; i++)board[i] = new node[N];

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> board[j][i].population;
            board[j][i].visit = -1;
        }
    }

    int avg, check;
    while(1){
        check = 1;
        for(int y = 0; y < N; y++){
            for(int x = 0; x < N; x++){
                if(board[y][x].visit == count)continue;
                search(board, x, y, count);
                avg = SUM / q.size();
                check = check / q.size();
                while(!q.empty())
                {
                    pair<int, int> dots= q.front();
                    q.pop();
                    board[dots.second][dots.first].population = avg;
                }
                SUM = 0;
            }
        }
        for(int y = 0; y < N; y++){
            for(int x = 0; x < N; x++){
                cout << board[y][x].population << " ";
            }
            cout << "\n";
        }   
        if(check == 1)break;
        count++;
        


 
    }
    
    cout << "count : " << count << "\n";
}