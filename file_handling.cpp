
// Online IDE - Code Editor, Compiler, Interpreter

#include<iostream>
#include <cstring>
#include<fstream>

using namespace std;

int main()
{
    // ofstream ofs("demo.txt", ios::);
    // ofs<<"John"<<endl;
    // ofs<<25<<endl;
    // ofs<<"CS"<<endl;
    // ofs.close();
    ifstream ifs;
    ifs.open("demo.txt");
    if(!ifs.is_open())
    {
        cout <<"can't open file"<<endl;
    }
    string str,str2;
    int x;
    ifs>>str;
    ifs>>x;
    ifs>>str2;
    if(ifs.eof())
    {
        cout<<"eof reached"<<endl;
    }
    cout<<str<<" "<<x<<" "<<str2<<endl;
    ifs.close();
}
