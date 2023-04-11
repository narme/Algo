#include <iostream>
#include <string.h>

using namespace std;

int n, answer;


void printBoard(int ** board){
    for(int y = 0; y < n; y++){
        for(int x = 0; x < n; x++){
            cout << board[y][x] << " ";
        }
        cout << "\n";
    }
        
}

void calcMax(int ** board){
    for(int y = 0; y < n; y++){
        for(int x = 0; x < n; x++){
            if(answer < board[y][x])answer = board[y][x];
        }
    }
}


void spinBoard(int ** board, int time)
{
    int **temp;

    temp = new int *[n];
    for(int i = 0; i < n; i++)temp[i] = new int[n];

    
    for(int t = 0; t < time; t++){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++)temp[i][j] = board[n - j -1][i];
        }
        //copy
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++)board[i][j] = temp[i][j];
        }
    }
    
}

void moveBoard(int ** beforeBoard, int ** afterBoard, int direction)
{
    for(int y = 0; y < n; y++){
        for(int x = 0; x < n; x++){
            afterBoard[y][x] = beforeBoard[y][x];
        }
    }

    //printBoard(afterBoard);
    //방향에 따라 회전
    spinBoard(afterBoard, direction);
    //이동
    //printBoard(afterBoard);
    int * temp = new int[n];
    
    for(int y = 0; y < n; y++){
        int index = n - 1;
        memset(temp, 0, sizeof(int)*n);

        for(int x = n - 1; x >= 0; x--){
            if(temp[index] == 0){
                temp[index] = afterBoard[y][x];
            }
            else if(temp[index] == afterBoard[y][x]){
                temp[index] = temp[index] + afterBoard[y][x];
                index--;
            }else if(afterBoard[y][x] != 0){
                index--;
                temp[index] = afterBoard[y][x];
            }
        }
        for(int x = n - 1; x >= 0; x--)afterBoard[y][x] = temp[x];

    }
    //다시 회전해서 원래대로
    //printBoard(afterBoard);
    spinBoard(afterBoard, 4 - direction);
    //printBoard(afterBoard);
}


void func2048(int ** board, int round, int direction)
{
    //end
    if(round == 5){
        calcMax(board);
        return;
    }
    int ** afterBoard;
    

    afterBoard = new int *[n];
    for(int y = 0; y < n; y++){
        afterBoard[y] = new int[n];
    }
    

    moveBoard(board, afterBoard, direction);
    cout << "round  :  " << round << " direction : "  << direction << "\n";
    printBoard(afterBoard);
    getchar();
    //ㅏ
    func2048(afterBoard, round+1, 0);
    //ㅗ
    func2048(afterBoard, round+1, 1);
    //ㅓ
    func2048(afterBoard, round+1, 2);
    //ㅜ
    func2048(afterBoard, round+1, 3);
}

int main()
{
    int **board;
    
    cin >> n;

    board = new int *[n];

    for(int y = 0; y < n; y++){
        board[y] = new int[n];
        for(int x = 0; x < n; x++){
            cin >> board[y][x];
        }
    }

    if(n == 1){
        cout << board[0][0];
        return 0;
    }
    for(int i = 0; i < 4; i++){
        //func2048(board, 0, i);
    }
    func2048(board, 0, 1);
    cout << answer;
}