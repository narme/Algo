#include <iostream>

using namespace std;

#define LAND 0
#define WALL 1
#define VIRUS 2

struct node{
    int type;
    int visit;
};

int n, m;

void init(node ** board){
    for(int y = 0; y < n; y++){
        for(int x = 0; x < m; x++)board[y][x].visit = 0;
    }
}

//감염 : 0 , 감염 x : 1
int safeZone, infected;

void search(node ** board, int x, int y){
    if(y == n || y == -1 || x == m || x == -1)return;
    if(board[y][x].type == VIRUS){
        infected = 0;
        return;
    }
    if(board[y][x].type == WALL || board[y][x].visit == 1)return;

    board[y][x].visit = 1;
    safeZone++;

    search(board, x + 1, y);
    search(board, x, y + 1);
    search(board, x - 1, y);
    search(board, x, y - 1);
}

int countSafeZone(node ** board){
    int sum = 0;
    safeZone = 0;
    infected = 1;
    for(int y = 0; y < n; y++){
        for(int x = 0; x < m; x++){
            if(board[y][x].type != LAND || board[y][x].visit == 1)continue;
                search(board, x, y);
                sum += (safeZone * infected);
                safeZone = 0;
                infected = 1;
        }
    }
    return sum;
}

int main()
{
    
    node **board;
    cin >> n >> m;

    board = new node *[n];

    for(int i = 0; i < n; i++){
        board[i] = new node[m];
    }

    for(int y = 0; y < n; y++){
        for(int x = 0; x < m; x++){
            cin >> board[y][x].type;
            board[y][x].visit = 0;
        }
    }


    //벽 3개를 세울 수 있는 모든 경우 대입
    int max = 0, tmp;
    for(int p1 = 0; p1 < n * m - 2; p1++){
        //board[p1/m][p1%m]
        if(board[p1/m][p1%m].type != LAND)continue;
        board[p1/m][p1%m].type = WALL;

        for(int p2 = p1 + 1; p2 < n * m - 1; p2++){
            //board[p2/m][p2%m]
            if(board[p2/m][p2%m].type != LAND)continue;
            board[p2/m][p2%m].type = WALL;

            for(int p3 = p2 + 1; p3 < n *m; p3++){
                //board[p3/m][p3%m]
                if(board[p3/m][p3%m].type != LAND)continue;
                board[p3/m][p3%m].type = WALL;
                tmp = countSafeZone(board);
                init(board);
                if(tmp > max)max = tmp;

                board[p3/m][p3%m].type = LAND;
            }
            board[p2/m][p2%m].type = LAND;
        }
        board[p1/m][p1%m].type = LAND;
    }

    cout << max;
}