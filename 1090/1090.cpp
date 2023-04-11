#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

struct xy{
    int x;
    int y;
    double distance;
};

bool compare(const xy& p1, const xy& p2){
    return p1.distance < p2.distance;
}

long long solve(int n, int k, xy board[])
{
    long long *distance = new long long[n];
    long long minimum = 99999999;
    for(int x = 0; x < n; x++)
    {
        for(int y = 0; y < n; y++)
        {
            for(int l = 0; l < n; l++){
                distance[l] = abs(board[l].x - board[x].x) + abs(board[l].y - board[y].y);
            }
            sort(distance, distance+n);
            int sum = 0;
            for(int i = 0; i < k+1; i++)sum += distance[i];
            if(minimum > sum)minimum = sum;
        }

    }
    return minimum;

}

int main()
{
    int n;

    cin >> n;

    xy * board = new xy[n];

    for(int i = 0; i < n; i++)
    {
        cin >> board[i].x;
        cin >> board[i].y;
    }

    for(int i = 0; i < n; i++)
    {
        cout << solve(n, i, board) << " ";
    }
    return 0;
}
