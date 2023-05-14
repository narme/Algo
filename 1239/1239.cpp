#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<int> pie;
int n;

void input(){
    int tmp;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> tmp;
        pie.push_back(tmp);
    }
    sort(pie.begin(), pie.end());
}
void solve(){
    int answer = 0;
    do{
        int cnt = 0;

        //50이 되는 경우 카운트
        for(int i = 0; i < pie.size() - 1; i++){
            int tmp = 0;
            tmp += pie[i];
            for(int j = i+1; j < pie.size(); j++){
                if(tmp == 50){
                    cnt++;
                    break;
                }
                tmp += pie[j];
            }
        }
        answer = max(answer, cnt);
    }while(next_permutation(pie.begin(), pie.end()));
    cout << answer;
}

int main(){
    input();
    solve();
}