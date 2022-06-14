
// Online IDE - Code Editor, Compiler, Interpreter

#include<iostream>
#include <memory>
using namespace std;

class Rectangle
{    
    private :
    int len;
    int width;
    public:
    Rectangle(int l = 0, int w = 0)
    {
        len = l;
        width = w;
    }
    int area()
    {
        return len * width;
    }
};

int main()
{
    unique_ptr<Rectangle> ptr(new Rectangle(10,30));
  // unique_ptr<Rectangle> ptr2 = ptr;  // not allowed in unique_ptr
    unique_ptr<Rectangle> ptr2;
    ptr2 = move(ptr); // allowd
    cout<<ptr2->area()<<endl;
    
    shared_ptr<Rectangle> p1(new Rectangle(10,5));
    cout<<p1->area()<<endl;
    shared_ptr<Rectangle> p2 = p1; // allowed in shared_ptr;
    cout<<p2->area()<<endl;
    cout<<p1->area()<<endl;
   
    return 0;
}
