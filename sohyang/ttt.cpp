#include <iostream>

int evenSum(int start, int end)
{
    int sum = 0;
    for(int i = start; i <= end; i++){
        if(i % 2 == 0)sum += i;
    }
    return sum;
}

int main()
{
    int start = 0;
    int end = 10;

    std::cout << start << "와" << end << "사이의 짝수 합 = " << evenSum(start, end) << "\n";

    return 0;
}