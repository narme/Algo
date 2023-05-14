#include <iostream>
#include <string>

#define maxsize 200

using namespace std;

string gear1, gear2;


int solve(string gear1, string gear2){
    int size = gear1.length() + gear2.length();

    int start = 0;
    while(start < gear1.length()){
        int i = start, j = 0;
        while(gear1[i] + gear2[j] - '0'*2 < 4 && j < gear2.length() && i < gear1.length())j++, i++;
        if(j == gear2.length() || i == gear1.length())break;
        else start++;
    }
    if(start <= gear1.length()){
        //내부에 모두 포함
        if(gear1.length() - start >= gear2.length())return gear1.length();
        //튀어 나감
        else return size - gear1.length() + start;
    }
    else return size;
}

int main(){
    cin >> gear1 >> gear2;
    cout << min(solve(gear1, gear2), solve(gear2, gear1));
}