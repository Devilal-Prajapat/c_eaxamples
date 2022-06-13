
// Online IDE - Code Editor, Compiler, Interpreter

#include<iostream>
#include<fstream>

using namespace std;
class Student
{
    public:
    string name;
    int rollno;
    string branch;
    friend ofstream & operator<<(ofstream &ofs, Student &s);
    friend ifstream & operator>>(ifstream &ifs, Student &s);
    
};

ofstream & operator<<(ofstream &ofs, Student &s)
{
    ofs<<s.name<<endl;
    ofs<<s.rollno<<endl;
    ofs<<s.branch<<endl;
    return ofs;
}

ifstream & operator>>(ifstream &ifs, Student &s)
{
    ifs>>s.name;
    ifs>>s.rollno;
    ifs>>s.branch;
    return ifs;
}

int main()
{
    // ofstream outfile("demo.txt");
    // outfile<<"hello"<<endl;
    // outfile<<123<<endl;
    // outfile.close();
    Student s1;
    s1.name = "Dev";
    s1.rollno = 10;
    s1.branch = "EC";
    ofstream ofs("demo.txt");
    ofs<<s1;
      s1.name = "Devil";
    s1.rollno = 11;
    s1.branch = "EC";
    ofs<<s1; 
      s1.name = "Devid";
    s1.rollno = 12;
    s1.branch = "EC";
    ofs<<s1;
    ofs.close();
    
    Student s2;
    ifstream ifs;
    ifs.open("demo.txt");
    ifs>>s2;
    cout<<s2.name<<" "<<s2.rollno<<" "<<s2.branch<<endl;
    ifs>>s2;
    cout<<s2.name<<" "<<s2.rollno<<" "<<s2.branch<<endl;
    ifs>>s2;
    cout<<s2.name<<" "<<s2.rollno<<" "<<s2.branch<<endl;
    Student s3;
    ifs>>s3;
    cout<<s3.name<<" "<<s3.rollno<<" "<<s3.branch<<endl;
    if(ifs.eof())
    {
        cout<<"eof reached"<<endl;
    }

    ifs.close();
}
