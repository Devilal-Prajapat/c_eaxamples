
// Online IDE - Code Editor, Compiler, Interpreter

#include<iostream>
# include<cstdarg>
using namespace std;

int sum(int n, ...)
{
    va_list list;
    va_start(list,n);
    int s = 0;
    for(int i = 0; i<n; i++)
    {
        s += va_arg(list, int);
    }
    va_end(list);
    return s;
}
int main()
{
    cout<<sum(3,1,2,3)<<endl;
    return 0;
}
