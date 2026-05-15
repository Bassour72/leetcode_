#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <vector>
#include <stack>
#include <deque>
class MyQueue 
{
public:
    std::deque<int> qu;
    MyQueue() 
    {
        
    }
    
    void push(int x) 
    {
        qu.push_back(x);
    }
    
    int pop() 
    {
        int temp = 0;
        if (!qu.empty())
        {
            temp = qu.front();
            qu.pop_front();
        }
        return (temp);
    }
    
    int peek() 
    {
        return (qu.front());
    }
    bool empty() 
    {
        return (qu.empty());
    }
};

int main(void)
{
    MyQueue* obj = new MyQueue();
    obj->push(10);
    int param_2 = obj->pop();
    obj->pop();
    obj->pop();
    std :: cout << param_2 << "\n";
    // int param_3 = obj->peek();
    // std :: cout << param_3 << "\n";

    bool param_4 = obj->empty();
    std :: cout << param_4 << "\n";

    return 0;
}
