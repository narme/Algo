#include <iostream>
#include <string>
#include <cstring>

#define MAX 100000
#define MAX_RANGE 300000
using namespace std;

pair<int, int> smap[MAX_RANGE]; // 누적합 N에 대한 {minIdx, maxIdx}

void solve(){
    string s;
    int chStr[MAX]; // K는 -1, S는 2, 이외에는 0 으로 변환할 배열
    int sum[MAX], kcnt[MAX], scnt[MAX]; // 누적합, K의 개수 누적합, S의 개수 누적합
    bool check[MAX_RANGE]; // 누적합 N 에 대한 방문 검사, 최초 방문의 경우 최소 인덱스로 등록하고 이후에는 최대 인덱스로 등록 
    int length;
    cin >> s;
    
    length = s.length();

    //처음 입력인지 아닌지 검사하는 check 배열 초기화
    memset(check, false, sizeof(check));
    memset(kcnt, 0, sizeof(kcnt));
    memset(scnt, 0, sizeof(scnt));
    
    //누적합 0에 대한 초기화
    //SKK 와 같은 경우에 필요, SKK의 누적합은 -2 -1 0 이되는데 누적합 0에 대한 최소 인덱스를 임의로 -1로 설정.
    check[MAX] = true;
    smap[MAX] = {-1, -1};
    for(int i = 0; i < length; i++){
        if(s[i] == 'K')chStr[i] = -1;
        else if(s[i] == 'S')chStr[i] = 2;
        else chStr[i] = 0;
        
        //K 와 S의 누적합
        //AASKSSK 같은 경우 AA 를 답으로 처리하지 않기 위해 
        kcnt[i] = (i == 0 ? s[i] == 'K' : kcnt[i-1] + (s[i] == 'K'));
        scnt[i] = (i == 0 ? s[i] == 'S' : scnt[i-1] + (s[i] == 'S'));
        
        sum[i] = chStr[i] + (i != 0 ? sum[i-1] : 0);
        int idx = sum[i] + MAX;
        //첫 입력이면 최소값으로 등록
        if(!check[idx]){
            check[idx] = true;
            smap[idx] = {i, -1};
        }else{
            int tmp = smap[idx].first;
            smap[idx] = {tmp, i};
        }
    }
    //S와 K가 등장하지 않은경우
    if(scnt[length-1] < 1 || kcnt[length-1] < 2){
        cout << -1;
        return;
    }
    int answer = -1;

    for(int i = 0; i < MAX_RANGE; i++){
        if(!check[i])continue;
        int from = smap[i].first;
        int to = smap[i].second;

        if(to == -1)continue;
        else if(scnt[from] - scnt[to-1] != 0 && kcnt[from] - kcnt[to-1] != 0)answer = max(to - from, answer);
        
    }
    cout << answer;
}


int main(){
    solve();
}