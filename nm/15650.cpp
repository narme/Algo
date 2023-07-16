#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> v;
int n, m;
void solve(int start){
    if(v.size() == m){
        for(int i = 0; i < m; i++)cout << v[i] << " ";
        cout << "\n";
        return;
    }
    for(int i = start; i <= n; i++){
        v.push_back(i);
        solve(i+1);
        v.pop_back();
    }
    
}

int main(){
    cin >> n >> m;
    solve(1);
}