#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, minimumCost;

typedef struct node{
    int x;
    int y;
    int p;
    node(int ix, int iy, int ip) : x(ix), y(iy), p(ip){}
}node;



vector<node> nodes;

void input(){
    cin >> n >> minimumCost;

    int x, y;
    nodes.push_back(node(-1, -1, -1)); // dummy
    for(int i = 1; i <= n; i++){
        cin >> x >> y;
        nodes.push_back(node(x, y, i));
    }
}

int find_parent(int n1){
    if(nodes[n1].p == n1)return n1;
    else return nodes[n1].p = find_parent(nodes[n1].p);
}

bool make_union(int n1, int n2){
    int p1 = find_parent(n1);
    int p2 = find_parent(n2);
    if(p1 == p2)return false;
    else{
        if(p1 < p2)nodes[p2].p = p1;
        else nodes[p1].p = p2;
        return true;
    }

}

void solve(){
    //cost , from , to
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;

    for(int i = 1; i < n; i++){
        for(int j = i + 1; j <= n; j++){
            int diffx = nodes[i].x - nodes[j].x;
            int diffy = nodes[i].y - nodes[j].y;
            int dis = diffx * diffx + diffy * diffy;
            if(dis < minimumCost)continue;
            pq.push({dis, {i, j}});
        }
    }
    int cnt = 0, answer = 0;
    while(!pq.empty()){
        int n1 = pq.top().second.first;
        int n2 = pq.top().second.second;
        int dis = pq.top().first;

        pq.pop();

        if(!make_union(n1, n2))continue;
        answer += dis;
        cnt++;
        if(cnt == n - 1)break;
    }
    if(cnt != n - 1)answer = -1;
    cout << answer;
}

int main(){
    input();
    solve();
}