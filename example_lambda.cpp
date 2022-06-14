
// Online IDE - Code Editor, Compiler, Interpreter

#include<iostream>
using namespace std;

int main()
{
    [](){cout<<"Hello"<<endl;}();
    [](int a, int b){cout<<"sum "<<a+b<<endl;}(10,5);
    int x = [](int a, int b){return a+b;}(10,10);
    int y = [](int a, int b)->int{return a+b;}(10,17);
    cout<<x<<" "<<y<<endl;
    auto f =  [](){cout<<"Hello"<<endl;};
    f();
    int c = 50;
    int d = 60;
    [c,d](){cout<<c<<" "<<d<<endl;}();
    // for modify reference is used
     [&c,&d](){cout<<++c<<" "<<++d<<endl;}();
     int e = 90;
    // want to acsess all member reference is used
     [&](){cout<<++c<<" "<<++d<<" "<<e<<endl;}();
    
    
    return 0;
}
