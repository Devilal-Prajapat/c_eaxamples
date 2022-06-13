// Template class example

#include<iostream>

using namespace std;
template<class T>
class mystack
{
    private:
        T *ptr;
        int size;
        int top;
    public:
    mystack(int sz)
    {
        size = sz;
        top = -1;
        ptr = new T(size);
    }
    void push(T x);
    T pop();

};
template<class T>
void mystack<T> :: push(T x)
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
template<class T>
T mystack<T> :: pop()
{
    T num;
    if(top == -1)
    {
        cout<<"Empty"<<endl;
    }
    else
    {
        T x = ptr[top];
        top -= 1;
        cout<< x<<endl;
    }
    return num;
}

int main()
{
    mystack<int> s(5);
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
