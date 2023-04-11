#include<stdio.h>

int plus(int num1, int num2)
{
    return num1 + num2;
}

int minus(int num1, int num2)
{
    return num1 - num2;
}

int multiple(int num1, int num2)
{
    return num1 * num2;
}

int divide(int num1, int num2)
{
    return num1 / num2;
}

int main(int argc, char **argv)
{
    int choice = 0, num1, num2;

    while(choice != -1)
    {
        printf("1. ADD 2. MINUS 3. MULTIPLE 4. DEVIDE\n");
        printf("Enter the menu (Enter -1 to exit): ");
        scanf("%d", &choice);
        
        if(choice == -1)
        {
            printf("201713829\n");
            break;
        }
        
        printf("input two : ");
        scanf("%d %d", &num1, &num2);

        if(choice == 1)
        {
            printf("result : %d\n", plus(num1, num2));
        }
        else if(choice == 2)
        {
            printf("result : %d\n", minus(num1, num2));
        }
        else if(choice == 3)
        {
            printf("result : %d\n", multiple(num1, num2));
        }
        else if(choice == 4)
        {
            printf("result : %d\n", divide(num1, num2));
        }
    }
    return 0;
}