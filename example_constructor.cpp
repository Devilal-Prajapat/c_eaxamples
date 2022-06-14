
// Online IDE - Code Editor, Compiler, Interpreter

#include<iostream>
using namespace std;

class Base
{
    public:
    Base()
    {
        cout<<"Base constructor\n";
    }
    Base(int x)
    {
        cout<<"Base "<<x<<endl;
    }
};

class Derived:public Base
{
    public:
    Derived()
    {
        cout<<"Derived constructor\n";
    }
    Derived(int x, int y):Base(x)
    {
        cout<<"Derived "<<y<<endl;
    }
};

int main()
{
    Derived d(10,20);
    return 0;
}
