#include <iostream>
#include <algorithm>

using namespace std;

#define diff(a, b) abs(a + b)

bool compare(const int &lhs, const int &rhs){
    return lhs < rhs;
}

int main()
{
    int n, *numbers;

    
    cin >> n;

    numbers = new int[n];

    for(int i = 0; i < n; i++)
    {
        cin >> numbers[i];
    }
    int lptr = 0, rptr = n - 1;

    sort(numbers, numbers+n);

    //int minimum = abs(abs(numbers[lptr]) - abs(numbers[rptr]));
    int minimum = diff(numbers[lptr], numbers[rptr]);
    int bestl = lptr, bestr = rptr;
    while(lptr < rptr)
    {
        int currentMinimum = diff(numbers[lptr], numbers[rptr]);

        if(abs(currentMinimum) < abs(minimum))
        {
            minimum = currentMinimum;
            bestl = lptr;
            bestr = rptr;
        }else{
            if(abs(numbers[lptr]) > abs(numbers[rptr]))lptr++;
            else rptr--;
        }
        
    }

    cout << numbers[bestl] << " " << numbers[bestr];
}