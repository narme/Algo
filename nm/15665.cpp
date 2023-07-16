#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

vector<int> v;
vector<int> arr;
bool check[10];

int n, m;
void solve(int start){
    if(v.size() == m){
        for(int i = 0; i < m; i++)cout << v[i] << " ";
        cout << "\n";
        return;
    }
    int end = -1;
    for(int i = start; i <= n; i++){
        if(end != arr[i-1]){
            v.push_back(arr[i-1]);
            end = arr[i-1];
            solve(1);
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