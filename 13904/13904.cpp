#include <iostream>
#include <queue>

using namespace std;

priority_queue<pair<int, int>> q;   //score deadline
int n;
int schedule[1000];
int findindex(int day){
    int index = day;

    while(schedule[index] != 0 && index != 0)index--;
    return index;
}

long long solve(){
    long long sum = 0;
    while(!q.empty()){
        int score = q.top().first;
        int day = q.top().second;
        q.pop();

        //search index;
        int index = schedule[day] == 0 ? day : findindex(day);

        if(index == 0)continue;
        else{
            schedule[index] = 1;
            sum += score;
        }
    }
    return sum;
}

void input(){
    cin >> n;
    int score, day;
    for(int i = 0; i < n; i++){
        cin >> day >> score;
        q.push({score, day});
    }
}

int main(){
    input();
    cout << solve();
}