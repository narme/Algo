#include <iostream>
#include <fstream>

using namespace std;
char arr[10] = "1000 ";

int main(){
    ofstream writeStream;

    writeStream.open("input.txt");

    for(int i = 0; i < 100; i++){
        for(int j = 0; j < 100; j++){
            writeStream << "1000 ";
        }
        writeStream << "\n";
    }

    writeStream.close();
}