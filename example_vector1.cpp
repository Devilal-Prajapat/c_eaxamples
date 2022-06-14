
// Online IDE - Code Editor, Compiler, Interpreter

#include<iostream>
#include<vector>
using namespace std;

int main()
{
    vector<int> v = {10, 20, 30};
    v.push_back(40);
    v.push_back(60);
    for(int x:v)
    {
        cout<<x<<endl;
    }
    cout<<"----------------------------\n";
    vector<int>::iterator itr;
    for(itr = v.begin(); itr!=v.end();itr++)
    {
        cout<<*itr<<endl;
    }
    return 0;
}
