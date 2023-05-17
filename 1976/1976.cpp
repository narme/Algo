#include <iostream>
#include <vector>
#include <queue>

using namespace std;
int city[201][201];
int parent[201];
vector<int> plan;
int n, m;
queue<pair<int, int>> q;

void input(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        parent[i] = i;
        for(int j = 1; j <= n; j++){
            cin >> city[i][j];
            if(city[i][j] == 1)q.push({i, j});
        }
    }
    int tmp;
    for(int i = 0; i < m; i++){
        cin >> tmp;
        plan.push_back(tmp);
    }
}

int find_parent(int city){
    if(parent[city] == city)return city;
    else return parent[city] = find_parent(parent[city]);
}
bool make_union(int c1, int c2){
    int p1 = find_parent(c1);
    int p2 = find_parent(c2);
    //cout << "find : " << p1 << " , " << p2 << "\n";
 
    if(p1 < p2)parent[p2] = p1;
    else parent[p1] = p2;

    return true;
}
void print(){
    for(int i = 1; i <= n; i++){
        cout << parent[i] << " ";
    }
    cout << "\n";
}

void solve(){
    while(!q.empty()){
        int n1 = q.front().first;
        int n2 = q.front().second;
        q.pop();
        //print();
        make_union(n1, n2);
    }
    
    //시작 지점과 부모가 같으면 도달할 수 있다고 판단.
    for(int i = 1; i < m; i++){
        if(parent[plan[i]] != parent[plan[0]]){
            cout << "NO";
            return;
        }
    }
    cout << "YES";
}

int main(){
    input();
    solve();
}