#include <iostream>
#include <algorithm>

using namespace std;

int **input, n;
long long * combine1, * combine2;

bool compare(long long a, long long b)
{
    if(a > b)return true;
    else return false;
}

void init()
{
    cin >> n;
    input = new int *[4];

    for(int i = 0; i < 4; i++)input[i] = new int[n];
    for(int i = 0; i < n; i++)cin >> input[0][i] >> input[1][i] >> input[2][i] >> input[3][i];

    combine1 = new long long [n*n];
    combine2 = new long long [n*n];
}

void combine()
{
    int index = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++, index++){
            combine1[index] = input[0][i] + input[1][j];
            combine2[index] = input[2][i] + input[3][j];
        } 
    }
    sort(combine1, combine1+(n*n));
    sort(combine2, combine2+(n*n), compare);
}

long long solve()
{
    long long cnt = 0;
    int ptr1 = 0, ptr2 = 0;

    while(ptr1 != n*n && ptr2 != n*n)
    {
        long long sum = combine1[ptr1] + combine2[ptr2];

        
        if(sum == 0)
        {
            //cout << combine1[ptr1] << " " << combine2[ptr2] << "\n";
            int temp1 = combine1[ptr1];
            int temp2 = combine2[ptr2];
            long long cnt1 = 0, cnt2 = 0;
            while(ptr1 != n*n && combine1[ptr1] == temp1)ptr1++, cnt1++;
            while(ptr2 != n*n && combine2[ptr2] == temp2)ptr2++, cnt2++;

            cnt += cnt1 * cnt2;
        }
        else
        {
            if(sum > 0)ptr2++;
            else ptr1++;
        }
    }
    return cnt;
}

int main()
{
    init();
    combine();

    cout << solve();
}