#include <iostream>
#include <string>
#include <queue>

using namespace std;

int main()
{
    string input, temp;
    queue<int> numbers;
    queue<char> operators;

    cin >> input;

    for(int i = 0; i < input.length(); i++)
    {
        
        int start, end;
        for(end = i, start = i; input[end] != '+' && input[end] != '-' && end < input.length(); end++, i++);

        temp = input.substr(start, end - start);
        numbers.push(stoi(temp));
        if(input[end] != '\n' && input[end] != '\0')operators.push(input[end]);
    }

    char oper;
    int sums = numbers.front();
    numbers.pop();
    //cout << sums << "\n";
    while(!operators.empty())
    {
        oper = operators.front();
        operators.pop();

        if(oper == '-'){
            sums -= numbers.front();
            numbers.pop();
            while(operators.front() == '+'){
                sums -= numbers.front();
                numbers.pop();
                operators.pop();
            }
        }else{
            sums += numbers.front();
            numbers.pop();
        }
    }
    cout << sums;
    /*

    while(!numbers.empty()){
        cout << numbers.front() << "\n";
        numbers.pop();
    }

    while(!operators.empty()){
        cout << operators.front() << "\n";
        operators.pop();
    }

    */
}