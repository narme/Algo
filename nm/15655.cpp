#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

vector<int> v;
vector<int> arr;
int n, m;
void solve(int start){
    if(v.size() == m){
        for(int i = 0; i < m; i++)cout << v[i] << " ";
        cout << "\n";
        return;
    }
    for(int i = start; i <= n; i++){
        if(find(v.begin(), v.end(), arr[i-1]) == v.end()){
            v.push_back(arr[i-1]);
            solve(i+1);
            v.pop_back();
        }
    }
}

int main(){
    
    cin >> n >> m;

    int a;
    for(int i = 0; i < n; i++){
        cin >> a;
        arr.push_back(a);
    }
    sort(arr.begin(), arr.end());
    solve(1);
}