#include <iostream>
#include <conio.h>
#include <cstdio>
#include <stdio.h>
using namespace std;

class rac
{
    private : 
    int a,b;
    public :
    void set_data(int x, int y)
    {a=x;b=y;}
    void show_data()
    {
        cout<<"\na="<<a<<"b="<<b;
    }
    rac add(rac c){
    rac temp;
    temp.a= a+c.a;
    temp.b= b+c.b;
    return (temp);
    }
};

void main()
{
    rac r1,r2,r3;
    r1.set_data(10,9);
    r2.set_data(5,4);
    r3=r1.add(r2);
    r3.show_data();
}


