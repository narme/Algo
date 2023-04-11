#include <stdio.h>

int main(int argc, char** argv)
{
    int i, sum = 0;
    int array[10];

    printf("input 10 nums : ");
    for(i = 0; i < 10; i++)
    {
        scanf("%d", &array[i]);
    }

    for(i = 0; i < 10; i++)
    {
        sum += array[i];
    }
    
    printf("Amount : %d\n", sum);
    return 0;
}