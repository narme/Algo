#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> v;
int n, m;
void solve(){
    if(v.size() == m){
        for(int i = 0; i < m; i++)cout << v[i] << " ";
        cout << "\n";
        return;
    }
    for(int i = 1; i <= n; i++){
        v.push_back(i);
        solve();
        v.pop_back();
    }
    
}

int main(){
    cin >> n >> m;
    solve();
}