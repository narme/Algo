#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int funcDslr(int n, int i){
    switch (i)
    {
    case 0:
        return (n * 2) % 10000;
    case 1:
        return n == 0 ? 9999 : n - 1;
    case 2:
        return (n % 1000 * 10) + n / 1000;
    case 3:
        return ((n % 10) * 1000) + (n / 10);
    default:
        return -1;
    }
}

char dslr[4] = {'D', 'S', 'L', 'R'};

vector<string> answer; 

void solve(int n1, int n2){
    queue<pair<int, string>> q;
    bool visit[10000]{0};
    bool reverse = true;
    string nroute;

    q.push({n1, ""});

    while(true){
        int n = q.front().first;
        string route = q.front().second;
        q.pop();
        if(n == n2){
            answer.push_back(route);
            return;
        }
        visit[n] = true;
        if(!reverse){
            for(int i = 3; i >= 0; i--){
                int nn = funcDslr(n, i);
            
                if(visit[nn])continue;
                else visit[nn] = true;
                nroute = route + dslr[i];
                if(nn == n2){
                    answer.push_back(nroute);
                    return;
                }
                q.push({nn, nroute});
            }
        }else{
            for(int i = 0; i < 4; i++){
                int nn = funcDslr(n, i);
                
                if(visit[nn])continue;
                else visit[nn] = true;
                nroute = route + dslr[i];
                if(nn == n2){
                    answer.push_back(nroute);
                    return;
                }
                q.push({nn, nroute});
            }
        }
        reverse = !reverse;
    }
}




int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t, n1, n2;

    cin >> t;
    for(int i = 0; i < t; i++){
        cin >> n1 >> n2;
        solve(n1, n2);
    }
    for(auto i : answer)cout << i << "\n";
}