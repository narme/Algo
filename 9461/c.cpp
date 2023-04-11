#include <iostream>


using namespace std;

int main()
{
    int n;
    unsigned long arr[100] = { 1, 1, 1, 2, 2, 3, 4, 5, 7, 9};

    for(int i = 9; i < 100; i++){
        arr[i] = arr[i-1] + arr[i-5];

    }
    
    cin >> n;

    for(int i = 0, j; i < n; i++){
        cin >> j;
        cout << arr[j-1];
    }

    return 0;
}

