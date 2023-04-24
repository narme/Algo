#include <iostream>
#include <queue>

using namespace std;

int main(){
    int n, number;
    cin.tie(NULL), cout.tie(NULL);
    cin >> n;

    priority_queue<int> descendingQueue;
    priority_queue<int, vector<int>, greater<int>> ascendingQueue;

    while(n != 0)
    {
        cin >> number;

        if(ascendingQueue.size() < descendingQueue.size() && descendingQueue.size() != 0)ascendingQueue.push(number);
        else descendingQueue.push(number);

        
        if(!ascendingQueue.empty() && !descendingQueue.empty()){
            if(ascendingQueue.top() < descendingQueue.top()){
                int a = ascendingQueue.top();
                int b = descendingQueue.top();

                ascendingQueue.pop();
                descendingQueue.pop();

                ascendingQueue.push(b);
                descendingQueue.push(a);
            }
        }
        cout << descendingQueue.top() << "\n";
        n--;
    }
}