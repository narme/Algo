#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
    int n, m, answer = 50*50;
    char board[50][50];

    cin >> n;
    cin >> m;
    

    for(int i = 0; i < n; i++){
        cin >> board[i];
    }
    
    for(int c = 0; c <= n - 8; c++){
        for(int r = 0; r <= m - 8; r++){
            char temp = 'B';
            int a1 = 0, a2 = 0;
            for(int i = 0; i < 8; i++){
                for(int j = 0; j < 8; j++){
                    if(board[c+i][r+j] != temp)a1++;
                    temp = temp == 'W' ? 'B' : 'W';
                }
                temp = temp == 'W' ? 'B' : 'W';
            }


            temp = 'W';
            for(int i = 0; i < 8; i++){
                for(int j = 0; j < 8; j++){
                    if(board[c+i][r+j] != temp)a2++;
                    temp = temp == 'W' ? 'B' : 'W';
                }
                temp = temp == 'W' ? 'B' : 'W';
            }   
            int a3 = min(a1, a2);
            answer = min(a3, answer);
        }
       
    }


    cout << answer;
    return 0;
}

