#include <iostream>
using namespace std;
 
void print(int arr[], int n)
{
    for(int i = 0; i < n; i++)cout << arr[i];
}
 
bool AreAll9s(int* num, int n )
{
    int i;
    for(i = 0; i < n; ++i)
        if (num[i] != 9)
            return false;
             
    return true;
}
 
void palindrome(int num[], int n)
{
    int mid = n / 2;
    bool smaller = false;
 
    int i = mid - 1;
    int j = (n % 2) ? mid + 1 : mid;
 
    while (i >= 0 && num[i] == num[j])
        i--, j++;
 

    if (i < 0 || num[i] < num[j])
        smaller = true;
 
    while (i >= 0)
    {
        num[j] = num[i];
        j++;
        i--;
    }

    if (smaller == true)
    {
        int carry = 1;
        i = mid - 1;
 
        if (n % 2 == 1){
            num[mid] += carry;
            carry = num[mid] / 10;
            num[mid] %= 10;
            j = mid + 1;
        }
        else j = mid;

        while (i >= 0){
            num[i] += carry;
            carry = num[i] / 10;
            num[i] %= 10;

            num[j++] = num[i--];
        }
    }
}
 
void solve(int num[], int n)
{
    int i;
 
    // 입력이 전부 9 일때
    if (AreAll9s(num, n))
    {
        printf("1");
        for(i = 1; i < n; i++)
            printf("0");
        printf("1");
    }
    else
    {
        palindrome(num, n);
        print (num, n);
    }
}
 
int main()
{
    string input;
    cin >> input;
    int *num;
    int n = input.size();
    num = new int[input.size()];
    for(int i = 0; i < n; i++){
        char tmp = input.at(i);
        num[i] = atoi(&tmp);
    }
 
    solve(num, n);
 
    return 0;
}