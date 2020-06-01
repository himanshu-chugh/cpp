#include<iostream>
using namespace std;
class d 
{
    public:
    // d()
    // {
    //     cout<<"const d"<<endl;
    // }
    // ~d()
    // {
    //     cout<<"dest d"<<endl;
    // }
    void print()
    {
        `
        cout<<"const D"<<endl;
    }
};
class b
{
    int c;
    public:
    
    // ~b()
    // {
    //     cout<<"dest b"<<endl;
    // }
    friend void d::print();

};

int main()
{
    d d1;
    d1.print();
    
}