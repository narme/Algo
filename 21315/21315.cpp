#include <iostream>
#include <cmath>

using namespace std;

//k : k의 최대값
int n, k;
int *arr, *first, *second, *third;

void print_arr(int *arr)
{
    for(int i = 0; i < n; i++)cout << arr[i] << " ";
    cout << "\n";
}

//같은지 비교
int check()
{

    /*
    cout << "-----check-----" << "\n";
    print_arr(arr);
    print_arr(third);
    cout << "-----check-----" << "\n";
    */
    for(int i = 0; i < n; i++)
    {
        if(arr[i] != third[i])return 0;
    }
    return 1;
}
void swap(int result[], int range)
{
    int size = pow(2,range);
    int *temp = new int[size];
    for(int i = 0; i < pow(2, range); i++)
    {
        temp[i] = result[i];
    }

    for(int i = 0; i < pow(2,range); i++)
    {
        int idx = i + pow(2, range);
        result[i] = result[idx];
        result[idx] = temp[i];
    }
    
}


void cardMix(int *origin, int *result, int times)
{
    int j, k;
    for(int i = times; i >= 0; i--)
    {
        if(i == times)
        {
            for(j = n - pow(2, times), k = 0; j < n; j++, k++)
            {
                result[k] = origin[j];
            }
            for(j = 0, k = pow(2,times); j < n - pow(2,times) ; j++, k++)
            {
                result[k] = origin[j];
            }
        }
        else
        {   
            swap(result, i);
        }
        //print_arr(result);
    }
}

int main()
{
    cin >> n;

    arr = new int[n];
    first = new int[n];
    second = new int[n];
    third = new int[n];

    for(int i = 0; i < n; i++)cin >> arr[i];
    for(int i = 0; i < n; i++)first[i] = i + 1;
    for(int i = 1; pow(2, i) < n; i++)k = i;

    for(int i = 1; i <= k; i++)
    {
        cardMix(first, second, i);
        for(int j = 1; j <= k; j++)
        {
            cardMix(second, third, j);
            if(check())
            {
                cout << i << " " << j;
                return 0;
            }
        }
    }

}