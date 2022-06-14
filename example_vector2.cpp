
// Online IDE - Code Editor, Compiler, Interpreter

#include<iostream>
#include<vector>
using namespace std;

class Item
{
    private:
        string name;
        float price;
        int Qty;
    public:
    Item()
    {
        name = "Dev";
        price = 0.0f;
        Qty = 0;
    }
    Item(string str, float rate, int qty)
    {
        name = str;
        price = rate;
        Qty = qty;
    }
    
    friend ostream & operator<<(ostream &out, Item &itm);
};
ostream & operator<<(ostream &out, Item &x)
{
    out<<x.name<<" "<<x.price<<" "<<x.Qty<<endl;
    return out;
}

int main()
{
    vector<Item> v;
    v.push_back(Item("Banana",30.0f,12));
    v.push_back(Item("Mango",50.0f,5));
    for(Item x:v)
    {
        cout<<x;
    }
    return 0;
}
