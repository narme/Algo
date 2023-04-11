#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int width, heigth, temp;
    int *up, *down;
    unsigned int *sum;

    cin >> width >> heigth;

    up = new int[heigth]{0,};
    down = new int[heigth]{0,};
    sum = new unsigned int[heigth]{0, };
    for(int i = 0; i < width; i++){
        cin >> temp;
        if(i % 2 == 0){
            up[temp-1]++;
        }else{
            down[temp-1]++;
        }

    }
    for(int i = 1; i < heigth; i++){
        up[heigth-i-1] += up[heigth-i];
        down[heigth-i-1] += down[heigth-i];
    }
    for(int i = 0; i < heigth; i++)sum[i] = up[i] + down[heigth-1-i];


    sort(sum, sum+heigth);
    int count = 1;
    for(int i = 0; sum[i] == sum[i+1]; i++)count++;
    cout << sum[0] << " " << count;

}