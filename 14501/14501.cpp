#include <iostream>

using namespace std;

int answer = 0;
int n;
int *t, *p;

//재귀는 메모리가 터져버렸음..
//check 함수 넣으니까 되네 후.. 개빡 ^^7
//인덱스 뒤로 더 추가할게 있으면 1 없으면 0
int check(int idx)
{
    for(int i = idx; i < n; i++)
    {
        if(t[i] + i < n + 1)return 1;
    }
    return 0;
}

void solve(int idx, int sum){
    if(n < idx || check(idx) == 0)
    {
        if(sum > answer)answer = sum;
        return;
    }

    if(n >= idx + t[idx])solve(idx+t[idx], sum + p[idx]);
    solve(idx + 1, sum);

}

int main(){
    cin >> n;

    t = new int[n];
    p = new int[n];

    for(int i = 0; i < n; i++)cin >> t[i] >> p[i];

    solve(0,0);

    
    cout << answer;
}