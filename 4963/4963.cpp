#include <iostream>

using namespace std;

#define LAND 1
#define SEA 0

struct node{
    int type;
    int visit;
};

void search(node ** board, int x, int y, int w, int h)
{
    if(x == w || y == h || x == -1 || y == -1)return;
    if(board[y][x].visit == 1)return;
    if(board[y][x].type == LAND){
        board[y][x].visit = 1;
        search(board, x + 1, y, w, h);
        search(board, x - 1, y, w, h);
        search(board, x, y + 1, w, h);
        search(board, x, y - 1, w, h);
        search(board, x - 1, y + 1, w, h);
        search(board, x - 1, y - 1, w, h);
        search(board, x + 1, y - 1, w, h);
        search(board, x + 1, y + 1, w, h);
    }else{
        return;
    }
}

int main()
{
    node ** board;

    int w, h, count;

    do
    {
        //init
        cin >> w >> h;

        if(w == 0 && h == 0)break;
        board = new node*[h];
        count = 0;
        for(int i = 0; i < h; i++)board[i] = new node[w];

        for(int y = 0; y < h; y++){
            for(int x = 0; x < w; x++){
                cin >> board[y][x].type;
                board[y][x].visit = 0;
            }
        }

        //search
        for(int y = 0; y < h; y++){
            for(int x = 0; x < w; x++){
                if(board[y][x].visit == 1 || board[y][x].type == SEA)continue;
                search(board, x, y, w, h);
                count++;
            }
        }


        cout << count << "\n";

        for(int i = 0; i < h; i++)delete[] board[i];
        delete[] board;
    }while(1);
}
