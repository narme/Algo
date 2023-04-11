#include <iostream>
#include <string>
#include <memory.h>

using namespace std;

int main()
{
    int n, size, answer = 0;
    int *nums;
    
    cin >> n;
    
    size = to_string(n).length();
    nums = new int[size+1];

    //분리
    int idx;
    for(int i = 1; i <= n; i++){
        if(i < 100){
            answer++;
            continue;
        }
        idx = 0;
        memset(nums, -1, sizeof(int)*(size+1));
        
        int j = i;
        while(j != 0){
            nums[idx] = j % 10;
            idx++;
            j = j / 10;
        }
        
        idx = 0;
        while(nums[idx+2] != -1){
            if(nums[idx+1] - nums[idx] != nums[idx+2] - nums[idx+1])break;
            idx++;
        }
        if(nums[idx+2] == -1)answer++;
    }
    
    cout << answer;
}