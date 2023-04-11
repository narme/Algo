#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    int n;
    while(cin >> n){
        long long answer = 1;
        int count = 1;
        while(answer % n != 0){
            
            answer = answer % n * 10 + 1;
            //cout << answer % n << "\n";
            count++;
        }
        cout << count << "\n";
    }
}