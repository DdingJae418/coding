#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

class Queue
{
private:
    stack<int> s1;
    stack<int> s2;
public:
    void Enqueue(int data)
    {
        s1.push(data);
    }
    void Dequeue()
    {
        if(s2.empty())
        {
            while(!s1.empty())
            {
                int data = s1.top();
                s1.pop();
                s2.push(data);
            }
        }
        s2.pop();
    }
    void PrintFront()
    {
        if(s2.empty())
        {
            while(!s1.empty())
            {
                int data = s1.top();
                s1.pop();
                s2.push(data);
            }
        }
        cout<<s2.top()<<endl;
    }
};

int main() {
    Queue q;
    int querys;
    cin>>querys;
    
    for(int i = 0; i < querys; i++)
    {
        int query;
        int num;
        cin>>query;
        
        switch(query)
        {
        case 1:
            cin>>num;
            q.Enqueue(num);
            break;
        case 2:
            q.Dequeue();
            break;
        case 3:
            q.PrintFront();
            break;
        }
    }
    return 0;
}