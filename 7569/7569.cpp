#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

int ***box, width, depth, height;
int unripe, ripe;

queue<tuple<int, int, int>> ripeTomato;

bool isOut(int x, int y, int z){
    if(x > width -1 || x < 0 || y > depth - 1 || y < 0 || z > height -1 || z < 0 )return true;
    else return false;
}

void tomato()
{
    int xDirection[6] = {0, 0, -1, 1, 0, 0};
    int yDirection[6] = {1, -1, 0, 0, 0, 0};
    int zDirection[6] = {0, 0, 0, 0, 1, -1};

    queue<tuple<int, int, int>> temp;
    while(ripeTomato.empty() == 0)
    {
        int x = get<0>(ripeTomato.front());
        int y = get<1>(ripeTomato.front());
        int z = get<2>(ripeTomato.front());
        ripeTomato.pop();
        
        for(int i = 0; i < 6; i++)
        {
            int nx = x + xDirection[i];
            int ny = y + yDirection[i];
            int nz = z + zDirection[i];
            if(isOut(nx, ny, nz))continue;

            if(box[nz][ny][nx] == 1 || box[nz][ny][nx] == -1)continue;
            
            //새로 익은거면 큐에 등록
            box[nz][ny][nx] = 1;
            ripe++;
            temp.push(make_tuple(nx, ny, nz));
        }
    }
    ripeTomato = temp;
}

int solve()
{
    int goal, before, day = 0;

    goal = (width * depth * height) - unripe;
    while(true)
    {
        before = ripe;
        //전부 익으면 날짜 반환
        if(goal == ripe)return day;
        tomato();
        day++;
        //하루가 지났는데 변한게 없으면 더 이상 익힐 수 없음.
        if(before == ripe)return -1;
    }
}


int main()
{
    cin >> width >> depth >> height;

    box = new int **[height];
    
    for(int i = 0; i < height; i++){
        box[i] = new int*[depth];
        for(int j = 0; j < depth; j++){
            box[i][j] = new int[width];
            for(int k = 0; k < width; k++){
                cin >> box[i][j][k];
                if(box[i][j][k] == -1)unripe++;
                else if(box[i][j][k] == 1)ripe++, ripeTomato.push(make_tuple(k, j, i));
            }
        }
    }
    cout << solve();
}