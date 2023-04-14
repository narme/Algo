#include <algorithm>
#include <iostream>

using namespace std;

bool compare(int a, int b){
    if( a > b)return true;
    return false;
}

int main()
{
    int n, k, answer;

    int *board, *distance;

    cin >> n >> k;

    board = new int[n];
    distance = new int[n-1];
    for(int i = 0; i < n; i++)cin >> board[i];

    sort(board, board+n);

    for(int i = 0; i < n - 1; i++){
        distance[i] = board[i+1] - board[i];
    }
    sort(distance, distance+n-1);

    answer = 0;
    for(int i = 0; i < n - k; i++)answer += distance[i];

    cout << answer;
}