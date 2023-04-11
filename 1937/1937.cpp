#include <iostream>

using namespace std;

int n;
int **board, **dp;

void print(int **board, int n){
    for(int y = 0; y < n; y++){
        for(int x = 0; x < n; x++)cout << board[y][x] << " ";
        cout << "\n";
    }
    cout <<"---------------------------------\n";
}

int search(int x, int y){
    if(dp[y][x] == -1)dp[y][x] = 1;
    else return dp[y][x];

    if(x + 1 != n){
        if(board[y][x] < board[y][x + 1])dp[y][x] = max(dp[y][x],search(x + 1, y) + 1);
    }
    if(x - 1 != -1){
        if(board[y][x] < board[y][x - 1])dp[y][x] = max(dp[y][x],search(x - 1, y) + 1);
    }
    if(y + 1 != n){
        if(board[y][x] < board[y + 1][x])dp[y][x] = max(dp[y][x],search(x, y + 1) + 1);
    }
    if(y - 1 != -1){
        if(board[y][x] < board[y - 1][x])dp[y][x] = max(dp[y][x],search(x, y - 1) + 1);
    }
    
    //막다른곳
    return dp[y][x];
}



int main(){
    int max = 0;

    cin >> n;
    board = new int *[n];
    dp = new int *[n];

    for(int y = 0; y < n; y++){
        board[y] = new int[n];
        dp[y] = new int[n];

        for(int x = 0; x < n; x++){
            cin >> board[y][x];
            dp[y][x] = -1;
        }
    }

    for(int y = 0; y < n; y++){
        for(int x = 0; x < n; x++){
            //cout << y << " " << x << "\n";
            search(x, y);
            if(max < dp[y][x])max = dp[y][x];
            print(dp, n);
        }
    }

    cout << max;
}