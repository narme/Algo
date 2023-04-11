#include <iostream>

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
        std::cout << "1. ADD 2. MINUS 3. MULTIPLE 4. DEVIDE\n";
        std::cout << "Enter the menu (Enter -1 to exit): ";
        
        std::cin >> choice;
        
        if(choice == -1)
        {
            std::cout << "201713829\n";
            break;
        }
        
        std::cout << "input two : ";
        std::cin >> num1 >> num2;

        if(choice == 1)
        {
            std::cout << "result : " << plus(num1, num2) << "\n";
        }
        else if(choice == 2)
        {
            std::cout << "result : " << minus(num1, num2) << "\n";
        }
        else if(choice == 3)
        {
            std::cout << "result : " << multiple(num1, num2) << "\n";
        }
        else if(choice == 4)
        {
            std::cout << "result : " << divide(num1, num2) << "\n";
        }
    }
    return 0;
}