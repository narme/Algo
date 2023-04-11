#include <iostream>
#define SIZE 1000
int board[SIZE][SIZE] = {-1,};
int answer[SIZE][SIZE] = {0,};
using namespace std;

int main()
{
    int N, M;

    cin >> N;
    cin >> M;

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++)
            cin >> board[i][j];
    }
    for(int i = 1; i < N; i++)board[i][0] = board[i-1][0] + board[i][0];
    for(int i = 1; i < M; i++)board[0][i] = board[0][i] + board[0][i-1];

    for(int y = 1; y < N; y++){
        for(int x = 1; x < M; x++){
            board[y][x] = board[y][x] + max(board[y-1][x], board[y][x-1]);
        }
    }
    cout << board[N-1][M-1];

    return 0;
}

