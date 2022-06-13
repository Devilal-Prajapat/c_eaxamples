
// Online IDE - Code Editor, Compiler, Interpreter

#include<iostream>

using namespace std;
class mystack
{
    private:
        int *ptr;
        int size;
        int top;
    public:
    mystack(int sz)
    {
        size = sz;
        top = -1;
        ptr = new int(size);
    }
    void push(int x);
    int pop();

};

void mystack :: push(int x)
{
    if(top == size - 1)
    {
        cout<<"Full"<<endl;
    }
    else
    {
        top += 1;
        ptr[top] = x;
      
    }
}
int mystack :: pop()
{
    if(top == -1)
    {
        cout<<"Empty"<<endl;
    }
    else
    {
       int x = ptr[top];
        top -= 1;
        cout<< x<<endl;
    }
    return 1;
}

int main()
{
    mystack s(5);
    int i = 0;
    s.push(i++);
    s.push(i++);
    s.push(i++);
    s.push(i++);
    s.push(i++);
    s.push(i++);
    s.push(i++);
    s.pop();
    s.pop();
    s.pop();
    s.pop();
    s.pop();
    return 0;
}
