#include <iostream>

#define MAX 1001

using namespace std;

int t, w;
int tree[MAX];
int dp[2][MAX][31]; // 현재 위치, 시간, 이동 회수

void input(){
    cin >> t >> w;
    for(int i = 1; i <= t; i++)cin >> tree[i];
}
void solve(){
    //
    for(int m = 0; m <= w; m++){
        for(int r = 1; r <= t; r++){
            
            if(m == 0)dp[0][r][m] = dp[0][r-1][m] + (tree[r] == 1);
            else{ //이동했을때랑 안했을때중의 최대 값
                dp[0][r][m] = max(dp[1][r-1][m-1] + (tree[r] == 1), dp[0][r-1][m] + (tree[r] == 1));
                dp[1][r][m] = max(dp[0][r-1][m-1] + (tree[r] == 2), dp[1][r-1][m] + (tree[r] == 2));
            }
        }
    }
    int answer = 0;

    for(int i = 0; i <= w; i++){
        answer = max(answer, max(dp[0][t][i], dp[1][t][i]));
    }
    cout << answer;
}
int main(){
    input();
    solve();
}