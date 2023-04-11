#include <iostream>
#include <algorithm>

using namespace std;

void quick_sort(int *data, int start, int end){
    if(start >= end){
        // 원소가 1개인 경우
        return; 
    }
    
    int pivot = start;
    int i = pivot + 1; // 왼쪽 출발 지점 
    int j = end; // 오른쪽 출발 지점
    int temp;
    
    while(i <= j){
        // 포인터가 엇갈릴때까지 반복
        while(i <= end && data[i] <= data[pivot]){
            i++;
        }
        while(j > start && data[j] >= data[pivot]){
            j--;
        }
        
        if(i > j){
            // 엇갈림
            temp = data[j];
            data[j] = data[pivot];
            data[pivot] = temp;
        }else{
            // i번째와 j번째를 스왑
            temp = data[i];
            data[i] = data[j];
            data[j] = temp;
        }
    } 
    
    // 분할 계산
    quick_sort(data, start, j - 1);
    quick_sort(data, j + 1, end);
}

int main()
{
    int n;

    cin >> n;

    int *x = new int[n], *y = new int[n];
    int ansx = 0, ansy = 0;

    for(int i = 0; i < n; i++){
        cin >> x[i];
        cin >> y[i];   
    }

    //quick_sort(x, 0, n-1);
    //quick_sort(y, 0, n-1);

    sort(x, x+n);
    sort(y, y+n);

    for(int i = 0; i < n; i++)cout << x[i] << " ";
    cout << "\n";
    for(int i = 0; i < n; i++)cout << y[i] << " ";
    cout << "\n";

    unsigned long answer = 0;
    ansx = x[(n-1)/2];
    ansy = y[(n-1)/2];

    

    for(int i = 0; i < n; i++)
        answer = answer + abs(ansx - x[i]) + abs(ansy - y[i]);

    cout << answer;
    return 0;
}