#include <iostream>
#include <queue>

using namespace std;

int **box, width, height;
int unripe, ripe;

queue<pair<int, int>> ripeTomato;

bool isOut(int x, int y){
    if(x > width -1 || x < 0 || y > height - 1 || y < 0)return true;
    else return false;
}

void tomato()
{
    int xDirection[4] = {0, 0, -1, 1};
    int yDirection[4] = {1, -1, 0, 0};

    queue<pair<int, int>> temp;
    while(ripeTomato.empty() == 0)
    {
        int x = ripeTomato.front().first;
        int y = ripeTomato.front().second;

        ripeTomato.pop();
        
        for(int i = 0; i < 4; i++)
        {
            int nx = x + xDirection[i];
            int ny = y + yDirection[i];
            if(isOut(nx, ny))continue;

            if(box[ny][nx] == 1 || box[ny][nx] == -1)continue;
            
            //새로 익은거면 큐에 등록
            box[ny][nx] = 1;
            ripe++;
            temp.push(make_pair(nx, ny));
        }
    }
    ripeTomato = temp;
}

int solve()
{
    int goal, before, day = 0;

    goal = (width * height) - unripe;
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
    cin >> width >> height;

    box = new int *[height];
    
    for(int i = 0; i < height; i++){
        box[i] = new int[width];
        for(int j = 0; j < width; j++){
            cin >> box[i][j];
            if(box[i][j] == -1)unripe++;
            else if(box[i][j] == 1){
                ripeTomato.push(make_pair(j, i));
                ripe++;
            }
        }
    }
    cout << solve();
}