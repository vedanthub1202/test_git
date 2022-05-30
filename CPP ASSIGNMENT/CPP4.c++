#include <iostream>
using namespace std;

class Complex
{
    private : 
    int a,b;
    public :
    void set_data(int x, int y)
    {
        a=x;
        b=y;
    }

    void show_data()
    {
        cout<<"\na="<<a<<" b="<<b;
        cout<<"\nreal + imaginary= "<<a<<" + i"<<b;
    }

    Complex operator +(Complex c){
    Complex temp;
    temp.a= a+c.a;
    temp.b= b+c.b;
    return (temp);
    }

    Complex operator -(Complex c){
    Complex temp;
    temp.a= a-c.a;
    temp.b= b-c.b;
    return (temp);
    }
};


int main()
{
    Complex c1,c2,c3,c4;
    c1.set_data(10,9);
    c2.set_data(5,4);
    c3=c1 + c2;
    c3.show_data();
    c4=c1 - c2;
    c4.show_data();
    return 0;
}



