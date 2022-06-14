
// Online IDE - Code Editor, Compiler, Interpreter

#include<iostream>
#include<map>
using namespace std;

int main()
{
    map<int,string> m;
    m.insert(pair<int, string>(1, "Dev"));
    m.insert(pair<int, string>(2, "Harshita"));
    m.insert(pair<int, string>(3, "Manju"));
    cout<<"----------------------------\n";
    map<int,string>::iterator itr;
    for(itr = m.begin(); itr!=m.end();itr++)
    {
        cout<<itr->first<<" "<<itr->second<<endl;
    }
    
    map<int,string>::iterator itr2;
    itr2 = m.find(2);
    cout<<"value found is \n";
    cout<<itr2->first<<" "<<itr2->second<<endl;
    return 0;
}
