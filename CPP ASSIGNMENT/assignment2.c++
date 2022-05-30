#include<iostream>
using namespace std;

class Complex
{
    public:
    int r,i;
    Complex()
    {
        cout<<"A Default constructor is called\n";
        r=0;i=1;
    }
    Complex(int b)
    {
        cout<<"one argument constructor is called\n";
        i=b; r=0;
    }
    Complex(int a, int b)
    {
        cout<<"two argument constructor is called\n";
        i=b; r=a;
    }
};

int main(int argc, char const *argv[])
{
    int option=0,m=8,n=9;
    cout<<"constructor you want to call\n";
    cout<<"1. default Constructor\n";
    cout<<"2. one argument Constructor\n";
    cout<<"3. two argument Constructor\n";
    cin>>option;

    switch(option)
    {
        case 1:
        {
            Complex c1;
            cout<<c1.r<<" + i"<<c1.i<<"\n";
            break;
        }
        case 2:
        {
            Complex c2(5);
            cout<<c2.r<<" + i"<<c2.i<<"\n";
            break;
        }
        case 3:
        {
            Complex c3(m,n);
            cout<<c3.r<<" + i"<<c3.i<<"\n";
            break;
        }
    }
    return 0;
}
