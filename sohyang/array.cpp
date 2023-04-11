#include <iostream>

int main(int argc, char** argv)
{
    int i, sum = 0;
    int array[10];

    std::cout << "input 10 nums : ";

    for(i = 0; i < 10; i++)
    {
        std::cin >> array[i];
    }

    for(i = 0; i < 10; i++)
    {
        sum += array[i];
    }
    
    std::cout << "Amount : " << sum << "\n";
    return 0;
}